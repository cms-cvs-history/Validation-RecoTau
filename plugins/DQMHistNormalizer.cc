/** \class DQMHistNormalizer
 *  
 *  Class to produce efficiency histograms by dividing nominator by denominator histograms
 *
 *  $Date: 2012/02/03 10:06:44 $
 *  $Revision: 1.2 $
 *  \author Christian Veelken, UC Davis
 */

// framework & common header files
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"


//DQM services
#include "DQMServices/Core/interface/DQMStore.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DQMServices/Core/interface/MonitorElement.h"


#include <string>
#include <vector>
#include <map>

using namespace std;


class DQMHistNormalizer : public edm::EDAnalyzer
{

 public:
  explicit DQMHistNormalizer(const edm::ParameterSet&);
  virtual ~DQMHistNormalizer();
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob(){}
  virtual void endRun(const edm::Run& r, const edm::EventSetup& c);

private:
  vector<string> plotNamesToNormalize_; //root name used by all the plots that must be normalized
  string reference_;
};

DQMHistNormalizer::DQMHistNormalizer(const edm::ParameterSet& cfg):
  plotNamesToNormalize_(cfg.getParameter< std::vector<string> >("plotNamesToNormalize")),
  reference_(cfg.getParameter< string >("reference"))
{
  //std::cout << "<DQMHistNormalizer::DQMHistNormalizer>:" << std::endl;
}

DQMHistNormalizer::~DQMHistNormalizer() 
{
//--- nothing to be done yet
}

void DQMHistNormalizer::analyze(const edm::Event&, const edm::EventSetup&)
{
//--- nothing to be done yet
}

void DQMHistNormalizer::endRun(const edm::Run& r, const edm::EventSetup& c)
{
  //std::cout << "<DQMHistNormalizer::endJob>:" << std::endl;

//--- check that DQMStore service is available
  if ( !edm::Service<DQMStore>().isAvailable() ) {
    edm::LogError ("endJob") << " Failed to access dqmStore --> histograms will NOT be plotted !!";
    return;
  }

  DQMStore& dqmStore = (*edm::Service<DQMStore>());

  string refRegex = "*RecoTauV/*/" + reference_;
  vector<MonitorElement *> refelements = dqmStore.getMatchingContents(refRegex);
  map<string, vector<MonitorElement *>::const_iterator > refsMap;
  for(vector<MonitorElement *>::const_iterator refElem = refelements.begin(); refElem != refelements.end(); ++refElem){
    string meName = (*refElem)->getFullname();
    string dir = (*refElem)->getFullname().substr(0, meName.rfind("/"));
    if(refsMap.find(dir) != refsMap.end()){
      edm::LogInfo("DQMHistNormalizer")<<"DQMHistNormalizer::endRun: Warning! found multiple normalizing references for dir: "<<dir<<"!";
      edm::LogInfo("DQMHistNormalizer")<<"     " << (*refsMap[dir])->getFullname();
      edm::LogInfo("DQMHistNormalizer")<<"     " << (*refElem)->getFullname();
    }
    else{
      refsMap[dir] = refElem;
    }
  }

  for ( std::vector<string>::const_iterator toNorm = plotNamesToNormalize_.begin(); toNorm != plotNamesToNormalize_.end(); ++toNorm ) {
    //std::cout << "plot->numerator_ = " << plot->numerator_ << std::endl;
    string regexp = "*RecoTauV/*/" + *toNorm;
    vector<MonitorElement *> matchingElemts = (dqmStore.getMatchingContents(regexp));
    
    for(vector<MonitorElement *>::const_iterator matchingElement = matchingElemts.begin(); matchingElement != matchingElemts.end(); ++matchingElement){
      string meName = (*matchingElement)->getFullname();
      string dir = meName.substr(0, meName.rfind("/"));

      if(refsMap.find(dir) == refsMap.end()){
        edm::LogInfo("DQMHistNormalizer")<<"DQMHistNormalizer::endRun: Error! normalizing references for "<<meName<<" not found! Skipping...";
        continue;
      }
      
      float norm = (*refsMap[dir])->getTH1()->GetEntries();
      TH1* hist = (*matchingElement)->getTH1();
      if ( norm != 0. ) {
        if( !hist->GetSumw2N() ) hist->Sumw2();
        hist->Scale(1/norm);//use option "width" to divide the bin contents and errors by the bin width?
      }else{
        edm::LogInfo("DQMHistNormalizer")<<"DQMHistNormalizer::endRun: Error! Normalization failed in "<<hist->GetTitle()<<"!";
      }
      
    }//    for(vector<MonitorElement *>::const_iterator matchingElement = matchingElemts.begin(); matchingElement = matchingElemts.end(); ++matchingElement)
  }//  for ( std::vector<string>::const_iterator toNorm = plotNamesToNormalize_.begin(); toNorm != plotNamesToNormalize_.end(); ++toNorm ) {
}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(DQMHistNormalizer);



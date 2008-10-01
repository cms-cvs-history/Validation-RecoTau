{
char *hosttype = gSystem->Getenv( "HOSTTYPE" );
char *rootsys  = gSystem->Getenv( "ROOTSYS" );


// gROOT->Reset();                // Reseting ROOT
gROOT->LoadMacro("drawEfficiency.C++");
gROOT->LoadMacro("drawHistograms.C++");
gROOT->LoadMacro("drawEfficiencyOther.C++");
gROOT->LoadMacro("drawEfficiencies.C++");
 
gROOT->LoadMacro("tdrstyle.C");
setTDRStyle();
printf( "libraries loaded\n" );

}


!#/bin/bash

echo "Finding tau validation datasets for $CMSSW_VERSION"

echo "Finding QCD dataset"
QCD_DATASET=`dbs search --noheader --query="find dataset where primds=RelValQCD_FlatPt_15_3000 and release = $CMSSW_VERSION and tier=GEN-SIM-RECO"`
echo "...using $QCD_DATASET"

echo "Finding QCD files"
rm qcd_files
dbs search --noheader --query="find file where dataset=$QCD_DATASET" > qcd_files
echo "found `wc -l qcd_files` files"

echo "Finding ZTT dataset"
ZTT_DATASET=`dbs search --noheader --query="find dataset where primds=RelValZTT and release = $CMSSW_VERSION and tier=GEN-SIM-RECO"`
echo "...using $ZTT_DATASET"

echo "Finding ZTT files"
rm ztt_files
dbs search --noheader --query="find file where dataset=$ZTT_DATASET" > ztt_files
echo "found `wc -l ztt_files` files"

#Python loop to show data structure
import ROOT as r
#argument for input file
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-f", help="file with input tree",dest='inputfile', required=True)
args = parser.parse_args()

#opening file and getting tree
inputfile = r.TFile.Open(args.inputfile,"read")
hittree = inputfile.Get("shippositions")

nentries = hittree.GetEntries()


#loop on events
for ievent, event in enumerate(hittree):

 nhits = hittree.nhits 

 if (ievent < 10):
  print("")
  print("Dump start for event number {} with {} hits".format(ievent, nhits))
 
 #loop on hits
 for (detID, x,y,z,subdetector,trackID) in zip(hittree.detID, hittree.posx, hittree.posy, hittree.posz,  hittree.subdetector, hittree.trackID):
  if (ievent < 10):
   print("DetectorID: "," from subdetector ",subdetector)
   print("Test position: ({0:.2f},{0:.2f},{0:.2f}) cm".format(x,y,z))

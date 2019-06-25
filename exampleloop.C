/*C++ loop to show ntuple structure
Usage: root -l exampleloop.C\(\"filepath\"\) 
Backslashes are required to pass argument inline.
*/
void exampleloop(TString filename){

 //"/eos/experiment/ship/data/charmxsec/DATA_8000_charmTest/ntuples/RUN_8000_2800/ntuples_SPILLDATA_8000_0522407415_20180730_193803.root"

 TFile *inputfile = TFile::Open(filename.Data(),"read");

 TTreeReader reader("shippositions",inputfile);

 TTreeReaderValue <int> nhits(reader, "nhits");
 //information from each hit
 TTreeReaderArray<float> posx(reader,"posx");
 TTreeReaderArray<float> posy(reader,"posy");
 TTreeReaderArray<float> posz(reader,"posz");
 
 TTreeReaderArray<int> detID(reader,"detID");
 TTreeReaderArray<int> subdetector(reader, "subdetector");

 int ievent = 0;
 //loop on events
 while(reader.Next()){
  //loop on hits
  if(ievent<10){
   cout<<endl;
   cout<<"Dump start for event number"<<ievent<<" with "<<*nhits<<" hits"<<endl; //Note: TTreeReaderValues behave as iterators
  }

  for (int ihit = 0; ihit < *nhits; ihit++){ 
   if (ievent < 10){
    cout<<"Detector ID "<<detID[ihit]<<" from subdetector "<<subdetector[ihit]<<endl;
    cout<<Form("Test position: (%.2f, %.2f, %.2f) cm",posx[ihit],posy[ihit],posz[ihit])<<endl;
   }
  }//end loop on hits
 ievent++;
 }//end loop on events
}

#include "Riostream.h"
void data_reader() {
	// Read data from ASCII file and create histogram/ntuple combo

	ifstream in;
	in.open("testData.txt");

	Float_t cost,time,type;
	TFile *file = new TFile("data_reader.root", "RECREATE");
	TH1F *histo = new TH1F("histo", "cost distribution", 100, 0, 2);
	TTree *Tree = new TTree("ntuple", "data from file");
	
	Tree->ReadFile(Form("testData.txt"), "cost:time:type");
	Tree->Draw("cost");
	Tree->Write();

}

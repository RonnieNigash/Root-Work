#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void histogram_draw() {
	// Create histogram
	TH1F *histoX = new TH1F("histoY", "tree", 10000, -2,2);
	TH1F *histoY = new TH1F("histoY", "tree", 10000, 0, 4);

	// Open file with tree
	TFile *file = new TFile("histo.root","READ");

	// Get us out of here if our file is invalid!
	if (file->IsOpen()) {
		cout << "File opened!";
	} else {
		return;
	}

	TTreeReader treeReader("tree", file);

	// Names of branches
	TTreeReaderValue<Float_t> valX(treeReader, "X");
	TTreeReaderValue<Float_t> valY(treeReader, "Y");

	while(treeReader.Next()) {
		histo->Fill(*valX);
	}

	histo->Draw();
}

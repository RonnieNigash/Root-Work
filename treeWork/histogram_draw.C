#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void histogram_draw() {
	// Create histogram
	TH1F *histo = new TH1F("histo", "myTree", 10000, -2,2);

	// Open file with tree
//	TFile *file = TFile::Open("/users/ronnie/root/bin/histo.root");
	TFile file("/users/ronnie/root/bin/histo.root");

	// Get us out of here if our file is invalid!
//	if (!file || file->IsZombie()) {
//		cout << "File not found.";
//		return;
//	}

	TTreeReader treeReader("myTree", &file);
		
	// Names of branches
	TTreeReaderValue<Float_t> valX(treeReader, "X");
//	TTreeReaderValue<Float_t> valY(treeReader, "Y");
	// @TODO: We are never getting inside of this loop. Fix that!
	cout << "We made it on the outside of the loop";
	while(treeReader.Next()) {
		cout << "We made it to the inside of the loop";
		histo->Fill(*valX);
	}

	histo->Draw();
}

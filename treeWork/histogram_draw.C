void histogram_draw() {
	// Create histogram
	TH1F *histo = new TH1F("histo", "myTree", 10000, -2,2);

	// Open file with tree
	TFile *file = TFile::Open("histo.root");
	
	// Get us out of here if our file is invalid!
	if (!file || file->IsZombie()) {
		cout << "File not found.";
		return;
	}

	TTreeReader treeReader("myTree", file);
	
	// Names of branches
	TTreeReaderValue<Float_t> valX(treeReader, "X");
//	TTreeReaderValue<Float_t> valY(treeReader, "Y");
	// @TODO: Fix this, doesn't appear to be filling out a tree -- cannot get values
	while(treeReader.Next()) {
		histo->Fill(*valX);
	}

	histo->Draw();
}

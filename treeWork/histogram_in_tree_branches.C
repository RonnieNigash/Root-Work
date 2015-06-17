void histogram_in_tree_branches() {
	// Creates a Tree with two branches -- each branch generates 10,000 leaves
	// Values at leaves are Gaussian distribution and Poisson
	
	// Found PoissonD and Rannor in API documentation, maybe use these
	// https://root.cern.ch/root/html600/TRandom.html#TRandom:Rannor

	TFile *file = new TFile("histo.root", "RECREATE");
	TTree *tree = new TTree("tree", "My Tree");

	Float_t X, Y;

	tree->Branch("X", &X, "X");
	tree->Branch("Y", &Y, "Y");

	for (int i = 0; i < 10; i++) {
		X = gRandom->Gaus(0, 1);
		Y = gRandom->Poisson(0);
		tree->Fill();
	}	
	tree->Write();
	
	// Make the histograms
//	tree->Draw("X");
	tree->Draw("Y");	
}

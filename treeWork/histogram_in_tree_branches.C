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

	// 10,000 entries
	for (int i = 0; i < 10000; i++) {
		X = gRandom->Gaus(0, 1); // Fill out the X branch with Gaussian Distribution
		Y = (float)gRandom->Poisson(1.1); // Fill out the Y branch with a Poisson Distribution
		tree->Fill(); // Puts values into bins in branches
	}	
	tree->Write(); // Write to histo.root
	
	// Make the histograms
  	tree->Draw("Y");
//	tree->Draw("Y");	
}

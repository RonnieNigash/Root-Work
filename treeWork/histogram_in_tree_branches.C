void histogram_in_tree_branches() {
	// Creates a Tree with two branches -- each branch generates 10,000 leaves
	// Values at leaves are Gaussian distribution and Poisson
	
	// Found PoissonD and Rannor in API documentation, maybe use these
	// https://root.cern.ch/root/html600/TRandom.html#TRandom:Rannor

	TFile *file = new TFile("histo.root", "RECREATE");
	TTree *tree = new TTree("tree", "My Tree");

	// @TODO: Fix this syntax for Branching -- should have two more params
	// 		  Pointer to address of some object -- create a Point object maybe?	
	
	Float_t X, Y;
	Double_t random;
	TRandom *rand = new TRandom(0);

	tree->Branch("X", &X, "X");
	tree->Branch("Y", &Y, "Y");

	for (int i = 0; i < 100; i++) {
		X = gRandom->Gaus(0, 1);
		Y = (float)rand->Poisson(1.1);
		//gRandom->Rannor(X, Y);
		//random = gRandom->Rndm();
		tree->Fill();
	}	
	// @TODO: Add the ability to Draw() the tree as well
	// @TODO: Build out both branches and generate values
	tree->Write();
	
	// Make the histograms
//	tree->Draw("X");
	tree->Draw("Y");	
}

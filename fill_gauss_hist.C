// Fill Guassian Histogram 1D
//
void fillGauss() {

	TCanvas *canvas = new TCanvas("canvas", "The Gaussian Distribution", 200, 10, 800, 800);
	canvas->SetFillColor(20);

	auto funcPad = new TPad("funcPad", "Gaussian function", 0.05, 0.50, 0.95, 0.95, 21);
	auto histPad = new TPad("histPad", "Gaussian histogram", 0.05, 0.05, 0.95, 0.45, 21);

	funcPad->Draw();
	histPad->Draw();
	funcPad->cd();

	gBenchmark->Start("fillGauss");

	auto formula = new TFormula("formula", "x*gaus(0)", 0, 10);
	formula->SetParameters(10, 4, 1, 20);

	funcPad->SetGrid(x);
	funcPad->SetGrid(y);
	funcPad->GetFrame()->SetFillColor(36);
	funcPad->GetFrame()->SetBorderMode(-1);
	funcPad->GetFrame()->SetBorderSize(5);

	formula->SetLineColor(7);
	formula->SetLineWidth(5);

	formula->Draw();

	auto functionLabel = new TPaveLabel(5, 39, 9.8, 46, "The Guassian Function");
	functionLabel->SetFillColor(40);
	functionLabel->Draw();

	canvas->Update();
	
	// Create a one-dimemsional histogram with one float per bin
	// Fill with gaussian distribution
	
	histPad->cd();
	histPad->GetFrame()->SetFillColor(36);
	histPad->GetFrame()->SetBorderMode(-1);
	histPad->GetFrame()->SetBorderSize(5);

	auto histDraw = new TH1F("histDraw", "Draw numbers", 200, 0, 10);
	histDraw->SetFillColor(45);
	histDraw->FillRandom("formula", 100000);
	histDraw->Draw();
	canvas->Update();

	// Open ROOT file and save
	
	TFile newFile("fill_gauss_hist.root", "RECREATE");
	formula->Write();
	histDraw->Write();
	gBenchmark->Show("fillGuass");

}

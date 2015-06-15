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

	auto formula = new TFormula("formula", "abs(sin(x)/x)");
	auto newFunction = new TF1("newFunction", "x*gauss(0) + formula", 0, 10);
	formula->SetParameters(10, 4, 1, 20);

	funcPad->SetGridx();
	funcPad->SetGridy();
	funcPad->GetFrame()->SetFillColor(36);
	funcPad->GetFrame()->SetBorderMode(-1);
	funcPad->GetFrame()->SetBorderSize(5);

	newFunction->SetLineColor(7);
	newFunction->SetLineWidth(5);

	newFunction->Draw();

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
	histDraw->FillRandom("newFunction", 100000);
	histDraw->Draw();
	canvas->Update();

	// Open ROOT file and save
	
	TFile newFile("fill_gauss_hist.root", "RECREATE");
	formula->Write();
	newFunction->Write();
	histDraw->Write();
	gBenchmark->Show("fillGuass");

}

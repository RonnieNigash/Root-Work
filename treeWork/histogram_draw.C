#include "TFile.h"
#include "TH1F.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

void histogram_draw() {
	// Create canvas
	TCanvas *canvas = new TCanvas("canvas", "Histogram Distributions", 200, 10, 800, 1200);
	canvas->SetFillColor(15);

	// Create histograms
	TH1F *histoX = new TH1F("histoY", "tree", 10000, -2,2);
	TH1F *histoY = new TH1F("histoY", "tree", 10000, 0, 4);
	TH2F *histoXY = new TH2F("histoXY", "tree", 100000, -2, 4, 10, 0, 5);

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
		//histo->Fill(*valX);
		histoX->Fill(*valX);
		histoY->Fill(*valY);
		histoXY->Fill(*valX, *valY);
	}
	// Draw our histograms to the canvas and update after each draw
	histoX->Draw();
	canvas->Update();

	histoY->Draw();
	canvas->Update();

	histoXY->Draw();
	canvas->Update();
}

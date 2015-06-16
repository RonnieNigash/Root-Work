void randomNumbers()
{
	getRandom = new TRandom3();
	TH1F * histo = new TH1F("histo", "histo", 20, 0.0, 100.0);
	for (int i = 0; i < 100000; ++i) {
		histo->Fill(getRandom->Gaus(50.0, 5.0));
	}
	TCanvas * canvas = new TCanvas("canvas", "randomNumbers", 5, 5, 800, 800);
	histo->Draw();

}

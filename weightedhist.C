#include<cmath>
void weightedhist()
{
	// TH1F takes 5 parameters name,graph title,bins,starting point,ending point
	double bins = 30;
	double lower_limit = 511;
	double upper_limit = 540;
	double binSize = ((upper_limit-lower_limit)/bins);
	TH1F *hist = new TH1F("hist", "Weighted Histogram of posZ,EnergyDeposit",bins,lower_limit,upper_limit);
	TH1F *hist2 = new TH1F("hist2", "Weighted Histogram of posZ,EnergyDeposit", bins,lower_limit,upper_limit);
	TLegend *legend = new TLegend(0.1,0.7,0.48,0.9);
	
	//Opening the text file in reading mode
	fstream file;
	fstream file2;
	file.open("electron_data.txt",ios::in);
	file2.open("pion_data.txt",ios::in);
	double pos,ene;
	double posP,eneP;
	while(1)
	{
		file >> ene>>pos;
		hist->Fill(pos,(ene));
		if (file.eof())
		{
			break;
		}
	
	
	}
	while(1)
	{
		file2 >> eneP>>posP;
		hist2->Fill(posP,(eneP));
		if (file2.eof())
		{
			break;
		}
	
	
	}
	legend->AddEntry(hist, "electron", "l");
	legend->AddEntry(hist2, "pion", "l");
	//Setting the title of x and y axis
	hist->GetXaxis()->SetTitle("Drift region (Z mm)");
	hist->GetYaxis()->SetTitle("Energy Deposit (dE/dx KeV)");
	hist->Draw("hist");
	legend->Draw();
	hist2->SetLineColor(kRed);
	hist2->Draw("hist same");
	
	

}

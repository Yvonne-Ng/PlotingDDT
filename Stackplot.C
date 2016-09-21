#include "TH1F.h"
#include "THStack.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include <iostream>

using namespace std;

void Stackplot(void){
  float nBins_PT=5000;
  float xMax_PT= 5000e3;
  float xMin_PT=0;

  float nBins_Mass=1800;
  float xMax_Mass= 1800e3;
  float xMin_Mass=0;



  TChain *Bkgnd= new TChain("zpj");
  Bkgnd->Add("mc15_13TeV.361022.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2W.merge.DAOD_JETM8.e3668_s2576_s2132_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361023.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ3W.merge.DAOD_JETM8.e3668_s2576_s2132_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361024.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ4W.merge.DAOD_JETM8.e3668_s2576_s2132_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361025.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ5W.merge.DAOD_JETM8.e3668_s2576_s2132_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361026.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ6W.merge.DAOD_JETM8.e3569_s2608_s2183_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361027.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ7W.merge.DAOD_JETM8.e3668_s2608_s2183_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361028.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ8W.merge.DAOD_JETM8.e3569_s2576_s2132_r7773_r7676_p2666.ntuple.root");
  Bkgnd->Add("mc15_13TeV.361029.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ9W.merge.DAOD_JETM8.e3569_s2576_s2132_r7773_r7676_p2666.ntuple.root");

cout<<"Check1"<<endl;
  TChain *s = new TChain("zpj");
  s->Add("mc15_13TeV.304707.Sherpa_CT10_Zqq_Pt280_500.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");
  s->Add("mc15_13TeV.304708.Sherpa_CT10_Zqq_Pt500_1000.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");
  s->Add("mc15_13TeV.304709.Sherpa_CT10_Zqq_Pt1000.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");
  cout<<"Check2"<<endl;

  TChain *w = new TChain("zpj");
  w->Add("mc15_13TeV.304307.Sherpa_CT10_Wqq_Pt280_500.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");
  w->Add("mc15_13TeV.304308.Sherpa_CT10_Wqq_Pt500_1000.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");
  w->Add("mc15_13TeV.304309.Sherpa_CT10_Wqq_Pt1000.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");

  cout<<"Check3"<<endl;

  TH1F *Bg_Mass = new TH1F("Bg_Mass","Bg_Mass",nBins_Mass,xMin_Mass,xMax_Mass);
  TH1F *Wqq_Mass = new TH1F("Wqq_Mass","Wqq_Mass",nBins_Mass,xMin_Mass, xMax_Mass);
  TH1F *Sig_Mass = new TH1F("Sig_Mass","Sig_Mass",nBins_Mass,xMin_Mass, xMax_Mass);

  TH1F *Sig_PT = new TH1F("Sig_PT","Sig_PT",nBins_Mass,xMin_PT, xMax_PT);
  TH1F *Wqq_PT = new TH1F("Wqq_PT","Wqq_PT",nBins_Mass,xMin_PT, xMax_PT);
  TH1F *Bg_PT= new TH1F("Bg_PT","Bg_PT",nBins_Mass,xMin_PT, xMax_PT);
  cout<<"Check4"<<endl;

//reweighting
  Bkgnd->Draw("fjetTau_m[0]>>Bg_Mass","lumi_weight*event_weight", "goff");
  Bkgnd->Draw("fjetTau_pt[0]>>Bg_PT","lumi_weight*event_weight","goff");
  s->Draw("fjetTau_m[0]>>Sig_Mass","lumi_weight*event_weight","goff");
  s->Draw("fjetTau_pt[0]>>Sig_PT","lumi_weight*event_weight","goff");
  w->Draw("fjetTau_m[0]>>Wqq_Mass","lumi_weight*event_weight","goff");
  w->Draw("fjetTau_pt[0]>>Wqq_PT","lumi_weight*event_weight","goff");


//Reweighting and set D2 limit
/*
Bkgnd->Draw("fjetTau_m[0]>>Bg_Mass","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)", "goff");
Bkgnd->Draw("fjetTau_pt[0]>>Bg_PT","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)","goff");
s->Draw("fjetTau_m[0]>>Sig_Mass","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)","goff");
s->Draw("fjetTau_pt[0]>>Sig_PT","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)","goff");
w->Draw("fjetTau_m[0]>>Wqq_Mass","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)","goff");
w->Draw("fjetTau_pt[0]>>Wqq_PT","lumi_weight*event_weight*(jet_pt[0]>350e3&&fjetTau_D2[0]<1&&fjetTau_D2[0]>0)","goff");
*/

/*
Bkgnd->Draw("fjetTau_m[0]>>Bg_Mass","", "goff");
Bkgnd->Draw("fjetTau_pt[0]>>Bg_PT","","goff");
s->Draw("fjetTau_m[0]>>Sig_Mass","","goff");
s->Draw("fjetTau_pt[0]>>Sig_PT","","goff");
w->Draw("fjetTau_m[0]>>Wqq_Mass","","goff");
w->Draw("fjetTau_pt[0]>>Wqq_PT","","goff");
*/

  cout<<"Check5"<<endl;

  TCanvas *PT_Canvas = new TCanvas ("pt","pt",700,500);
  PT_Canvas->SetLogy();

  cout<<"Check6"<<endl;

  Bg_PT->SetLineColor(kBlue);
  Wqq_PT->SetLineColor(kGreen);
  Sig_PT->SetLineColor(kRed);

//  Bg_PT->SetFillColor(kBlue);
//  Wqq_PT->SetFillColor(kGreen);
//  Sig_PT->SetFillColor(kRed);

  Bg_PT->Draw();
  Wqq_PT->Draw("same");
  Sig_PT->Draw("same");

  cout<<"Check7"<<endl;

  Bg_PT->SetFillColor(kBlue);
  Wqq_PT->SetFillColor(kGreen);
  Sig_PT->SetFillColor(kRed);
  THStack *Stack_PT = new THStack("stack_pt","");
//Sig on the top

  Stack_PT->Add(Bg_PT);
    Stack_PT->Add(Wqq_PT);
    Stack_PT->Add(Sig_PT);

//Sig in the bottom
/*
      Stack_PT->Add(Sig_PT);
      Stack_PT->Add(Wqq_PT);
    Stack_PT->Add(Bg_PT);

*/

  cout<<"Check8"<<endl;

  TCanvas *PT_Stacked= new TCanvas("pt_stack","pt_stack",700, 500);
//  PT_Stacked->SetLogy();
  Stack_PT->Draw();
  cout<<"Check9"<<endl;

  //Bg_PT->Clear();
  //Wqq_PT->Clear();
  //Sig_PT->Clear();

}

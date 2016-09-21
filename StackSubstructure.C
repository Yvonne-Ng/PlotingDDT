#include "TH1F.h"
#include "THStack.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include <iostream>
#include "TLatex.h"
#include "TProfile.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TPave.h"
#include "TBox.h"

using namespace std;

void StackSubstructure(void){
  float nBins_PT=5000;
  float xMax_PT= 5000e3;
  float xMin_PT=0;

  float nBins_Mass=1800;
  float xMax_Mass= 1800e3;
  float xMin_Mass=0;

  float nBins_Tau21=45;
  float xMax_Tau21= 1.2;
  float xMin_Tau21=0;

  float nBins_Rho= 90;
  float xMax_Rho=10;
  float xMin_Rho=-35;

  gStyle->SetOptFit(1111);
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
//  w->Add("mc15_13TeV.304309.Sherpa_CT10_Wqq_Pt1000.merge.DAOD_JETM8.e4692_s2726_r7772_r7676_p2666.ntuple.root");

  cout<<"Check3"<<endl;

/*
TProfile *Tau21VRho_bg_PT300t400  = new TProfile("Tau21VRhobg_PT300t400","Tau2/Tau1 vs Rho bg_PT300t400",100,-4,4,0,20);
TProfile *Tau21VRho_bg_PT500t600  = new TProfile("Tau21VRhobg_PT500t600","Tau2/Tau1 vs Rho bg_PT500t600",100,-4,4,0,20);
TProfile *Tau21VRho_bg_PT1000t1100  = new TProfile("Tau21VRhobg_PT300t400","Tau2/Tau1 vs Rho bg_PT1000t1100",100,-4,4,0,20);
*/
/*
TH2F *Tau21VRho_bg_pt1  = new TProfile("Tau21VRho_bg_pt1","Tau2/Tau1 vs Rho ",100,-4,4,0,20);
TH2F *Tau21VRho_bg_pt2  = new TProfile("Tau21VRho_bg_pt2","Tau2/Tau1 vs Rho ",100,-4,4,0,20);
TH2F *Tau21VRho_bg_pt3  = new TProfile("Tau21VRho_bg_pt3","Tau2/Tau1 vs Rho ",100,-4,4,0,20);

TH2F *Tau21VRho_sig_pt2  = new TProfile("Tau21VRhoSig","Tau2/Tau1 vs Rho ",100,-4,4,0,20);
TH2F *Tau21VRho_wq  = new TProfile("Tau21VRhoWq","Tau2/Tau1 vs Rho ",100,-4,4,0,20);
*/

TH2F *Tau21VRho_bg_PT300t400=new TH2F("Tau21VRho_bg_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_bg_PT500t600=new TH2F("Tau21VRho_bg_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_bg_PT1000t1100=new TH2F("Tau21VRho_bg_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);

TH2F *Tau21VRho_sig_PT300t400=new TH2F("Tau21VRho_sig_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_sig_PT500t600=new TH2F("Tau21VRho_sig_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_sig_PT1000t1100=new TH2F("Tau21VRho_sig_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);

TH2F *Tau21VRho_wq_PT300t400=new TH2F("Tau21VRho_wq_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_wq_PT500t600=new TH2F("Tau21VRho_wq_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRho_wq_PT1000t1100=new TH2F("Tau21VRho_wq_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);


TH2F *Tau21VRhoP_bg_PT300t400=new TH2F("Tau21VRhoP_bg_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_bg_PT500t600=new TH2F("Tau21VRhoP_bg_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_bg_PT1000t1100=new TH2F("Tau21VRhoP_bg_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);

TH2F *Tau21VRhoP_sig_PT300t400=new TH2F("Tau21VRhoP_sig_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_sig_PT500t600=new TH2F("Tau21VRhoP_sig_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_sig_PT1000t1100=new TH2F("Tau21VRhoP_sig_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);

TH2F *Tau21VRhoP_wq_PT300t400=new TH2F("Tau21VRhoP_wq_PT300t400","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_wq_PT500t600=new TH2F("Tau21VRhoP_wq_PT500t600","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH2F *Tau21VRhoP_wq_PT1000t1100=new TH2F("Tau21VRhoP_wq_PT1000t1100","tauVRho_bg1",nBins_Rho,xMin_Rho,xMax_Rho,nBins_Tau21,xMin_Tau21,xMax_Tau21);


Tau21VRho_bg_PT300t400->Sumw2();
Tau21VRho_bg_PT500t600->Sumw2();
Tau21VRho_bg_PT1000t1100->Sumw2();

Tau21VRho_sig_PT300t400->Sumw2();
Tau21VRho_sig_PT500t600->Sumw2();
Tau21VRho_sig_PT1000t1100->Sumw2();

Tau21VRho_wq_PT300t400->Sumw2();
Tau21VRho_wq_PT500t600->Sumw2();
Tau21VRho_wq_PT1000t1100->Sumw2();

Tau21VRhoP_bg_PT300t400->Sumw2();
Tau21VRhoP_bg_PT500t600->Sumw2();
Tau21VRhoP_bg_PT1000t1100->Sumw2();

Tau21VRhoP_sig_PT300t400->Sumw2();
Tau21VRhoP_sig_PT500t600->Sumw2();
Tau21VRhoP_sig_PT1000t1100->Sumw2();

Tau21VRhoP_wq_PT300t400->Sumw2();
Tau21VRhoP_wq_PT500t600->Sumw2();
Tau21VRhoP_wq_PT1000t1100->Sumw2();
//Declaring histograms
  TH1F *Bg_Mass = new TH1F("Bg_Mass","Bg_Mass",nBins_Mass,xMin_Mass,xMax_Mass);
  TH1F *Wqq_Mass = new TH1F("Wqq_Mass","Wqq_Mass",nBins_Mass,xMin_Mass, xMax_Mass);
  TH1F *Sig_Mass = new TH1F("Sig_Mass","Sig_Mass",nBins_Mass,xMin_Mass, xMax_Mass);

  TH1F *Sig_PT = new TH1F("Sig_PT","Sig_PT",nBins_Mass,xMin_PT, xMax_PT);
  TH1F *Wqq_PT = new TH1F("Wqq_PT","Wqq_PT",nBins_Mass,xMin_PT, xMax_PT);
  TH1F *Bg_PT= new TH1F("Bg_PT","Bg_PT",nBins_Mass,xMin_PT, xMax_PT);
  cout<<"Check4"<<endl;
//All PT Tau21
  TH1F *Bg_Tau21 = new TH1F("Bg_Tau21","Bg_Tau21",nBins_Tau21,xMin_Tau21,xMax_Tau21);
  TH1F *Wqq_Tau21 = new TH1F("Wqq_Tau21","Wqq_Tau21",nBins_Tau21,xMin_Tau21, xMax_Tau21);
  TH1F *Sig_Tau21 = new TH1F("Sig_Tau21","Sig_Tau21",nBins_Tau21,xMin_Tau21, xMax_Tau21);

  TH1F *Bg_Tau21P = new TH1F("Bg_Tau21P","Bg_Tau21P",nBins_Tau21,xMin_Tau21,xMax_Tau21);
  TH1F *Wqq_Tau21P = new TH1F("Wqq_Tau21P","Wqq_Tau21P",nBins_Tau21,xMin_Tau21, xMax_Tau21);
  TH1F *Sig_Tau21P = new TH1F("Sig_Tau21P","Sig_Tau21P",nBins_Tau21,xMin_Tau21, xMax_Tau21);


//PT Slices Tau21
TH1F *Bg_Tau21_PT300to400 = new TH1F("Bg_Tau21_PT300to400","Bg_Tau21_PT300to400",nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH1F *Bg_Tau21_PT500to600 = new TH1F("Bg_Tau21_PT500to600","Bg_Tau21_PT500to600",nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH1F *Bg_Tau21_PT1000to1100 = new TH1F("Bg_Tau21_PT1000to1100","Bg_Tau21_PT1000to1100",nBins_Tau21,xMin_Tau21,xMax_Tau21);

TH1F *Wqq_Tau21_PT300to400 = new TH1F("Wqq_Tau21_PT300to400","Wqq_Tau21_PT300to400",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Wqq_Tau21_PT500to600 = new TH1F("Wqq_Tau21_PT500to600","Wqq_Tau21_PT500to600",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Wqq_Tau21_PT1000to1100 = new TH1F("Wqq_Tau21_PT1000to1100","Wqq_Tau21_PT1000to1100",nBins_Tau21,xMin_Tau21, xMax_Tau21);

TH1F *Sig_Tau21_PT300to400 = new TH1F("Sig_Tau21_PT300to400","Sig_Tau21_PT300to400",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Sig_Tau21_PT500to600 = new TH1F("Sig_Tau21_PT500to600","Sig_Tau21_PT500to600",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Sig_Tau21_PT1000to1100 = new TH1F("Sig_Tau21_PT1000to1100","Sig_Tau21_PT1000to1100",nBins_Tau21,xMin_Tau21, xMax_Tau21);

TH1F *Wqq_Tau21P_PT300to400 = new TH1F("Wqq_Tau21P_PT300to400","Wqq_Tau21P_PT300to400",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Wqq_Tau21P_PT500to600 = new TH1F("Wqq_Tau21P_PT500to600","Wqq_Tau21P_PT500to600",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Wqq_Tau21P_PT1000to1100 = new TH1F("Wqq_Tau21P_PT1000to1100","Wqq_Tau21P_PT1000to1100",nBins_Tau21,xMin_Tau21, xMax_Tau21);

TH1F *Sig_Tau21P_PT300to400 = new TH1F("Sig_Tau21P_PT300to400","Sig_Tau21P_PT300to400",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Sig_Tau21P_PT500to600 = new TH1F("Sig_Tau21P_PT500to600","Sig_Tau21P_PT500to600",nBins_Tau21,xMin_Tau21, xMax_Tau21);
TH1F *Sig_Tau21P_PT1000to1100 = new TH1F("Sig_Tau21P_PT1000to1100","Sig_Tau21P_PT1000to1100",nBins_Tau21,xMin_Tau21, xMax_Tau21);

TH1F *Bg_Tau21P_PT300to400 = new TH1F("Bg_Tau21P_PT300to400","Bg_Tau21P_PT300to400",nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH1F *Bg_Tau21P_PT500to600 = new TH1F("Bg_Tau21P_PT500to600","Bg_Tau21P_PT500to600",nBins_Tau21,xMin_Tau21,xMax_Tau21);
TH1F *Bg_Tau21P_PT1000to1100 = new TH1F("Bg_Tau21P_PT1000to1100","Bg_Tau21P_PT1000to1100",nBins_Tau21,xMin_Tau21,xMax_Tau21);




TH1F *Bg_Rho_PT300to400 = new TH1F("Bg_Rho_PT300to400","Bg_Rho_PT300to400",nBins_Rho,xMin_Rho,xMax_Rho);
TH1F *Bg_Rho_PT500to600 = new TH1F("Bg_Rho_PT500to600","Bg_Rho_PT500to600",nBins_Rho,xMin_Rho,xMax_Rho);
TH1F *Bg_Rho_PT1000to1100 = new TH1F("Bg_Rho_PT1000to1100","Bg_Rho_PT1000to1100",nBins_Rho,xMin_Rho,xMax_Rho);

TH1F *Wqq_Rho_PT300to400 = new TH1F("Wqq_Rho_PT300to400","Wqq_Rho_PT300to400",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Wqq_Rho_PT500to600 = new TH1F("Wqq_Rho_PT500to600","Wqq_Rho_PT500to600",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Wqq_Rho_PT1000to1100 = new TH1F("Wqq_Rho_PT1000to1100","Wqq_Rho_PT1000to1100",nBins_Rho,xMin_Rho, xMax_Rho);


TH1F *Sig_RhoP_PT300to400 = new TH1F("Sig_RhoP_PT300to400","Sig_RhoP_PT300to400",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Sig_RhoP_PT500to600 = new TH1F("Sig_RhoP_PT500to600","Sig_RhoP_PT500to600",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Sig_RhoP_PT1000to1100 = new TH1F("Sig_RhoP_PT1000to1100","Sig_RhoP_PT1000to1100",nBins_Rho,xMin_Rho, xMax_Rho);

TH1F *Bg_RhoP_PT300to400 = new TH1F("Bg_RhoP_PT300to400","Bg_RhoP_PT300to400",nBins_Rho,xMin_Rho,xMax_Rho);
TH1F *Bg_RhoP_PT500to600 = new TH1F("Bg_RhoP_PT500to600","Bg_RhoP_PT500to600",nBins_Rho,xMin_Rho,xMax_Rho);
TH1F *Bg_RhoP_PT1000to1100 = new TH1F("Bg_RhoP_PT1000to1100","Bg_RhoP_PT1000to1100",nBins_Rho,xMin_Rho,xMax_Rho);

TH1F *Wqq_RhoP_PT300to400 = new TH1F("Wqq_RhoP_PT300to400","Wqq_RhoP_PT300to400",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Wqq_RhoP_PT500to600 = new TH1F("Wqq_RhoP_PT500to600","Wqq_RhoP_PT500to600",nBins_Rho,xMin_Rho, xMax_Rho);
TH1F *Wqq_RhoP_PT1000to1100 = new TH1F("Wqq_RhoP_PT1000to1100","Wqq_RhoP_PT1000to1100",nBins_Rho,xMin_Rho, xMax_Rho);



//Reweighting
//Tau21VRho_bg_PT300t400->SetName(“Name1”);
TCanvas*Tau21VsRho = new TCanvas("Tau21VsRho");
//Tau21VsRho->SetLogy();
//Bkgnd->Scan("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)");
//Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>histo(35,-35,0,15,0,1.5)","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)");


Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff");

s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_bg_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_bg_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_bg_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff");

s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_sig_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_sig_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_sig_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_wq_PT300t400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_wq_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Tau21VRhoP_wq_PT1000t1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

//Test
//Bkgnd->Draw("1:1>>Tau21VRho_bg_PT300t400","", "goff");
/*
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT300t400","1*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT500t600","1*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff");
Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT1000t1100","1*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff");

s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT300t400","1*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT500t600","1*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
s->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_sig_PT1000t1100","1*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT300t400","1*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT500t600","1*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
w->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_wq_PT1000t1100","1*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");
//Tau21VRho_bg_PT300t400->Fill(Bkgnd->fjet_tau21[0]:Bkgnd->log(fjet_m[0]^2/ut_fjet10_pt[0]^2));
/*
Tau21VRho_bg_PT300t400->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT300t400”);
Tau21VRho_bg_PT400t500->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT400t500”);
Tau21VRho_bg_PT1000t1100->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT1000t1100”);

Tau21VRho_bg_PT300t400->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT300t400”);
Tau21VRho_bg_PT400t500->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT400t500”);
Tau21VRho_bg_PT1000t1100->(TH2F*)gROOT->FindObject(“Tau21VRho_bg_PT1000t1100”);
*/

Tau21VRho_bg_PT300t400->SetTitle("Tau2/Tau1 vs Rho;Rho;Tau2/Tau1");
//LeadingRhoSlices_Canvas->SetLogy();

TProfile *Tau21VRho_bg_PT300t400_pfx=Tau21VRho_bg_PT300t400->ProfileX("1_pfx");
TProfile *Tau21VRho_bg_PT500t600_pfx=Tau21VRho_bg_PT500t600->ProfileX("2_pfx");
TProfile *Tau21VRho_bg_PT1000t1100_pfx=Tau21VRho_bg_PT1000t1100->ProfileX("3_pfx");

TProfile *Tau21VRho_sig_PT300t400_pfx=Tau21VRho_sig_PT300t400->ProfileX("4_pfx");
TProfile *Tau21VRho_sig_PT500t600_pfx=Tau21VRho_sig_PT500t600->ProfileX("5_pfx");
TProfile *Tau21VRho_sig_PT1000t1100_pfx=Tau21VRho_sig_PT1000t1100->ProfileX("6_pfx");

TProfile *Tau21VRho_wq_PT300t400_pfx=Tau21VRho_wq_PT300t400->ProfileX("7_pfx");
TProfile *Tau21VRho_wq_PT500t600_pfx=Tau21VRho_wq_PT500t600->ProfileX("8_pfx");
TProfile *Tau21VRho_wq_PT1000t1100_pfx=Tau21VRho_wq_PT1000t1100->ProfileX("9_pfx");

Tau21VRho_bg_PT300t400_pfx->SetMarkerSize(5);
Tau21VRho_bg_PT500t600_pfx->SetMarkerSize(5);
Tau21VRho_bg_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRho_sig_PT300t400_pfx->SetMarkerSize(5);
Tau21VRho_sig_PT500t600_pfx->SetMarkerSize(5);
Tau21VRho_sig_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRho_wq_PT300t400_pfx->SetMarkerSize(5);
Tau21VRho_wq_PT500t600_pfx->SetMarkerSize(5);
Tau21VRho_wq_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRho_bg_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRho_bg_PT500t600_pfx->SetLineColor(kRed);
Tau21VRho_bg_PT1000t1100_pfx->SetLineColor(kBlue);

Tau21VRho_sig_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRho_sig_PT500t600_pfx->SetLineColor(kRed);
Tau21VRho_sig_PT1000t1100_pfx->SetLineColor(kBlue);

Tau21VRho_sig_PT300t400_pfx->SetLineStyle(3);
Tau21VRho_sig_PT500t600_pfx->SetLineStyle(3);
Tau21VRho_sig_PT1000t1100_pfx->SetLineStyle(3);

Tau21VRho_sig_PT300t400_pfx->SetLineWidth(4);
Tau21VRho_sig_PT500t600_pfx->SetLineWidth(4);
Tau21VRho_sig_PT1000t1100_pfx->SetLineWidth(4);

Tau21VRho_wq_PT300t400_pfx->SetLineStyle(9);
Tau21VRho_wq_PT500t600_pfx->SetLineStyle(9);
Tau21VRho_wq_PT1000t1100_pfx->SetLineStyle(9);

Tau21VRho_wq_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRho_wq_PT500t600_pfx->SetLineColor(kRed);
Tau21VRho_wq_PT1000t1100_pfx->SetLineColor(kBlue);


Tau21VRho_bg_PT300t400->SetMarkerSize(1.2);
Tau21VRho_bg_PT500t600->SetMarkerSize(1.2);
Tau21VRho_bg_PT1000t1100->SetMarkerSize(1.2);

Tau21VRho_sig_PT300t400->SetMarkerSize(1.2);
Tau21VRho_sig_PT500t600->SetMarkerSize(1.2);
Tau21VRho_sig_PT1000t1100->SetMarkerSize(1.2);

Tau21VRho_wq_PT300t400->SetMarkerSize(1.2);
Tau21VRho_wq_PT500t600->SetMarkerSize(1.2);
Tau21VRho_wq_PT1000t1100->SetMarkerSize(1.2);

Tau21VRho_bg_PT300t400->SetLineColor(kBlack);
Tau21VRho_bg_PT500t600->SetLineColor(kRed);
Tau21VRho_bg_PT1000t1100->SetLineColor(kBlue);

Tau21VRho_sig_PT300t400->SetLineColor(kBlack);
Tau21VRho_sig_PT500t600->SetLineColor(kRed);
Tau21VRho_sig_PT1000t1100->SetLineColor(kBlue);

Tau21VRho_sig_PT300t400->SetLineStyle(3);
Tau21VRho_sig_PT500t600->SetLineStyle(3);
Tau21VRho_sig_PT1000t1100->SetLineStyle(3);

Tau21VRho_sig_PT300t400->SetLineWidth(4);
Tau21VRho_sig_PT500t600->SetLineWidth(4);
Tau21VRho_sig_PT1000t1100->SetLineWidth(4);

Tau21VRho_wq_PT300t400->SetLineStyle(9);
Tau21VRho_wq_PT500t600->SetLineStyle(9);
Tau21VRho_wq_PT1000t1100->SetLineStyle(9);

Tau21VRho_wq_PT300t400->SetLineColor(kBlack);
Tau21VRho_wq_PT500t600->SetLineColor(kRed);
Tau21VRho_wq_PT1000t1100->SetLineColor(kBlue);


/*
Tau21VRho_bg_PT300t400_pfx->Draw();
TCanvas *c1= new TCanvas("c1"):
Tau21VRho_bg_PT500t600_pfx->Draw();
TCanvas *c2= new TCanvas("c2"):
Tau21VRho_bg_PT1000t1100_pfx->Draw();

TCanvas *c3= new TCanvas("c3");
Tau21VRho_sig_PT300t400_pfx->Draw();
TCanvas *c4= new TCanvas("c4");
Tau21VRho_sig_PT500t600_pfx->Draw();
TCanvas *c5= new TCanvas("c5");
Tau21VRho_sig_PT1000t1100_pfx->Draw();

TCanvas *c7= new TCanvas("c7");
Tau21VRho_wq_PT300t400_pfx->Draw();
TCanvas *c8= new TCanvas("c8");
Tau21VRho_wq_PT500t600_pfx->Draw();
TCanvas *c9= new TCanvas("c9");
Tau21VRho_wq_PT1000t1100_pfx->Draw();
*/
TCanvas *c[10];

TProfile *Tau21VRhoP_bg_PT300t400_pfx=Tau21VRhoP_bg_PT300t400->ProfileX("1_pfx");
TProfile *Tau21VRhoP_bg_PT500t600_pfx=Tau21VRhoP_bg_PT500t600->ProfileX("2_pfx");
TProfile *Tau21VRhoP_bg_PT1000t1100_pfx=Tau21VRhoP_bg_PT1000t1100->ProfileX("3_pfx");

TProfile *Tau21VRhoP_sig_PT300t400_pfx=Tau21VRhoP_sig_PT300t400->ProfileX("4_pfx");
TProfile *Tau21VRhoP_sig_PT500t600_pfx=Tau21VRhoP_sig_PT500t600->ProfileX("5_pfx");
TProfile *Tau21VRhoP_sig_PT1000t1100_pfx=Tau21VRhoP_sig_PT1000t1100->ProfileX("6_pfx");

TProfile *Tau21VRhoP_wq_PT300t400_pfx=Tau21VRhoP_wq_PT300t400->ProfileX("7_pfx");
TProfile *Tau21VRhoP_wq_PT500t600_pfx=Tau21VRhoP_wq_PT500t600->ProfileX("8_pfx");
TProfile *Tau21VRhoP_wq_PT1000t1100_pfx=Tau21VRhoP_wq_PT1000t1100->ProfileX("9_pfx");

Tau21VRhoP_bg_PT300t400_pfx->SetMarkerSize(5);
Tau21VRhoP_bg_PT500t600_pfx->SetMarkerSize(5);
Tau21VRhoP_bg_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRhoP_sig_PT300t400_pfx->SetMarkerSize(5);
Tau21VRhoP_sig_PT500t600_pfx->SetMarkerSize(5);
Tau21VRhoP_sig_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRhoP_wq_PT300t400_pfx->SetMarkerSize(5);
Tau21VRhoP_wq_PT500t600_pfx->SetMarkerSize(5);
Tau21VRhoP_wq_PT1000t1100_pfx->SetMarkerSize(5);

Tau21VRhoP_bg_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRhoP_bg_PT500t600_pfx->SetLineColor(kRed);
Tau21VRhoP_bg_PT1000t1100_pfx->SetLineColor(kBlue);

Tau21VRhoP_sig_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRhoP_sig_PT500t600_pfx->SetLineColor(kRed);
Tau21VRhoP_sig_PT1000t1100_pfx->SetLineColor(kBlue);

Tau21VRhoP_sig_PT300t400_pfx->SetLineStyle(3);
Tau21VRhoP_sig_PT500t600_pfx->SetLineStyle(3);
Tau21VRhoP_sig_PT1000t1100_pfx->SetLineStyle(3);

Tau21VRhoP_sig_PT300t400_pfx->SetLineWidth(4);
Tau21VRhoP_sig_PT500t600_pfx->SetLineWidth(4);
Tau21VRhoP_sig_PT1000t1100_pfx->SetLineWidth(4);

Tau21VRhoP_wq_PT300t400_pfx->SetLineStyle(9);
Tau21VRhoP_wq_PT500t600_pfx->SetLineStyle(9);
Tau21VRhoP_wq_PT1000t1100_pfx->SetLineStyle(9);

Tau21VRhoP_wq_PT300t400_pfx->SetLineColor(kBlack);
Tau21VRhoP_wq_PT500t600_pfx->SetLineColor(kRed);
Tau21VRhoP_wq_PT1000t1100_pfx->SetLineColor(kBlue);


Tau21VRhoP_bg_PT300t400->SetMarkerSize(1.2);
Tau21VRhoP_bg_PT500t600->SetMarkerSize(1.2);
Tau21VRhoP_bg_PT1000t1100->SetMarkerSize(1.2);

Tau21VRhoP_sig_PT300t400->SetMarkerSize(1.2);
Tau21VRhoP_sig_PT500t600->SetMarkerSize(1.2);
Tau21VRhoP_sig_PT1000t1100->SetMarkerSize(1.2);

Tau21VRhoP_wq_PT300t400->SetMarkerSize(1.2);
Tau21VRhoP_wq_PT500t600->SetMarkerSize(1.2);
Tau21VRhoP_wq_PT1000t1100->SetMarkerSize(1.2);

Tau21VRhoP_bg_PT300t400->SetLineColor(kBlack);
Tau21VRhoP_bg_PT500t600->SetLineColor(kRed);
Tau21VRhoP_bg_PT1000t1100->SetLineColor(kBlue);

Tau21VRhoP_sig_PT300t400->SetLineColor(kBlack);
Tau21VRhoP_sig_PT500t600->SetLineColor(kRed);
Tau21VRhoP_sig_PT1000t1100->SetLineColor(kBlue);

Tau21VRhoP_sig_PT300t400->SetLineStyle(3);
Tau21VRhoP_sig_PT500t600->SetLineStyle(3);
Tau21VRhoP_sig_PT1000t1100->SetLineStyle(3);

Tau21VRhoP_sig_PT300t400->SetLineWidth(4);
Tau21VRhoP_sig_PT500t600->SetLineWidth(4);
Tau21VRhoP_sig_PT1000t1100->SetLineWidth(4);

Tau21VRhoP_wq_PT300t400->SetLineStyle(9);
Tau21VRhoP_wq_PT500t600->SetLineStyle(9);
Tau21VRhoP_wq_PT1000t1100->SetLineStyle(9);

Tau21VRhoP_wq_PT300t400->SetLineColor(kBlack);
Tau21VRhoP_wq_PT500t600->SetLineColor(kRed);
Tau21VRhoP_wq_PT1000t1100->SetLineColor(kBlue);

Tau21VRhoP_bg_PT300t400->SetTitle("Tau2/Tau1 vs Rho';Rho';Tau2/Tau1");
Tau21VRhoP_bg_PT300t400_pfx->SetTitle("Tau2/Tau1 vs Rho';Rho';Tau2/Tau1");

Tau21VRhoP_bg_PT300t400_pfx->Draw();

TCanvas *c1= new TCanvas("c1");
Tau21VRhoP_bg_PT500t600_pfx->Draw();
TCanvas *c2= new TCanvas("c2");
Tau21VRhoP_bg_PT1000t1100_pfx->Draw();

TCanvas *c3= new TCanvas("c3");
Tau21VRhoP_sig_PT300t400_pfx->Draw();
TCanvas *c4= new TCanvas("c4");
Tau21VRhoP_sig_PT500t600_pfx->Draw();
TCanvas *c5= new TCanvas("c5");
Tau21VRhoP_sig_PT1000t1100_pfx->Draw();

TCanvas *c7= new TCanvas("c7");
Tau21VRhoP_wq_PT300t400_pfx->Draw();
TCanvas *c8= new TCanvas("c8");
Tau21VRhoP_wq_PT500t600_pfx->Draw();
TCanvas *c9= new TCanvas("c9");
Tau21VRhoP_wq_PT1000t1100_pfx->Draw();


/*
Tau21VRhoP_sig_PT300t400_pfx->Draw("same");
Tau21VRhoP_sig_PT500t600_pfx->Draw("same");
Tau21VRhoP_sig_PT1000t1100_pfx->Draw("same");

Tau21VRhoP_wq_PT300t400_pfx->Draw("same");
Tau21VRhoP_wq_PT500t600_pfx->Draw("same");
Tau21VRhoP_wq_PT1000t1100_pfx->Draw("same");
*/
//Name1->Draw();
//Test
//Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Tau21VRho_bg_PT500t600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff");
//Bkgnd->Draw("fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2)","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)");

//Tau21VRho_bg_PT500t600->Draw("AP")
/*
histo->SetMarkerSize(1.2);
histo->SetMarkerStyle(20);
histo->Draw("P");
*/
/*
Tau21VRho_bg_PT300t400->Draw();
Tau21VRho_bg_PT500t600->Draw("same");
Tau21VRho_bg_PT1000t1100->Draw("same");

Tau21VRho_sig_PT300t400->Draw("same");
Tau21VRho_sig_PT500t600->Draw("same");
Tau21VRho_sig_PT1000t1100->Draw("same");

Tau21VRho_wq_PT300t400->Draw("same");
Tau21VRho_wq_PT500t600->Draw("same");
Tau21VRho_wq_PT1000t1100->Draw("same");
*/
//leg->Draw("same");

//reweighting
  Bkgnd->Draw("fjetTau_m[0]>>Bg_Mass","lumi_weight*event_weight", "goff");
  Bkgnd->Draw("fjetTau_pt[0]>>Bg_PT","lumi_weight*event_weight","goff");
  s->Draw("fjetTau_m[0]>>Sig_Mass","lumi_weight*event_weight","goff");
  s->Draw("fjetTau_pt[0]>>Sig_PT","lumi_weight*event_weight","goff");
  w->Draw("fjetTau_m[0]>>Wqq_Mass","lumi_weight*event_weight","goff");
  w->Draw("fjetTau_pt[0]>>Wqq_PT","lumi_weight*event_weight","goff");


//Drawing and reweighting
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21","lumi_weight*event_weight", "goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21","lumi_weight*event_weight","goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21","lumi_weight*event_weight","goff norm");

Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21P","lumi_weight*event_weight", "goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21P","lumi_weight*event_weight","goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21P","lumi_weight*event_weight","goff norm");

//Reweighting tau21 for different PT Slices
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff norm");

s->Draw("fjet_tau21[0]>>Sig_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff norm");

w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff norm");


//Tau prime reweighting
Bkgnd->Draw("fjet_tau21[0]+0.04605*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Bg_Tau21P_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]+0.08212*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Bg_Tau21P_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]+0.05969*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Bg_Tau21P_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff norm");

s->Draw("fjet_tau21[0]+0.1175*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Sig_Tau21P_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff norm");
s->Draw("fjet_tau21[0]+0.08551*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Sig_Tau21P_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff norm");
s->Draw("fjet_tau21[0]+0.0406696*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Sig_Tau21P_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff norm");

w->Draw("fjet_tau21[0]+0.1122*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Wqq_Tau21P_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff norm");
w->Draw("fjet_tau21[0]+0.06212*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Wqq_Tau21P_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff norm");
w->Draw("fjet_tau21[0]+0.07104*log(fjet_m[0]^2/ut_fjet10_pt[0]/1000)>>Wqq_Tau21P_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff norm");

//Reweighting rho for different PT slices
Bkgnd->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Bg_Rho_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff ");
Bkgnd->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Bg_Rho_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff ");
Bkgnd->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Bg_Rho_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff ");

s->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Sig_Rho_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff");
s->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Sig_Rho_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff");
s->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Sig_Rho_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff");

w->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Wqq_Rho_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)","goff ");
w->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Wqq_Rho_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)","goff ");
w->Draw("log(fjet_m[0]^2/ut_fjet10_pt[0]^2)>>Wqq_Rho_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)","goff ");

//PT Slices
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff norm");
Bkgnd->Draw("fjet_tau21[0]>>Bg_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff norm");
w->Draw("fjet_tau21[0]>>Wqq_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21_PT300to400","lumi_weight*event_weight*(fjet_pt[0]<400*10^3&&fjet_pt[0]>300*10^3)", "goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21_PT500to600","lumi_weight*event_weight*(fjet_pt[0]<600*10^3&&fjet_pt[0]>500*10^3)", "goff norm");
s->Draw("fjet_tau21[0]>>Sig_Tau21_PT1000to1100","lumi_weight*event_weight*(fjet_pt[0]<1100*10^3&&fjet_pt[0]>1000*10^3)", "goff norm");

leg = new TLegend(0.62,0.7,0.98,0.95);
//leg->SetLegendTextSize(0.35);
  // leg->SetHeader("The Legend Title","C"); // option "C" allows to center the header
   leg->AddEntry(Bg_Tau21_PT300to400,"j+j, P_{T}=300-400 GeV","l");
   leg->AddEntry(Bg_Tau21_PT500to600,"j+j, P_{T}=500-600 GeV","l");
   leg->AddEntry(Bg_Tau21_PT1000to1100,"j+j, P_{T}=1000-1100 GeV","l");
   leg->AddEntry(Wqq_Tau21_PT300to400,"W+j, P_{T}=300-400 GeV","l");
   leg->AddEntry(Wqq_Tau21_PT500to600,"W+j, P_{T}=500-600 GeV","l");
   leg->AddEntry(Wqq_Tau21_PT1000to1100,"W+j, P_{T}=1000-1100 GeV","l");
   leg->AddEntry(Sig_Tau21_PT300to400,"Signal:Z+j, P_{T}=300-400 GeV","l");
   leg->AddEntry(Sig_Tau21_PT500to600,"Signal:Z+j, P_{T}=500-600 GeV","l");
   leg->AddEntry(Sig_Tau21_PT1000to1100,"Signal:Z+j, P_{T}=1000-1100 GeV","l");

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
/*
  TCanvas*Tau21VsRho = new TCanvas("Tau21VsRho");
Bkgnd->SetLineColor(kBlack);
Bkgnd->Draw(fjet_tau21[0]:log(fjet_m[0]^2/ut_fjet10_pt[0]^2) {lumi_weight*event_weight*(fjet_m[0]>20e3 && fjet_pt[0]>500e3 && fjet_pt[0]<650e3)});

  Tau21VRho_bg_PT300to400->SetLineColor(kBlack);
  Tau21VRho_bg_PT500to600->SetLineColor(kRed);
  Tau21VRho_bg_PT1000to1100->SetLineColor(kBlue);

  Tau21VRho_sig_PT300to400->SetLineColor(kBlack);
  Tau21VRho_sig_PT500to600->SetLineColor(kRed);
  Tau21VRho_sig_PT1000to1100->SetLineColor(kBlue);

  Tau21VRho_sig_PT300to400->SetLineStyle(3);
  Tau21VRho_sig_PT500to600->SetLineStyle(3);
  Tau21VRho_sig_PT1000to1100->SetLineStyle(3);

  Tau21VRho_sig_PT300to400->SetLineWidth(4);
  Tau21VRho_sig_PT500to600->SetLineWidth(4);
  Tau21VRho_sig_PT1000to1100->SetLineWidth(4);

  Tau21VRho_wq_PT300to400->SetLineStyle(9);
  Tau21VRho_wq_PT500to600->SetLineStyle(9);
  Tau21VRho_wq_PT1000to1100->SetLineStyle(9);

  Tau21VRho_wq_PT300to400->SetLineColor(kBlack);
  Tau21VRho_wq_PT500to600->SetLineColor(kRed);
  Tau21VRho_wq_PT1000to1100->SetLineColor(kBlue);

Tau21VRho_bg_PT300to400->SetTitle("Rho Distribution;Rho;Events");
//LeadingRhoSlices_Canvas->SetLogy();
  Tau21VRho_bg_PT300to400->Draw();
 Tau21VRho_bg_PT500to600->Draw("same");
  Tau21VRho_bg_PT1000to1100->Draw("same");

  Tau21VRho_sig_PT300to400->Draw("same");
  Tau21VRho_sig_PT500to600->Draw("same");
  Tau21VRho_sig_PT1000to1100->Draw("same");

  Tau21VRho_wq_PT300to400->Draw("same");
  Tau21VRho_wq_PT500to600->Draw("same");
  Tau21VRho_wq_PT1000to1100->Draw("same");

  leg->Draw("same");
*/



  TCanvas*LeadingRhoSlices_Canvas = new TCanvas("Leading AKT10 Rho PT Slices");
  LeadingRhoSlices_Canvas->SetLogy();
  Bg_Rho_PT300to400->SetLineColor(kBlack);
  Bg_Rho_PT500to600->SetLineColor(kRed);
  Bg_Rho_PT1000to1100->SetLineColor(kBlue);

  Sig_Rho_PT300to400->SetLineColor(kBlack);
  Sig_Rho_PT500to600->SetLineColor(kRed);
  Sig_Rho_PT1000to1100->SetLineColor(kBlue);

  Sig_Rho_PT300to400->SetLineStyle(3);
  Sig_Rho_PT500to600->SetLineStyle(3);
  Sig_Rho_PT1000to1100->SetLineStyle(3);

  Sig_Rho_PT300to400->SetLineWidth(4);
  Sig_Rho_PT500to600->SetLineWidth(4);
  Sig_Rho_PT1000to1100->SetLineWidth(4);

  Wqq_Rho_PT300to400->SetLineStyle(9);
  Wqq_Rho_PT500to600->SetLineStyle(9);
  Wqq_Rho_PT1000to1100->SetLineStyle(9);

  Wqq_Rho_PT300to400->SetLineColor(kBlack);
  Wqq_Rho_PT500to600->SetLineColor(kRed);
  Wqq_Rho_PT1000to1100->SetLineColor(kBlue);

Bg_Rho_PT300to400->SetTitle("Rho Distribution;Rho;Events");
//LeadingRhoSlices_Canvas->SetLogy();
  Bg_Rho_PT300to400->Draw();
 Bg_Rho_PT500to600->Draw("same");
  Bg_Rho_PT1000to1100->Draw("same");

  Sig_Rho_PT300to400->Draw("same");
  Sig_Rho_PT500to600->Draw("same");
  Sig_Rho_PT1000to1100->Draw("same");

  Wqq_Rho_PT300to400->Draw("same");
  Wqq_Rho_PT500to600->Draw("same");
  Wqq_Rho_PT1000to1100->Draw("same");

  leg->Draw("same");


  TCanvas*LeadingTau21Slices_Canvas = new TCanvas("Leading AKT10 Tau2/Tau1 PT Slices");
//LeadingTau21Slices_Canvas->SetLogy();
  Bg_Tau21_PT300to400->SetLineColor(kBlack);
  Bg_Tau21_PT500to600->SetLineColor(kRed);
  Bg_Tau21_PT1000to1100->SetLineColor(kBlue);

  Sig_Tau21_PT300to400->SetLineColor(kBlack);
  Sig_Tau21_PT500to600->SetLineColor(kRed);
  Sig_Tau21_PT1000to1100->SetLineColor(kBlue);

  Sig_Tau21_PT300to400->SetLineStyle(3);
  Sig_Tau21_PT500to600->SetLineStyle(3);
  Sig_Tau21_PT1000to1100->SetLineStyle(3);

  Sig_Tau21_PT300to400->SetLineWidth(4);
  Sig_Tau21_PT500to600->SetLineWidth(4);
  Sig_Tau21_PT1000to1100->SetLineWidth(4);

  Wqq_Tau21_PT300to400->SetLineStyle(9);
  Wqq_Tau21_PT500to600->SetLineStyle(9);
  Wqq_Tau21_PT1000to1100->SetLineStyle(9);

  Wqq_Tau21_PT300to400->SetLineColor(kBlack);
  Wqq_Tau21_PT500to600->SetLineColor(kRed);
  Wqq_Tau21_PT1000to1100->SetLineColor(kBlue);

  Bg_Tau21_PT300to400->SetTitle("Tau2/Tau1 Distribution;tau2/tau1;Fraction of Events(Normalized)");

  Bg_Tau21_PT300to400->Draw();

  Bg_Tau21_PT500to600->Draw("same");
  Bg_Tau21_PT1000to1100->Draw("same");

  Sig_Tau21_PT300to400->Draw("same");
  Sig_Tau21_PT500to600->Draw("same");
  Sig_Tau21_PT1000to1100->Draw("same");

  Wqq_Tau21_PT300to400->Draw("same");
  Wqq_Tau21_PT500to600->Draw("same");
  Wqq_Tau21_PT1000to1100->Draw("same");

  leg->Draw("same");

  TCanvas*LeadingTau21PSlices_Canvas = new TCanvas("Leading AKT10 Tau2/Tau1 PT Slices");
  LeadingTau21PSlices_Canvas->SetLogy();
  //LeadingTau21PSlices_Canvas->SetLogy();
  Bg_Tau21P_PT300to400->SetLineColor(kBlack);
  Bg_Tau21P_PT500to600->SetLineColor(kRed);
  Bg_Tau21P_PT1000to1100->SetLineColor(kBlue);

  Sig_Tau21P_PT300to400->SetLineColor(kBlack);
  Sig_Tau21P_PT500to600->SetLineColor(kRed);
  Sig_Tau21P_PT1000to1100->SetLineColor(kBlue);

  Sig_Tau21P_PT300to400->SetLineStyle(3);
  Sig_Tau21P_PT500to600->SetLineStyle(3);
  Sig_Tau21P_PT1000to1100->SetLineStyle(3);

  Sig_Tau21P_PT300to400->SetLineWidth(4);
  Sig_Tau21P_PT500to600->SetLineWidth(4);
  Sig_Tau21P_PT1000to1100->SetLineWidth(4);

  Wqq_Tau21P_PT300to400->SetLineStyle(9);
  Wqq_Tau21P_PT500to600->SetLineStyle(9);
  Wqq_Tau21P_PT1000to1100->SetLineStyle(9);

  Wqq_Tau21P_PT300to400->SetLineColor(kBlack);
  Wqq_Tau21P_PT500to600->SetLineColor(kRed);
  Wqq_Tau21P_PT1000to1100->SetLineColor(kBlue);

  Bg_Tau21P_PT300to400->SetTitle("Tau2/Tau1' Distribution;tau2/tau1';Fraction of Events(Normalized)");

  Bg_Tau21P_PT300to400->Draw();

  Bg_Tau21P_PT500to600->Draw("same");
  Bg_Tau21P_PT1000to1100->Draw("same");

  Sig_Tau21P_PT300to400->Draw("same");
  Sig_Tau21P_PT500to600->Draw("same");
  Sig_Tau21P_PT1000to1100->Draw("same");

  Wqq_Tau21P_PT300to400->Draw("same");
  Wqq_Tau21P_PT500to600->Draw("same");
  Wqq_Tau21P_PT1000to1100->Draw("same");

  leg->Draw("same");


TCanvas*LeadingTau21_Canvas = new TCanvas("Leading AKT10 Tau2/Tau1");
//LeadingTau21_Canvas->SetLogy();
Bg_Tau21->SetLineColor(kBlue);
Wqq_Tau21->SetLineColor(kGreen);
Sig_Tau21->SetLineColor(kRed);

Bg_Tau21->Draw();
Wqq_Tau21->Draw("same");
Sig_Tau21->Draw("same");

TCanvas*LeadingTau21P_Canvas = new TCanvas("Leading AKT10 Tau2/Tau1");
//LeadingTau21P_Canvas->SetLogy();
Bg_Tau21P->SetLineColor(kBlue);
Wqq_Tau21P->SetLineColor(kGreen);
Sig_Tau21P->SetLineColor(kRed);

Bg_Tau21P->Draw();
Wqq_Tau21P->Draw("same");
Sig_Tau21P->Draw("same");


/*
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
*/
//Sig in the bottom
/*
      Stack_PT->Add(Sig_PT);
      Stack_PT->Add(Wqq_PT);
    Stack_PT->Add(Bg_PT);

*/
/*
  cout<<"Check8"<<endl;

  TCanvas *PT_Stacked= new TCanvas("pt_stack","pt_stack",700, 500);
//  PT_Stacked->SetLogy();
  Stack_PT->Draw();
  cout<<"Check9"<<endl;

  //Bg_PT->Clear();
  //Wqq_PT->Clear();
  //Sig_PT->Clear();
*/
}

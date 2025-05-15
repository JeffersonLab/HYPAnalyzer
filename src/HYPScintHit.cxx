#include "HYPScintHit.h"

#include <iostream>

//___________________________________________________________________
HYPScintHit::HYPScintHit(Int_t Postdc, Int_t Negtdc, Double_t Posadc, Double_t Negadc, Int_t ipad,
                             HYPScintillatorPlane *hp)
    : fPosTDC(Postdc), fNegTDC(Negtdc), fPosADC_Ped(Posadc), fNegADC_Ped(Negadc), fPaddleNumber(ipad),fTwoGoodTimes(kFALSE), fPlane(hp) {}

//___________________________________________________________________
HYPScintHit::~HYPScintHit() {}

void HYPScintHit::SetCorrectedTimes(Double_t Pos, Double_t Neg, Double_t Postof, Double_t Negtof, Double_t timeave) {
  fPosCorrectedTime = Pos;
  fNegCorrectedTime = Neg;
  fPosTOFCorrectedTime = Postof;
  fNegTOFCorrectedTime = Negtof;
  fScinCorrectedTime = timeave;
  fHasCorrectedTimes = kTRUE;
}

void HYPScintHit::SetCorrectedTimes(Double_t Pos, Double_t Neg) {
  fPosCorrectedTime = Pos;
  fNegCorrectedTime = Neg;
  fHasCorrectedTimes = kFALSE;
}

ClassImp(HYPScintHit)

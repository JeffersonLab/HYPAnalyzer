#ifndef HYPScintHit_h
#define HYPScintHit_h

#include "HYPScintillatorPlane.h"
#include "THcRawHodoHit.h"
#include "TObject.h"

// Scint Hit Object, reused the one from LADHodoHit to start

class HYPScintHit : public TObject {
public:
  HYPScintHit(Int_t Postdc, Int_t Negtdc, Double_t Posadc, Double_t Negadc, Int_t ipad, HYPScintillatorPlane *hp);
  virtual ~HYPScintHit();

  Double_t GetPosADC() const { return fPosADC_Ped; }
  Double_t GetNegADC() const { return fNegADC_Ped; }
  Double_t GetPosADCpeak() const { return fPosADC_Peak; }
  Double_t GetNegADCpeak() const { return fNegADC_Peak; }
  Double_t GetPosADCtime() const { return fPosADC_Time; }
  Double_t GetNegADCtime() const { return fNegADC_Time; }
  Double_t GetPosADCCorrtime() const { return fPosADC_CorrTime; }
  Double_t GetNegADCCorrtime() const { return fNegADC_CorrTime; }
  Double_t GetCalcPosition() const { return fCalcPosition; }
  Int_t GetPosTDC() const { return fPosTDC; }
  Int_t GetNegTDC() const { return fNegTDC; }
  Double_t GetPosCorrectedTime() const { return fPosCorrectedTime; }
  Double_t GetNegCorrectedTime() const { return fNegCorrectedTime; }
  Double_t GetPosTOFCorrectedTime() const { return fPosTOFCorrectedTime; }
  Double_t GetNegTOFCorrectedTime() const { return fNegTOFCorrectedTime; }
  Double_t GetScinCorrectedTime() const { return fScinCorrectedTime; }
  Bool_t GetTwoGoodTimes() const { return fTwoGoodTimes; }
  Bool_t GetHasCorrectedTimes() const { return fHasCorrectedTimes; }
  Int_t GetPaddleNumber() const { return fPaddleNumber; }
  Int_t GetPaddleCenter() const { return fPaddleCenter; }
  Double_t GetPaddleADC() const { return sqrt(fPosADC_Ped * fNegADC_Ped); }

  void SetPaddleCenter(Double_t padcenter) { fPaddleCenter = padcenter; }
  void SetPosADCpeak(Double_t adc) { fPosADC_Peak = adc; }
  void SetNegADCpeak(Double_t adc) { fNegADC_Peak = adc; }
  void SetPosADCtime(Double_t ptime) { fPosADC_Time = ptime; }
  void SetPosADCCorrtime(Double_t ptime) { fPosADC_CorrTime = ptime; }
  void SetNegADCCorrtime(Double_t ptime) { fNegADC_CorrTime = ptime; }
  void SetCalcPosition(Double_t calcpos) { fCalcPosition = calcpos; }
  void SetNegADCtime(Double_t ptime) { fNegADC_Time = ptime; }
  void SetCorrectedTimes(Double_t Pos, Double_t Neg);
  void SetCorrectedTimes(Double_t Pos, Double_t Neg, Double_t Postof, Double_t Negtof, Double_t timeave);

protected:
  Int_t fPosTDC;
  Int_t fNegTDC;
  Double_t fPosADC_Ped; // Pedestal subtracted ADC
  Double_t fNegADC_Ped;
  Double_t fPosADC_Peak; // ADC peak amplitude
  Double_t fNegADC_Peak; // ADC peak amplitude
  Double_t fPosADC_Time;
  Double_t fNegADC_Time;
  Double_t fPosADC_CorrTime; // ADC time
  Double_t fNegADC_CorrTime; // ADC time
  Double_t fCalcPosition;    // Position along paddle calculated by time diff
  Int_t fPaddleNumber;

  Double_t fPosCorrectedTime;    // Pulse height corrected time
  Double_t fNegCorrectedTime;    // Pulse height corrected time
  Double_t fScinCorrectedTime;   // Time average corrected for position
                                 // based on ADCs.
  Double_t fPosTOFCorrectedTime; // Times corrected for z position
  Double_t fNegTOFCorrectedTime; // using nominal beta

  Bool_t fHasCorrectedTimes;
  Bool_t fTwoGoodTimes;
  Double_t fPaddleCenter;

  HYPScintillatorPlane *fPlane;

private:
  HYPScintHit(const HYPScintHit &);
  HYPScintHit &operator=(const HYPScintHit &);

  ClassDef(HYPScintHit, 0)
};

#endif

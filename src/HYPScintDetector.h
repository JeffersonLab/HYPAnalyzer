#ifndef HYPScintDetector_h
#define HYPScintDetector_h

// Scint detector class
// Shall be used for EHodo and TOF detectors

#include "TClonesArray.h"
#include "THaNonTrackingDetector.h"
#include "THaSpectrometer.h"
#include "THcHitList.h"
#include "HYPScintHit.h"
#include "THcRawHodoHit.h"

class HYPScintDetector : public THaNonTrackingDetector, public THcHitList {
 public:
  HYPScintDetector(const char* name, const char* description="",
	    THaApparatus* apparatus = NULL);
  virtual ~HYPScintDetector();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t   Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& date );
  virtual Int_t   CoarseProcess( TClonesArray& tracks );
  virtual Int_t   FineProcess( TClonesArray& tracks );

  Double_t DetermineTimePeak(Int_t FillFlag) { return 0.; } // func not defined yet

  Int_t GetScinIndex(Int_t nPlane, Int_t nPaddle) { return fNPlanes * nPaddle + nPlane; }
  Int_t GetScinIndex(Int_t nSide, Int_t nPlane, Int_t nPaddle) {
    return nSide * fMaxHodoScin + fNPlanes * nPaddle + nPlane - 1;
  }

  HYPScintillatorPlane* GetPlane(Int_t ip) { return fPlanes[ip];}
  Int_t GetNPlanes() { return fNPlanes;}
  Double_t GetHodoSlop(Int_t ip) { return fHodoSlop[ip];}
  Int_t GetTdcOffset(Int_t ip) const { return fTdcOffset[ip];}
  Double_t GetAdcTdcOffset(Int_t ip) const { return fAdcTdcOffset[ip];}
  Double_t GetTdcMin() const {return fScinTdcMin;}
  Double_t GetTdcMax() const {return fScinTdcMax;}
  Double_t GetTdcToTime() const {return fScinTdcToTime;}

  Double_t GetHodoPosAdcTimeWindowMax(Int_t iii) const {return fHodoPosAdcTimeWindowMax[iii];}
  Double_t GetHodoPosAdcTimeWindowMin(Int_t iii) const {return fHodoPosAdcTimeWindowMin[iii];}
  Double_t GetHodoNegAdcTimeWindowMax(Int_t iii) const {return fHodoNegAdcTimeWindowMax[iii];}
  Double_t GetHodoNegAdcTimeWindowMin(Int_t iii) const {return fHodoNegAdcTimeWindowMin[iii];}

  Double_t GetHodoVelLight(Int_t iii) const {return fHodoVelLight[iii];}

  //Get Time Walk Parameters
  Double_t GetHodoVelFit(Int_t iii) const {return fHodoVelFit[iii];}
  Double_t GetHodoCableFit(Int_t iii) const {return fHodoCableFit[iii];}
  Double_t GetHodoLCoeff(Int_t iii) const {return fHodo_LCoeff[iii];}


  Double_t GetHodoPos_c1(Int_t iii) const {return fHodoPos_c1[iii];}
  Double_t GetHodoNeg_c1(Int_t iii) const {return fHodoNeg_c1[iii];}
  Double_t GetHodoPos_c2(Int_t iii) const {return fHodoPos_c2[iii];}
  Double_t GetHodoNeg_c2(Int_t iii) const {return fHodoNeg_c2[iii];}
  Double_t GetTDCThrs() const {return fTdc_Thrs;}

  //Double_t GetBeta() const {return fBeta;}

 protected:

  Int_t  fNhits;
  Bool_t *fPresentP;

  Int_t fNPlanes;
  Int_t *fNPaddle;
  Int_t fMaxHodoScin;
  Int_t fCosmicFlag;
  Double_t fScinTdcMin, fScinTdcMax;
  Double_t fScinTdcToTime;
  Int_t *fTdcOffset;
  Double_t *fAdcTdcOffset;
  Double_t *fHodoSlop;
  Int_t fIsMC;

  Double_t *fHodoVelLight;

  // Double_t fBeta;

  Int_t *fNScinHits;       // [fNPlanes]

  // Time walk
  Double_t *fHodoVelFit;
  Double_t *fHodoCableFit;
  Double_t *fHodo_LCoeff;
  Double_t *fHodoPos_c1;
  Double_t *fHodoNeg_c1;
  Double_t *fHodoPos_c2;
  Double_t *fHodoNeg_c2;
  Double_t fTdc_Thrs;

  Int_t fAnalyzePedestals;

  Double_t *fHodoNegAdcTimeWindowMin;
  Double_t *fHodoNegAdcTimeWindowMax;
  Double_t *fHodoPosAdcTimeWindowMin;
  Double_t *fHodoPosAdcTimeWindowMax;

  HYPScintillatorPlane **fPlanes;
  char **fPlaneNames;

  virtual Int_t ReadDatabase( const TDatime& date );
  virtual Int_t DefineVariables( EMode mode = kDefine );
  void Setup(const char *name, const char *description);

  ClassDef(HYPScintDetector,0)
};

#endif

#ifndef HYPCherenkov_h
#define HYPCherenkov_h

// Cherenkov detector class
#include "TClonesArray.h"
#include "THaNonTrackingDetector.h"
#include "THcHitList.h"
#include "THcCherenkovHit.h"
#include <vector>

using namespace std;

// base class for AC and WC Cherenkov

class HYPCherenkov : public THaNonTrackingDetector, THcHitList {
 public:
  HYPCherenkov(const char* name, const char* description="",
	    THaApparatus* apparatus = NULL);
  virtual ~HYPCherenkov();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t   Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& date );
  virtual Int_t   CoarseProcess( TClonesArray& tracks );
  virtual Int_t   FineProcess( TClonesArray& tracks );

  HYPCherenkov();

 protected:

  Int_t fNhits;
  Bool_t* fPresentP;

  Int_t     fADC_RefTimeCut;
  Int_t     fUseSampWaveform;
  Double_t  fSampThreshold;
  Int_t     fSampNSA;
  Int_t     fSampNSAT;
  Int_t     fSampNSB;
  Int_t     fDebugAdc;

  //Double_t  *fAdcPosTimeWindowMin;
  //Double_t  *fAdcPosTimeWindowMax;
  //Double_t  *fAdcNegTimeWindowMin;
  //Double_t  *fAdcNegTimeWindowMax;

  // FIXME: make it more generic for other detectors too
  class FADCHitData {
    public:
    FADCHitData() : paddle(0), Ped(0), PulseInt(0), PulseAmp(0),
    PulseTime(0) {}

    void clear() {
      paddle = 0;
      Ped = PulseInt = PulseAmp = PulseTime = 0.0;
    }
    Int_t  paddle;
    Data_t Ped;
    Data_t PulseInt;
    Data_t PulseAmp;
    Data_t PulseTime;
  };

  vector<FADCHitData> fPosDataRaw;
  vector<FADCHitData> fNegDataRaw;
  vector<FADCHitData> fPosData;
  vector<FADCHitData> fNegData;

  vector<FADCHitData> fPosSampDataRaw;
  vector<FADCHitData> fNegSampDataRaw;
  vector<FADCHitData> fPosSampData;
  vector<FADCHitData> fNegSampData;

  vector<Int_t> fPosErrorFlag;
  vector<Int_t> fNegErrorFlag;

  virtual Int_t ReadDatabase( const TDatime& date );
  virtual Int_t DefineVariables( EMode mode = kDefine );

  ClassDef(HYPCherenkov,0)

};

#endif

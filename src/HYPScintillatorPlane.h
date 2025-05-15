#ifndef HYPScintillatorPlane_h
#define HYPScintillatorPlane_h

#include "TClonesArray.h"
#include "THaSubDetector.h"
#include "THcScintPlaneCluster.h"
#include <vector>

using namespace std;

class THaEvData;
class THaSignalHit;

// Scintillator plane class, based on LAD HodoPlane 
// contains xx number of paddles per plane

class HYPScintillatorPlane : public THaSubDetector {

public:
  HYPScintillatorPlane(const char *name, const char *description, const Int_t planenum, THaDetectorBase *parent = nullptr);
  virtual ~HYPScintillatorPlane();

  virtual void Clear(Option_t *opt = "");
  virtual Int_t Decode(const THaEvData &);
  virtual EStatus Init(const TDatime &date);

  virtual Int_t CoarseProcess(TClonesArray &tracks);
  virtual Int_t FineProcess(TClonesArray &tracks);
  virtual Int_t ProcessHits(TClonesArray *rawhits, Int_t nexthit);

  virtual Int_t AccumulatePedestals(TClonesArray *rawhits, Int_t nexthit);
  virtual void  CalculatePedestals();

  // Some getter/setter functions here

  Int_t GetNelem() { return fNelem; };          // return number of paddles in this plane
  Int_t GetNScinHits() { return fNScinHits; };  // Get # hits in plane (that pass min/max TDC cuts)
  Int_t GetNGoodHits() { return fNGoodHits; };  // Get # hits in plane (used in determining focal plane time)
  Double_t GetSpacing() { return fSpacing; };   // spacing of paddles
  Double_t GetSize() { return fSize; };         // paddle size
  Double_t GetHodoSlop() { return fHodoSlop; }; // hodo slop
  Double_t GetZpos() { return fZpos; };         // return the z position
  Double_t GetDzpos() { return fDzpos; }
  Double_t GetPosOffset() {return fPosOffset;};
  Double_t GetPosCenter(Int_t PaddleNo) { return fPosCenter[PaddleNo]; }; // counting from zero!
  Double_t GetPosLeft(Int_t PaddleNo) { return fPosLeft[PaddleNo]; }
  Double_t GetPosRight(Int_t PaddleNo) { return fPosRight[PaddleNo]; }

  TClonesArray *GetHits() { return fHodoHits; }
  TClonesArray *GetClusters() { return fCluster; }
  
protected:

  TClonesArray* fCluster;

  TClonesArray *frPosAdcErrorFlag;
  TClonesArray *frNegAdcErrorFlag;
  
  TClonesArray *frPosTdcHits;
  TClonesArray *frNegTdcHits;
  TClonesArray *frPosAdcHits;
  TClonesArray *frNegAdcHits;
  TClonesArray *frPosAdcSums;
  TClonesArray *frNegAdcSums;
  TClonesArray *frPosAdcPeds;
  TClonesArray *frNegAdcPeds;
  TClonesArray *fHodoHits;

  // Raw data
  TClonesArray *frPosTdcTimeRaw;
  TClonesArray *frPosAdcPedRaw;
  TClonesArray *frPosAdcPulseIntRaw;
  TClonesArray *frPosAdcPulseAmpRaw;
  TClonesArray *frPosAdcPulseTimeRaw;

  TClonesArray *frPosTdcTime;
  TClonesArray *frPosAdcPed;
  TClonesArray *frPosAdcPulseInt;
  TClonesArray *frPosAdcPulseAmp;
  TClonesArray *frPosAdcPulseTime;

  TClonesArray *frNegTdcTimeRaw;
  TClonesArray *frNegAdcPedRaw;
  TClonesArray *frNegAdcPulseIntRaw;
  TClonesArray *frNegAdcPulseAmpRaw;
  TClonesArray *frNegAdcPulseTimeRaw;

  TClonesArray *frNegTdcTime;
  TClonesArray *frNegAdcPed;
  TClonesArray *frNegAdcPulseInt;
  TClonesArray *frNegAdcPulseAmp;
  TClonesArray *frNegAdcPulseTime;

  TClonesArray *frPosAdcSampPedRaw;
  TClonesArray *frPosAdcSampPulseIntRaw;
  TClonesArray *frPosAdcSampPulseAmpRaw;
  TClonesArray *frPosAdcSampPulseTimeRaw;
  TClonesArray *frPosAdcSampPed;
  TClonesArray *frPosAdcSampPulseInt;
  TClonesArray *frPosAdcSampPulseAmp;
  TClonesArray *frPosAdcSampPulseTime;

  TClonesArray *frNegAdcSampPedRaw;
  TClonesArray *frNegAdcSampPulseIntRaw;
  TClonesArray *frNegAdcSampPulseAmpRaw;
  TClonesArray *frNegAdcSampPulseTimeRaw;
  TClonesArray *frNegAdcSampPed;
  TClonesArray *frNegAdcSampPulseInt;
  TClonesArray *frNegAdcSampPulseAmp;
  TClonesArray *frNegAdcSampPulseTime;

  // Counters
  Int_t fTotNumTdcHits;
  Int_t fTotNumPosTdcHits;
  Int_t fTotNumNegTdcHits;

  Int_t fTotNumAdcHits;
  Int_t fTotNumPosAdcHits;
  Int_t fTotNumNegAdcHits;

  Int_t fTotNumGoodPosAdcHits;
  Int_t fTotNumGoodNegAdcHits;
  Int_t fTotNumGoodAdcHits;

  Int_t fTotNumGoodPosTdcHits;
  Int_t fTotNumGoodNegTdcHits;
  Int_t fTotNumGoodTdcHits;

  // Occupancies
  vector<Int_t> fNumPosAdcHits;
  vector<Int_t> fNumNegAdcHits;
  vector<Int_t> fNumPosTdcHits;
  vector<Int_t> fNumNegTdcHits;

  vector<Int_t> fNumGoodPosAdcHits;
  vector<Int_t> fNumGoodNegAdcHits;
  vector<Int_t> fNumGoodPosTdcHits;
  vector<Int_t> fNumGoodNegTdcHits;

  // GOOD ADC variables
  vector<Double_t> fGoodPosAdcPed;
  vector<Double_t> fGoodNegAdcPed;

  vector<Double_t> fGoodPosAdcMult;
  vector<Double_t> fGoodNegAdcMult;

  vector<Double_t> fGoodPosAdcHitUsed;
  vector<Double_t> fGoodNegAdcHitUsed;

  vector<Double_t> fGoodPosAdcPulseInt;
  vector<Double_t> fGoodNegAdcPulseInt;

  vector<Double_t> fGoodPosAdcPulseAmp;
  vector<Double_t> fGoodNegAdcPulseAmp;

  vector<Double_t> fGoodPosAdcPulseTime;
  vector<Double_t> fGoodNegAdcPulseTime;

  vector<Double_t> fGoodPosAdcTdcDiffTime;
  vector<Double_t> fGoodNegAdcTdcDiffTime;

  vector<Double_t> fPosAdcSampWaveform;
  vector<Double_t> fNegAdcSampWaveform;

  // Hodoscopoe "GOOD" TDC Variables
  vector<Double_t> fGoodPosTdcTimeUnCorr;
  vector<Double_t> fGoodPosTdcTimeCorr;
  vector<Double_t> fGoodPosTdcTimeTOFCorr;

  vector<Double_t> fGoodNegTdcTimeUnCorr;
  vector<Double_t> fGoodNegTdcTimeCorr;
  vector<Double_t> fGoodNegTdcTimeTOFCorr;

  // Time Walk Corrected
  vector<Double_t> fGoodPosTdcTimeWalkCorr;
  vector<Double_t> fGoodNegTdcTimeWalkCorr;
  vector<Double_t> fGoodDiffDistTrack;

  vector<Double_t> fGoodHitTimeDiff; //FIXME: new for LADlib
  vector<Double_t> fGoodHitTimeAvg;  //FIXME: new for LADlib

  Int_t fDebugAdc;
  Double_t fPosTdcRefTime;
  Double_t fNegTdcRefTime;
  Double_t fPosTdcRefDiffTime;
  Double_t fNegTdcRefDiffTime;
  Double_t fPosAdcRefTime;
  Double_t fNegAdcRefTime;
  Double_t fPosAdcRefDiffTime;
  Double_t fNegAdcRefDiffTime;
  Double_t fHitDistance;
  Double_t fScinXPos;
  Double_t fScinYPos;
  Double_t fTrackXPosition;
  Double_t fTrackYPosition;
  Int_t fCosmicFlag;
  Int_t fPlaneNum;
  UInt_t fNelem;

  Int_t fNScinHits;     /* number of hits in plane (that pass min/max TDC cuts) */
  Int_t fNGoodHits;     /* number of hits in plane (used in determining focal plane time) */
  Int_t fNScinGoodHits; // number of hits for which both ends of the paddle fired in time 
 
  Int_t fADCMode;       // 0: standard, 1: use FADC ped, 2: integrate sample
                        // 3: integrate sample, subract dynamic pedestal
  
  enum { kADCStandard = 0, kADCDynamicPedestal, kADCSampleIntegral, kADCSampIntDynPed };

  Int_t fADCDiagCut;		  // Cut for ADC in hit maps.  Defaults to 50
  Int_t fTdcOffset;		    /* Overall offset to raw tdc */
  Double_t fAdcTdcOffset;	/* Overall offset to raw adc times */
  
  Int_t fOutputSampWaveform;
  Int_t fUseSampWaveform;
  Double_t fSampThreshold;
  Int_t fSampNSA;
  Int_t fSampNSAT;
  Int_t fSampNSB;
 
  Int_t fIsMC; 

  // Geometry parameters
  Double_t fSpacing; /* paddle spacing */
  Double_t fSize;    /* paddle size */
  Double_t fZpos;    /* z position */
  Double_t fDzpos;
  Double_t fHodoSlop;
  Double_t* fPosLeft;            /* NOTE: "left" = "bottom" for a Y scintillator */
  Double_t* fPosRight;           /* NOTE: "right" = "top" for a Y scintillator */
  Double_t fPosOffset;
  Double_t *fPosCenter;         /* array with centers for all scintillators in the plane */

  Double_t fScinTdcMin;
  Double_t fScinTdcMax;
  Double_t fStartTimeCenter;
  Double_t fStartTimeSlop;
  Double_t fScinTdcToTime;
  Double_t fTofTolerance;
  Double_t fBetaNominal;

  // Double_t *fHodoPosMinPh;	// Minimum pulse height per paddle for this plane
  // Double_t *fHodoNegMinPh;	// Minimum pulse height per paddle for this plane
  // Double_t *fHodoPosPhcCoeff;    // Pulse height to time coefficient per paddle for this plane
  // Double_t *fHodoNegPhcCoeff;    // Pulse height to time coefficient per paddlefor this plane
  // Double_t *fHodoPosTimeOffset;
  // Double_t *fHodoNegTimeOffset;
  Int_t fTofUsingInvAdc;
  Double_t *fHodoPosInvAdcOffset;
  Double_t *fHodoNegInvAdcOffset;
  Double_t *fHodoPosAdcTimeWindowMin;    
  Double_t *fHodoPosAdcTimeWindowMax;
  Double_t *fHodoNegAdcTimeWindowMin;    
  Double_t *fHodoNegAdcTimeWindowMax;
  Double_t *fHodoPosInvAdcLinear;
  Double_t *fHodoNegInvAdcLinear;
  Double_t *fHodoPosInvAdcAdc;
  Double_t *fHodoNegInvAdcAdc;

  // Time-Walk Parameters
  Double_t *fHodoVelFit;
  Double_t *fHodoCableFit;
  Double_t *fHodo_LCoeff;
  Double_t *fHodoPos_c1;
  Double_t *fHodoNeg_c1;
  Double_t *fHodoPos_c2;
  Double_t *fHodoNeg_c2;
  Double_t fTdc_Thrs;

  Double_t tw_corr_Pos;
  Double_t tw_corr_Neg;

  Double_t fTolerance; /* need this for Focal Plane Time estimation */
  Double_t fFptime;
 
  // Pedestal calculations
  Int_t fNPedestalEvents; /* Number of pedestal events */
  Int_t fMinPeds;         /* Only analyze/update if num events > */
  Int_t *fPosPedSum;      /* Accumulators for pedestals */
  Int_t *fPosPedSum2;
  Int_t *fPosPedLimit;
  Int_t *fPosPedCount;
  Int_t *fNegPedSum;
  Int_t *fNegPedSum2;
  Int_t *fNegPedLimit;
  Int_t *fNegPedCount;

  Double_t fTDC_match_window; 
  
  // Hodoscope Calib Parameters
  Double_t *fHodoVelLight;

  Double_t *fPosPed;
  Double_t *fPosThresh;
  Double_t *fNegPed;
  Double_t *fNegSig;
  Double_t *fNegThresh;

  Int_t        fEventType;
  Int_t        fEventNum;

  virtual Int_t ReadDatabase(const TDatime &date);
  virtual Int_t DefineVariables(EMode mode = kDefine);
  virtual void InitializePedestals();

  ClassDef(HYPScintillatorPlane, 0);
};

#endif 

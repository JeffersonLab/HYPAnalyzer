#include "HYPScintillatorPlane.h"
#include "THcGlobals.h"
#include "THcHitList.h"
#include "HYPScintHit.h"
#include "HYPScintDetector.h"
#include "THcParmList.h"
#include "THcRawAdcHit.h"
#include "THcRawTdcHit.h"
#include "THcSignalHit.h"

//_______________________________________________________________________________________
HYPScintillatorPlane::HYPScintillatorPlane(const char *name, const char *description, const Int_t planenum,
                                 THaDetectorBase *parent)
    : THaSubDetector(name, description, parent) {

  fPlaneNum      = planenum;
  fNScinHits     = 0;
  fNGoodHits     = 0;
  fNScinGoodHits = 0;
  
  fPosCenter = 0;
  fPosLeft = 0;
  fPosRight = 0;

  fHodoHits = new TClonesArray("HYPScintHit", 16);
  fCluster = new TClonesArray("THcScintPlaneCluster",10);

  frPosAdcErrorFlag = new TClonesArray("THcSignalHit", 16);
  frNegAdcErrorFlag = new TClonesArray("THcSignalHit", 16);

  frPosTdcHits = new TClonesArray("THcSignalHit", 16);
  frNegTdcHits = new TClonesArray("THcSignalHit", 16);
  frPosAdcHits = new TClonesArray("THcSignalHit", 16);
  frNegAdcHits = new TClonesArray("THcSignalHit", 16);
  frPosAdcSums = new TClonesArray("THcSignalHit", 16);
  frNegAdcSums = new TClonesArray("THcSignalHit", 16);
  frPosAdcPeds = new TClonesArray("THcSignalHit", 16);
  frNegAdcPeds = new TClonesArray("THcSignalHit", 16);

  frPosTdcTimeRaw      = new TClonesArray("THcSignalHit", 16);
  frPosAdcPedRaw       = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseIntRaw  = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseAmpRaw  = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseTimeRaw = new TClonesArray("THcSignalHit", 16);

  frPosTdcTime      = new TClonesArray("THcSignalHit", 16);
  frPosAdcPed       = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseInt  = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseAmp  = new TClonesArray("THcSignalHit", 16);
  frPosAdcPulseTime = new TClonesArray("THcSignalHit", 16);

  frNegTdcTimeRaw      = new TClonesArray("THcSignalHit", 16);
  frNegAdcPedRaw       = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseIntRaw  = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseAmpRaw  = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseTimeRaw = new TClonesArray("THcSignalHit", 16);

  frNegTdcTime      = new TClonesArray("THcSignalHit", 16);
  frNegAdcPed       = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseInt  = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseAmp  = new TClonesArray("THcSignalHit", 16);
  frNegAdcPulseTime = new TClonesArray("THcSignalHit", 16);

  frPosAdcSampPedRaw       = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseIntRaw  = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseAmpRaw  = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseTimeRaw = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPed          = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseInt     = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseAmp     = new TClonesArray("THcSignalHit", 16);
  frPosAdcSampPulseTime    = new TClonesArray("THcSignalHit", 16);

  frNegAdcSampPedRaw       = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseIntRaw  = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseAmpRaw  = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseTimeRaw = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPed          = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseInt     = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseAmp     = new TClonesArray("THcSignalHit", 16);
  frNegAdcSampPulseTime    = new TClonesArray("THcSignalHit", 16);
}

//_______________________________________________________________________________________
HYPScintillatorPlane::~HYPScintillatorPlane() 
{
  // destructor
  if (fIsSetup)
    RemoveVariables();

  delete frPosAdcErrorFlag;
  frPosAdcErrorFlag = nullptr;
  delete frNegAdcErrorFlag;
  frNegAdcErrorFlag = nullptr;

  delete fCluster; fCluster = nullptr;

  delete fHodoHits;
  delete frPosTdcHits;
  delete frNegTdcHits;
  delete frPosAdcHits;
  delete frNegAdcHits;
  delete frPosAdcSums;
  delete frNegAdcSums;
  delete frPosAdcPeds;
  delete frNegAdcPeds;

  delete frPosTdcTimeRaw;
  delete frPosAdcPedRaw;
  delete frPosAdcPulseIntRaw;
  delete frPosAdcPulseAmpRaw;
  delete frPosAdcPulseTimeRaw;

  delete frPosTdcTime;
  delete frPosAdcPed;
  delete frPosAdcPulseInt;
  delete frPosAdcPulseAmp;
  delete frPosAdcPulseTime;

  delete frNegTdcTimeRaw;
  delete frNegAdcPedRaw;
  delete frNegAdcPulseIntRaw;
  delete frNegAdcPulseAmpRaw;
  delete frNegAdcPulseTimeRaw;

  delete frNegTdcTime;
  delete frNegAdcPed;
  delete frNegAdcPulseInt;
  delete frNegAdcPulseAmp;
  delete frNegAdcPulseTime;

  delete frPosAdcSampPedRaw;  frPosAdcSampPedRaw = nullptr;
  delete frPosAdcSampPulseIntRaw;  frPosAdcSampPulseIntRaw = nullptr;
  delete frPosAdcSampPulseAmpRaw;  frPosAdcSampPulseAmpRaw = nullptr;
  delete frPosAdcSampPulseTimeRaw;  frPosAdcSampPulseTimeRaw = nullptr;
  delete frPosAdcSampPed;  frPosAdcSampPed = nullptr;
  delete frPosAdcSampPulseInt;  frPosAdcSampPulseInt = nullptr;
  delete frPosAdcSampPulseAmp;  frPosAdcSampPulseAmp = nullptr;
  delete frPosAdcSampPulseTime;  frPosAdcSampPulseTime = nullptr;

  delete frNegAdcSampPedRaw;  frNegAdcSampPedRaw = nullptr;
  delete frNegAdcSampPulseIntRaw;  frNegAdcSampPulseIntRaw = nullptr;
  delete frNegAdcSampPulseAmpRaw;  frNegAdcSampPulseAmpRaw = nullptr;
  delete frNegAdcSampPulseTimeRaw;  frNegAdcSampPulseTimeRaw = nullptr;
  delete frNegAdcSampPed;  frNegAdcSampPed = nullptr;
  delete frNegAdcSampPulseInt;  frNegAdcSampPulseInt = nullptr;
  delete frNegAdcSampPulseAmp;  frNegAdcSampPulseAmp = nullptr;
  delete frNegAdcSampPulseTime;  frNegAdcSampPulseTime = nullptr;

  delete[] fPosPedSum;
  fPosPedSum = 0;
  delete[] fPosPedSum2;
  fPosPedSum2 = 0;
  delete[] fPosPedLimit;
  fPosPedLimit = 0;
  delete[] fPosPedCount;
  fPosPedCount = 0;
  delete[] fNegPedSum;
  fNegPedSum = 0;
  delete[] fNegPedSum2;
  fNegPedSum2 = 0;
  delete[] fNegPedLimit;
  fNegPedLimit = 0;
  delete[] fNegPedCount;
  fNegPedCount = 0;
  delete[] fPosPed;
  fPosPed = 0;
  delete[] fNegPed;
  fNegPed = 0;
  delete[] fPosThresh;
  fPosThresh = 0;
  delete[] fNegThresh;
  fNegThresh = 0;

  delete[] fPosCenter;
  fPosCenter = 0;
  delete[] fPosLeft;
  fPosLeft = 0;  
  delete[] fPosRight;
  fPosRight = 0;

  delete[] fHodoPosAdcTimeWindowMax;
  fHodoPosAdcTimeWindowMax = nullptr;
  delete[] fHodoPosAdcTimeWindowMin;
  fHodoPosAdcTimeWindowMin = nullptr;
  delete[] fHodoNegAdcTimeWindowMax;
  fHodoNegAdcTimeWindowMax = nullptr;
  delete[] fHodoNegAdcTimeWindowMin;
  fHodoNegAdcTimeWindowMin = nullptr;
  delete[] fHodoVelFit;
  fHodoVelFit = nullptr;
  delete[] fHodoCableFit;
  fHodoCableFit = nullptr;
  delete[] fHodo_LCoeff;
  fHodo_LCoeff = nullptr;
  delete[] fHodoPos_c1;
  fHodoPos_c1 = nullptr;
  delete[] fHodoNeg_c1;
  fHodoNeg_c1 = nullptr;
  delete[] fHodoPos_c2;
  fHodoPos_c2 = nullptr;
  delete[] fHodoNeg_c2;
  fHodoNeg_c2 = nullptr;

  delete[] fHodoVelLight;
  fHodoVelLight = nullptr;
 
}

//_______________________________________________________________________________________
THaAnalysisObject::EStatus HYPScintillatorPlane::Init(const TDatime &date) {

  if (IsZombie())
    return fStatus = kInitError;

  EStatus status;
  if ((status = THaSubDetector::Init(date)))
    return fStatus = status;
  return fStatus = kOK;
}

//_______________________________________________________________________________________
void HYPScintillatorPlane::Clear(Option_t *opt) {

  fHodoHits->Clear();
  fCluster->Clear();

  frPosAdcErrorFlag->Clear();
  frNegAdcErrorFlag->Clear();

  frPosTdcHits->Clear();
  frNegTdcHits->Clear();
  frPosAdcHits->Clear();
  frNegAdcHits->Clear();

  frPosTdcTimeRaw->Clear();
  frPosAdcPedRaw->Clear();
  frPosAdcPulseIntRaw->Clear();
  frPosAdcPulseAmpRaw->Clear();
  frPosAdcPulseTimeRaw->Clear();

  frPosTdcTime->Clear();
  frPosAdcPed->Clear();
  frPosAdcPulseInt->Clear();
  frPosAdcPulseAmp->Clear();
  frPosAdcPulseTime->Clear();

  frPosAdcSampPedRaw->Clear();
  frPosAdcSampPulseIntRaw->Clear();
  frPosAdcSampPulseAmpRaw->Clear();
  frPosAdcSampPulseTimeRaw->Clear();
  frPosAdcSampPed->Clear();
  frPosAdcSampPulseInt->Clear();
  frPosAdcSampPulseAmp->Clear();
  frPosAdcSampPulseTime->Clear();

  frNegTdcTimeRaw->Clear();
  frNegAdcPedRaw->Clear();
  frNegAdcPulseIntRaw->Clear();
  frNegAdcPulseAmpRaw->Clear();
  frNegAdcPulseTimeRaw->Clear();

  frNegTdcTime->Clear();
  frNegAdcPed->Clear();
  frNegAdcPulseInt->Clear();
  frNegAdcPulseAmp->Clear();
  frNegAdcPulseTime->Clear();

  frNegAdcSampPedRaw->Clear();
  frNegAdcSampPulseIntRaw->Clear();
  frNegAdcSampPulseAmpRaw->Clear();
  frNegAdcSampPulseTimeRaw->Clear();
  frNegAdcSampPed->Clear();
  frNegAdcSampPulseInt->Clear();
  frNegAdcSampPulseAmp->Clear();
  frNegAdcSampPulseTime->Clear();

  // Clear occupancies
  for (UInt_t ielem = 0; ielem < fNumGoodPosAdcHits.size(); ielem++)
  fNumGoodPosAdcHits.at(ielem) = 0;
  for (UInt_t ielem = 0; ielem < fNumGoodNegAdcHits.size(); ielem++)
  fNumGoodNegAdcHits.at(ielem) = 0;

  for (UInt_t ielem = 0; ielem < fNumGoodPosTdcHits.size(); ielem++)
  fNumGoodPosTdcHits.at(ielem) = 0;
  for (UInt_t ielem = 0; ielem < fNumGoodNegTdcHits.size(); ielem++)
  fNumGoodNegTdcHits.at(ielem) = 0;

  for (UInt_t ielem = 0; ielem < fNumPosAdcHits.size(); ielem++)
    fNumPosAdcHits.at(ielem) = 0;
  for (UInt_t ielem = 0; ielem < fNumNegAdcHits.size(); ielem++)
    fNumNegAdcHits.at(ielem) = 0;
  for (UInt_t ielem = 0; ielem < fNumPosTdcHits.size(); ielem++)
    fNumPosTdcHits.at(ielem) = 0;
  for (UInt_t ielem = 0; ielem < fNumNegTdcHits.size(); ielem++)
    fNumNegTdcHits.at(ielem) = 0;
 
  // Clear Ped/Amps/Int/Time
  for (UInt_t ielem = 0; ielem < fGoodPosAdcPed.size(); ielem++) {
    fGoodPosAdcPed.at(ielem)         = 0.0;
    fGoodPosAdcMult.at(ielem)        = 0.0;
    fGoodPosAdcHitUsed.at(ielem)     = 0.0;
    fGoodPosAdcPulseInt.at(ielem)    = 0.0;
    fGoodPosAdcPulseAmp.at(ielem)    = 0.0;
    fGoodPosAdcPulseTime.at(ielem)   = kBig;
    fGoodPosAdcTdcDiffTime.at(ielem) = kBig;
  }
  for (UInt_t ielem = 0; ielem < fGoodNegAdcPed.size(); ielem++) {
    fGoodNegAdcPed.at(ielem)         = 0.0;
    fGoodNegAdcMult.at(ielem)        = 0.0;
    fGoodNegAdcHitUsed.at(ielem)     = 0.0;
    fGoodNegAdcPulseInt.at(ielem)    = 0.0;
    fGoodNegAdcPulseAmp.at(ielem)    = 0.0;
    fGoodNegAdcPulseTime.at(ielem)   = kBig;
    fGoodNegAdcTdcDiffTime.at(ielem) = kBig;
  }

  // Clear Good TDC Variables
  for (UInt_t ielem = 0; ielem < fGoodPosTdcTimeUnCorr.size(); ielem++) {
    fGoodPosTdcTimeUnCorr.at(ielem)   = kBig;
    fGoodPosTdcTimeCorr.at(ielem)     = kBig;
    fGoodPosTdcTimeTOFCorr.at(ielem)  = kBig;
    fGoodPosTdcTimeWalkCorr.at(ielem) = kBig;
  }

  for (UInt_t ielem = 0; ielem < fGoodNegTdcTimeUnCorr.size(); ielem++) {
    fGoodNegTdcTimeUnCorr.at(ielem)   = kBig;
    fGoodNegTdcTimeCorr.at(ielem)     = kBig;
    fGoodNegTdcTimeTOFCorr.at(ielem)  = kBig;
    fGoodNegTdcTimeWalkCorr.at(ielem) = kBig;
  }

  for (UInt_t ielem = 0; ielem < fGoodDiffDistTrack.size(); ielem++) {
    fGoodDiffDistTrack.at(ielem) = kBig;
    fGoodHitTimeDiff.at(ielem)   = kBig; // FIXME: LAD variable
    fGoodHitTimeAvg.at(ielem)    = kBig;
  }

  fHitDistance    = kBig;
  fScinYPos       = kBig;
  fScinXPos       = kBig;
  fTrackXPosition = kBig;
  fTrackYPosition = kBig;

  // Ref time
  fPosTdcRefTime     = kBig;
  fPosAdcRefTime     = kBig;
  fNegTdcRefTime     = kBig;
  fNegAdcRefTime     = kBig;
  fPosTdcRefDiffTime = kBig;
  fPosAdcRefDiffTime = kBig;
  fNegTdcRefDiffTime = kBig;
  fNegAdcRefDiffTime = kBig;

  // Waveform vectors
  fPosAdcSampWaveform.clear();
  fNegAdcSampWaveform.clear();

  // Adc good hits
  fTotNumGoodPosAdcHits = 0;
  fTotNumGoodNegAdcHits = 0;
  fTotNumGoodAdcHits    = 0;

  fTotNumPosAdcHits = 0;
  fTotNumNegAdcHits = 0;
  fTotNumAdcHits    = 0;

  // Tdc good hits
  fTotNumGoodPosTdcHits = 0;
  fTotNumGoodNegTdcHits = 0;
  fTotNumGoodTdcHits    = 0;

  fTotNumPosTdcHits = 0;
  fTotNumNegTdcHits = 0;
  fTotNumTdcHits    = 0;

  fNScinHits     = 0;
  fNGoodHits     = 0; // FIXME: looks like not being used.. remove it?
  fNScinGoodHits = 0; // FIXME: looks like not being used.. remove it?
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::Decode(const THaEvData &evdata) {
  // Leave it to do nothing

  return 0;
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::ReadDatabase(const TDatime &date) {

  // Read database files as needed here
  char prefix[2];
  prefix[0] = tolower(GetParent()->GetPrefix()[0]);
  prefix[1] = '\0';

  // Get # of element for each hodo detector
  string parname     = "scin_" + string(GetName()) + "_nr";
  DBRequest list_1[] = {{parname.c_str(), &fNelem, kInt}, {0}};
  gHcParms->LoadParmValues(list_1, prefix);

  delete[] fPosCenter;
  fPosCenter = new Double_t[fNelem];
  delete[] fPosLeft;
  fPosLeft = new Double_t[fNelem];
  delete[] fPosRight;
  fPosRight = new Double_t[fNelem];

  DBRequest list[] = {{Form("scin_%s_zpos", GetName()), &fZpos, kDouble},
                      {Form("scin_%s_dzpos", GetName()), &fDzpos, kDouble},
                      {Form("scin_%s_size", GetName()), &fSize, kDouble},
                      {Form("scin_%s_spacing", GetName()), &fSpacing, kDouble},
                      {Form("scin_%s_%s", GetName(), "Neg"), fPosLeft, kDouble,  fNelem},
                      {Form("scin_%s_%s", GetName(), "Pos"), fPosRight, kDouble, fNelem},
                      {Form("scin_%s_offset", GetName()), &fPosOffset, kDouble},
                      {Form("scin_%s_center", GetName()), fPosCenter, kDouble, fNelem},
                      {"scin_adc_mode", &fADCMode, kInt, 0, 1},
                      {"scin_adc_diag_cut", &fADCDiagCut, kInt, 0, 1},
                      {"cosmicflag", &fCosmicFlag, kInt, 0, 1},
                      {"scin_debug_adc", &fDebugAdc, kInt, 0, 1},
                      {"scin_SampThreshold", &fSampThreshold, kDouble, 0, 1},
                      {"scin_SampNSA", &fSampNSA, kInt, 0, 1},
                      {"scin_SampNSAT", &fSampNSAT, kInt, 0, 1},
                      {"scin_SampNSB", &fSampNSB, kInt, 0, 1},
                      {"scin_OutputSampWaveform", &fOutputSampWaveform, kInt, 0, 1},
                      {"scin_UseSampWaveform", &fUseSampWaveform, kInt, 0, 1},
                      {"scin_TDC_match_window", &fTDC_match_window, kDouble, 0, 1},
                      {0}};

  // Set Default values
  fDebugAdc           = 0; // Set ADC debug parameter to false unless set in parameter file
  fADCMode            = kADCDynamicPedestal;
  fADCDiagCut         = 50.0;
  fCosmicFlag         = 0;
  fSampThreshold      = 5.;
  fSampNSA            = 0;  // use value stored in event 125 info
  fSampNSB            = 0;  // use value stored in event 125 info
  fSampNSAT           = 2;  // default value in THcRawHit::SetF250Params
  fOutputSampWaveform = 0;  // 0= no output , 1 = output Sample Waveform
  fUseSampWaveform    = 0;  // 0= do not use , 1 = use Sample Waveform
  fTDC_match_window   = 50; //

  gHcParms->LoadParmValues((DBRequest *)&list, prefix);

  DBRequest list5[] = {{"is_mc", &fIsMC, kInt, 0, 1}, {0}};
  fIsMC             = 0;
  gHcParms->LoadParmValues((DBRequest *)&list5, "");

  if (fCosmicFlag == 1)
    cout << " setup for cosmics in scint plane" << endl;

  // Retrieve parameters we need from parent class
  // Common for all planes
  HYPScintDetector *parent = (HYPScintDetector *)GetParent();

  fHodoSlop      = parent->GetHodoSlop(fPlaneNum - 1);
  fTdcOffset     = parent->GetTdcOffset(fPlaneNum - 1);
  fAdcTdcOffset  = parent->GetAdcTdcOffset(fPlaneNum - 1);
  fScinTdcMin    = parent->GetTdcMin();
  fScinTdcMax    = parent->GetTdcMax();
  fScinTdcToTime = parent->GetTdcToTime();

  // Parameters for this plane
  fHodoPosAdcTimeWindowMin = new Double_t[fNelem];
  fHodoNegAdcTimeWindowMin = new Double_t[fNelem];
  fHodoPosAdcTimeWindowMax = new Double_t[fNelem];
  fHodoNegAdcTimeWindowMax = new Double_t[fNelem];

  fHodoVelLight = new Double_t[fNelem];

  // New Time-Walk Calibration Parameters
  fHodoVelFit   = new Double_t[fNelem];
  fHodoCableFit = new Double_t[fNelem];
  fHodo_LCoeff  = new Double_t[fNelem];
  fHodoPos_c1   = new Double_t[fNelem];
  fHodoNeg_c1   = new Double_t[fNelem];
  fHodoPos_c2   = new Double_t[fNelem];
  fHodoNeg_c2   = new Double_t[fNelem];

  for (Int_t j = 0; j < (Int_t)fNelem; j++) {
    Int_t index                 = parent->GetScinIndex(fPlaneNum - 1, j);
    fHodoPosAdcTimeWindowMin[j] = parent->GetHodoPosAdcTimeWindowMin(index);
    fHodoPosAdcTimeWindowMax[j] = parent->GetHodoPosAdcTimeWindowMax(index);
    fHodoNegAdcTimeWindowMin[j] = parent->GetHodoNegAdcTimeWindowMin(index);
    fHodoNegAdcTimeWindowMax[j] = parent->GetHodoNegAdcTimeWindowMax(index);

    fHodoVelLight[j] = parent->GetHodoVelLight(index);

    // Get Time-Walk correction param
    fHodoVelFit[j]   = parent->GetHodoVelFit(index);
    fHodoCableFit[j] = parent->GetHodoCableFit(index);
    fHodo_LCoeff[j]  = parent->GetHodoLCoeff(index);
    fHodoPos_c1[j]   = parent->GetHodoPos_c1(index);
    fHodoNeg_c1[j]   = parent->GetHodoNeg_c1(index);
    fHodoPos_c2[j]   = parent->GetHodoPos_c2(index);
    fHodoNeg_c2[j]   = parent->GetHodoNeg_c2(index);
  }

  fTdc_Thrs = parent->GetTDCThrs();

  // Create arrays to hold results here
  InitializePedestals();

  // Initialize
  fNumPosAdcHits = vector<Int_t>(fNelem, 0.0);
  fNumNegAdcHits = vector<Int_t>(fNelem, 0.0);
  fNumPosTdcHits = vector<Int_t>(fNelem, 0.0);
  fNumNegTdcHits = vector<Int_t>(fNelem, 0.0);

  fNumGoodPosAdcHits = vector<Int_t>(fNelem, 0.0);
  fNumGoodNegAdcHits = vector<Int_t>(fNelem, 0.0);
  fNumGoodPosTdcHits = vector<Int_t>(fNelem, 0.0);
  fNumGoodNegTdcHits = vector<Int_t>(fNelem, 0.0);

  fGoodPosAdcPed         = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcPed         = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcMult        = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcMult        = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcHitUsed     = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcHitUsed     = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcPulseAmp    = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcPulseAmp    = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcPulseInt    = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcPulseInt    = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcPulseTime   = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcPulseTime   = vector<Double_t>(fNelem, 0.0);
  fGoodPosAdcTdcDiffTime = vector<Double_t>(fNelem, 0.0);
  fGoodNegAdcTdcDiffTime = vector<Double_t>(fNelem, 0.0);

  fGoodPosTdcTimeUnCorr   = vector<Double_t>(fNelem, 0.0);
  fGoodNegTdcTimeUnCorr   = vector<Double_t>(fNelem, 0.0);
  fGoodPosTdcTimeCorr     = vector<Double_t>(fNelem, 0.0);
  fGoodNegTdcTimeCorr     = vector<Double_t>(fNelem, 0.0);
  fGoodPosTdcTimeTOFCorr  = vector<Double_t>(fNelem, 0.0);
  fGoodNegTdcTimeTOFCorr  = vector<Double_t>(fNelem, 0.0);
  fGoodPosTdcTimeWalkCorr = vector<Double_t>(fNelem, 0.0);
  fGoodNegTdcTimeWalkCorr = vector<Double_t>(fNelem, 0.0);
  fGoodDiffDistTrack      = vector<Double_t>(fNelem, 0.0);
  fGoodHitTimeDiff        = vector<Double_t>(fNelem, 0.0);
  fGoodHitTimeAvg         = vector<Double_t>(fNelem, 0.0);

  return 0;
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::DefineVariables(EMode mode) {

  /*
    Initialize global variables for histograms and Root tree
  */

  if (mode == kDefine && fIsSetup)
    return kOK;
  fIsSetup = (mode == kDefine);

  // Register variables in global list

  if (fDebugAdc) {
    RVarDef vars[] = {
        {"PosAdcErrorFlag", "Error Flag for When FPGA Fails", "frPosAdcErrorFlag.THcSignalHit.GetData()"},
        {"NegAdcErrorFlag", "Error Flag for When FPGA Fails", "frNegAdcErrorFlag.THcSignalHit.GetData()"},

        {"PosTdcTimeRaw", "List of Pos raw TDC values.", "frPosTdcTimeRaw.THcSignalHit.GetData()"},
        {"PosAdcPedRaw", "List of Pos raw ADC pedestals", "frPosAdcPedRaw.THcSignalHit.GetData()"},
        {"PosAdcPulseIntRaw", "List of Pos raw ADC pulse integrals.", "frPosAdcPulseIntRaw.THcSignalHit.GetData()"},
        {"PosAdcPulseAmpRaw", "List of Pos raw ADC pulse amplitudes.", "frPosAdcPulseAmpRaw.THcSignalHit.GetData()"},
        {"PosAdcPulseTimeRaw", "List of Pos raw ADC pulse times.", "frPosAdcPulseTimeRaw.THcSignalHit.GetData()"},

        {"PosTdcTime", "List of Pos TDC values.", "frPosTdcTime.THcSignalHit.GetData()"},
        {"PosAdcPed", "List of Pos ADC pedestals", "frPosAdcPed.THcSignalHit.GetData()"},
        {"PosAdcPulseInt", "List of Pos ADC pulse integrals.", "frPosAdcPulseInt.THcSignalHit.GetData()"},
        {"PosAdcPulseAmp", "List of Pos ADC pulse amplitudes.", "frPosAdcPulseAmp.THcSignalHit.GetData()"},
        {"PosAdcPulseTime", "List of Pos ADC pulse times.", "frPosAdcPulseTime.THcSignalHit.GetData()"},

        {"PosAdcSampPedRaw", "Pos Raw Samp ADC pedestals", "frPosAdcSampPedRaw.THcSignalHit.GetData()"},
        {"PosAdcSampPulseIntRaw", "Pos Raw Samp ADC pulse integrals", "frPosAdcSampPulseIntRaw.THcSignalHit.GetData()"},
        {"PosAdcSampPulseAmpRaw", "Pos Raw Samp ADC pulse amplitudes",
         "frPosAdcSampPulseAmpRaw.THcSignalHit.GetData()"},
        {"PosAdcSampPulseTimeRaw", "Pos Raw Samp ADC pulse times", "frPosAdcSampPulseTimeRaw.THcSignalHit.GetData()"},
        {"PosAdcSampPed", "Pos Samp ADC pedestals", "frPosAdcSampPed.THcSignalHit.GetData()"},
        {"PosAdcSampPulseInt", "Pos Samp ADC pulse integrals", "frPosAdcSampPulseInt.THcSignalHit.GetData()"},
        {"PosAdcSampPulseAmp", "Pos Samp ADC pulse amplitudes", "frPosAdcSampPulseAmp.THcSignalHit.GetData()"},
        {"PosAdcSampPulseTime", "Pos Samp ADC pulse times", "frPosAdcSampPulseTime.THcSignalHit.GetData()"},

        {"NegTdcTimeRaw", "List of bottom raw TDC values.", "frNegTdcTimeRaw.THcSignalHit.GetData()"},
        {"NegAdcPedRaw", "List of bottom raw ADC pedestals", "frNegAdcPedRaw.THcSignalHit.GetData()"},
        {"NegAdcPulseIntRaw", "List of bottom raw ADC pulse integrals.", "frNegAdcPulseIntRaw.THcSignalHit.GetData()"},
        {"NegAdcPulseAmpRaw", "List of bottom raw ADC pulse amplitudes.", "frNegAdcPulseAmpRaw.THcSignalHit.GetData()"},
        {"NegAdcPulseTimeRaw", "List of bottom raw ADC pulse times.", "frNegAdcPulseTimeRaw.THcSignalHit.GetData()"},

        {"NegTdcTime", "List of bottom TDC values.", "frNegTdcTime.THcSignalHit.GetData()"},
        {"NegAdcPed", "List of bottom ADC pedestals", "frNegAdcPed.THcSignalHit.GetData()"},
        {"NegAdcPulseInt", "List of bottom ADC pulse integrals.", "frNegAdcPulseInt.THcSignalHit.GetData()"},
        {"NegAdcPulseAmp", "List of bottom ADC pulse amplitudes.", "frNegAdcPulseAmp.THcSignalHit.GetData()"},
        {"NegAdcPulseTime", "List of bottom ADC pulse times.", "frNegAdcPulseTime.THcSignalHit.GetData()"},

        {"NegAdcSampPedRaw", "Bottom Raw Samp ADC pedestals", "frNegAdcSampPedRaw.THcSignalHit.GetData()"},
        {"NegAdcSampPulseIntRaw", "Bottom Raw Samp ADC pulse integrals",
         "frNegAdcSampPulseIntRaw.THcSignalHit.GetData()"},
        {"NegAdcSampPulseAmpRaw", "Bottom Raw Samp ADC pulse amplitudes",
         "frNegAdcSampPulseAmpRaw.THcSignalHit.GetData()"},
        {"NegAdcSampPulseTimeRaw", "Bottom Raw Samp ADC pulse times",
         "frNegAdcSampPulseTimeRaw.THcSignalHit.GetData()"},
        {"NegAdcSampPed", "Bottom Samp ADC pedestals", "frNegAdcSampPed.THcSignalHit.GetData()"},
        {"NegAdcSampPulseInt", "Bottom Samp ADC pulse integrals", "frNegAdcSampPulseInt.THcSignalHit.GetData()"},
        {"NegAdcSampPulseAmp", "Bottom Samp ADC pulse amplitudes", "frNegAdcSampPulseAmp.THcSignalHit.GetData()"},
        {"NegAdcSampPulseTime", "Bottom Samp ADC pulse times", "frNegAdcSampPulseTime.THcSignalHit.GetData()"},

        {"numPosAdcHits", "Number of Pos ADC Hits Per PMT", "fNumPosAdcHits"}, // Hodo+ ADC occupancy - vector<Int_t>
        {"numNegAdcHits", "Number of Bottom ADC Hits Per PMT",
         "fNumNegAdcHits"}, // Hodo- ADC occupancy - vector <Int_t>

        {"numPosTdcHits", "Number of Pos TDC Hits Per PMT", "fNumPosTdcHits"}, // Hodo+ TDC occupancy - vector<Int_t>
        {"numNegTdcHits", "Number of Bottom TDC Hits Per PMT",
         "fNumNegTdcHits"}, // Hodo- TDC occupancy - vector <Int_t>

        {"totNumPosAdcHits", "Total Number of Pos ADC Hits", "fTotNumPosAdcHits"}, // Hodo+ raw ADC multiplicity Int_t
        {"totNumNegAdcHits", "Total Number of Bottom ADC Hits", "fTotNumNegAdcHits"}, // Hodo- raw ADC multiplicity ""
        {"totNumAdcHits", "Total Number of PMTs Hit (as measured by ADCs)",
         "fTotNumAdcHits"}, // Hodo raw ADC multiplicity  ""

        {"totNumPosTdcHits", "Total Number of Pos TDC Hits", "fTotNumPosTdcHits"},    // Hodo+ raw TDC multiplicity ""
        {"totNumNegTdcHits", "Total Number of Bottom TDC Hits", "fTotNumNegTdcHits"}, // Hodo- raw TDC multiplicity ""
        {"totNumTdcHits", "Total Number of PMTs Hits (as measured by TDCs)",
         "fTotNumTdcHits"}, // Hodo raw TDC multiplicity  ""
        {0}};
    DefineVarsFromList(vars, mode);
  } // end debug statement

  if (fOutputSampWaveform == 1) {
    RVarDef vars[] = {{"adcNegSampWaveform", "FADC Neg ADCSample Waveform", "fNegAdcSampWaveform"},
                      {"adcPosSampWaveform", "FADC Pos ADCSample Waveform", "fPosAdcSampWaveform"},
                      {0}};
    DefineVarsFromList(vars, mode);
  }

  RVarDef vars[] = {
      {"nhits", "Number of paddle hits (passed TDC && ADC Min and Max cuts for either end)", "GetNScinHits() "},

      {"PosTdcCounter", "List of Pos TDC counter numbers.",
       "frPosTdcTimeRaw.THcSignalHit.GetPaddleNumber()"}, // Hodo+ raw TDC occupancy
      {"PosAdcCounter", "List of Pos ADC counter numbers.",
       "frPosAdcPulseIntRaw.THcSignalHit.GetPaddleNumber()"}, // Hodo+ raw ADC occupancy
      {"NegTdcCounter", "List of bottom TDC counter numbers.",
       "frNegTdcTimeRaw.THcSignalHit.GetPaddleNumber()"}, // Hodo- raw TDC occupancy
      {"NegAdcCounter", "List of bottom ADC counter numbers.",
       "frNegAdcPulseIntRaw.THcSignalHit.GetPaddleNumber()"}, // Hodo- raw ADC occupancy

      {"numGoodPosAdcHits", "Number of Good Pos ADC Hits Per PMT",
       "fNumGoodPosAdcHits"}, // Hodo+ good ADC occupancy - vector<Int_t>
      {"numGoodNegAdcHits", "Number of Good Bottom ADC Hits Per PMT",
       "fNumGoodNegAdcHits"}, // Hodo- good ADC occupancy - vector <Int_t>

      {"numGoodPosTdcHits", "Number of Good Pos TDC Hits Per PMT",
       "fNumGoodPosTdcHits"}, // Hodo+ good TDC occupancy - vector<Int_t>
      {"numGoodNegTdcHits", "Number of Good Bottom TDC Hits Per PMT",
       "fNumGoodNegTdcHits"}, // Hodo- good TDC occupancy - vector <Int_t>

      {"totNumGoodPosAdcHits", "Total Number of Good Pos ADC Hits",
       "fTotNumGoodPosAdcHits"}, // Hodo+ good ADC multiplicity - Int_t
      {"totNumGoodNegAdcHits", "Total Number of Good Bottom ADC Hits",
       "fTotNumGoodNegAdcHits"}, // Hodo- good ADC multiplicity - Int_t
      {"totNumGoodAdcHits", "TotalNumber of Good ADC Hits Per PMT",
       "fTotNumGoodAdcHits"}, // Hodo good ADC multiplicity - Int_t

      {"totNumGoodPosTdcHits", "Total Number of Good Pos TDC Hits",
       "fTotNumGoodPosTdcHits"}, // Hodo+ good TDC multiplicity - Int_t
      {"totNumGoodNegTdcHits", "Total Number of Good Bottom TDC Hits",
       "fTotNumGoodNegTdcHits"}, // Hodo- good TDC multiplicity - Int_t
      {"totNumGoodTdcHits", "TotalNumber of Good TDC Hits Per PMT",
       "fTotNumGoodTdcHits"}, // Hodo good TDC multiplicity - Int_t

      {"GoodPosAdcPed", "List of Pos ADC pedestals (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcPed"}, // vector<Double_t>
      {"GoodNegAdcPed", "List of Bottom ADC pedestals (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcPed"}, // vector<Double_t>
      {"GoodPosAdcMult", "List of Pos ADC Mult (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcMult"}, // vector<Double_t>
      {"GoodNegAdcMult", "List of Bottom ADC Mult (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcMult"}, // vector<Double_t>
      {"GoodPosAdcHitUsed", "List of Pos ADC Hit Used (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcHitUsed"}, // vector<Double_t>
      {"GoodNegAdcHitUsed", "List of Bottom ADC Hit Used (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcHitUsed"}, // vector<Double_t>

      {"GoodPosAdcPulseInt", "List of Pos ADC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcPulseInt"},
      {"GoodNegAdcPulseInt", "List of Bottom ADC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcPulseInt"},
      {"GoodPosAdcPulseAmp", "List of Pos ADC peak amp (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcPulseAmp"},
      {"GoodNegAdcPulseAmp", "List of Bottom ADC peak amp (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcPulseAmp"},
      {"GoodPosAdcPulseTime", "List of Pos ADC time (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcPulseTime"},
      {"GoodNegAdcPulseTime", "List of Bottom ADC time (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcPulseTime"},
      {"GoodPosAdcTdcDiffTime", "List of Pos TDC - ADC time (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosAdcTdcDiffTime"},
      {"GoodNegAdcTdcDiffTime", "List of Bottom TDC - ADC time (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegAdcTdcDiffTime"},

      {"GoodPosTdcTimeUnCorr", "List of Pos TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosTdcTimeUnCorr"},
      {"GoodNegTdcTimeUnCorr", "List of bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegTdcTimeUnCorr"},
      {"GoodPosTdcTimeCorr", "List of Pos TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosTdcTimeCorr"},
      {"GoodNegTdcTimeCorr", "List of bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegTdcTimeCorr"},
      {"GoodPosTdcTimeTOFCorr", "List of Pos TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosTdcTimeTOFCorr"},
      {"GoodNegTdcTimeTOFCorr", "List of bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegTdcTimeTOFCorr"},
      {"GoodPosTdcTimeWalkCorr", "List of Pos TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodPosTdcTimeWalkCorr"},
      {"GoodNegTdcTimeWalkCorr", "List of bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodNegTdcTimeWalkCorr"},
      {"GoodDiffDistTrack", "List of Pos-bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodDiffDistTrack"},
      {"GoodHitTimeDiff", "List of Pos-bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodHitTimeDiff"},
      {"GoodHitTimeAvg", "List of Pos-bottom TDC values (passed TDC && ADC Min and Max cuts for either end)",
       "fGoodHitTimeAvg"},
      {"PosTdcRefTime", "Reference time of Pos TDC", "fPosTdcRefTime"},
      {"NegTdcRefTime", "Reference time of Neg TDC", "fNegTdcRefTime"},
      {"PosAdcRefTime", "Reference time of Pos ADC", "fPosAdcRefTime"},
      {"NegAdcRefTime", "Reference time of Neg aDC", "fNegAdcRefTime"},
      {"PosTdcRefDiffTime", "Reference Diff time of Pos TDC", "fPosTdcRefDiffTime"},
      {"NegTdcRefDiffTime", "Reference Diff time of Neg TDC", "fNegTdcRefDiffTime"},
      {"PosAdcRefDiffTime", "Reference Diff time of Pos ADC", "fPosAdcRefDiffTime"},
      {"NegAdcRefDiffTime", "Reference Diff time of Neg aDC", "fNegAdcRefDiffTime"},
      {0}};
  DefineVarsFromList(vars, mode);

  // Full Hodohit variables
  RVarDef vars2[] = {
      {"nFullHodoHits", "List of HodoHit objects", "fNScinHits"},
      {"HodoHitTime", "List of HodoHit times", "fHodoHits.HYPScintHit.GetScinCorrectedTime()"},
      {"HodoHitPaddleNum", "List of HodoHit paddle numbers", "fHodoHits.HYPScintHit.GetPaddleNumber()"},
      {"HodoHitPos", "List of HodoHit positions on bar", "fHodoHits.HYPScintHit.GetCalcPosition()"},
      {"HodoHitEdep", "List of HodoHit energy depositions", "fHodoHits.HYPScintHit.GetPaddleADC()"},
      {"HodoHitisFull", "List of Bool's specifing if hit has Pos and Neg hodo hits",
       "fHodoHits.HYPScintHit.GetHasCorrectedTimes()"},
      {0}};

  return DefineVarsFromList(vars2, mode);
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::ProcessHits(TClonesArray *rawhits, Int_t nexthit) {

  /*! \brief Extract scintillator paddle hits from raw data starting at "nexthit"
   * - Called by THcHodoscope::Decode
   * - Loops through "rawhits" array  starting at index of "nexthit"
   * - Assumes that the hit list is sorted by plane and looping ends when plane number of hit doesn't match fPlaneNum
   * - Fills THcSignalHit objects frPosTdcHits and frNegTdcHits when TDC > 0
   * - Fills THcSignalHit objects frPosAdcHits and frNegAdcHit with pedestal subtracted ADC when value larger than 50
   * - For hits that have TDC value for either Pos or bottom PMT within  fScinTdcMin and fScinTdcMax
   *  + Creates new  fHodoHits[fNScinHits] =  THcHodoHit
   *  + Calculates pulse height correction to the Pos and bottom PMT times
   *  + Correct times for time traveled in paddle
   *  + Correct times for time of flight using beta from central spectrometer momentum and particle type
   *  + Calls  SetCorrectedTime method of THcHodoHit
   *  + Increments fNScinHits
   * - Returns value of nexthit + number of hits processed
   *
   */
  Clear();

  // counters for Tdc/Adc hits
  UInt_t nrPosTdcHits     = 0;
  UInt_t nrPosAdcHits     = 0;
  UInt_t nrNegTdcHits     = 0;
  UInt_t nrNegAdcHits     = 0;
  UInt_t nrSampPosAdcHits = 0;
  UInt_t nrSampNegAdcHits = 0;

  Int_t nrawhits = rawhits->GetLast() + 1;
  Int_t ihit     = nexthit;

  // A THcRawHodoHit contains all the information (tdc and adc for both
  // pmts) for a single paddle for a single trigger.  The tdc information
  // might include multiple hits if it uses a multihit tdc.
  // Use "ihit" as the index over THcRawHodoHit objects.  Use
  // "thit" to index over multiple tdc hits within an "ihit".

  Bool_t problem_flag = kFALSE; // check if fTdcRefTime is filled correctly or left initialized (kBig)

  while (ihit < nrawhits) {
    THcRawHodoHit *hit = (THcRawHodoHit *)rawhits->At(ihit);

    if (hit->fPlane > fPlaneNum) {
      break;
    }

    Int_t padnum = hit->fCounter;
    Int_t index  = padnum - 1;

    // Pos Tdc hits
    THcRawTdcHit &rawPosTdcHit = hit->GetRawTdcHitPos(); // Pos=Pos
    if (rawPosTdcHit.GetNHits() > 0 && rawPosTdcHit.HasRefTime()) {

      // Assume fPosTdcRefTime is initialized
      if (fPosTdcRefTime == kBig) {
        fPosTdcRefTime     = rawPosTdcHit.GetRefTime();
        fPosTdcRefDiffTime = rawPosTdcHit.GetRefDiffTime();
      }

      // Set problem_flag if the it's not set correctly
      if (fPosTdcRefTime != rawPosTdcHit.GetRefTime()) {
        problem_flag = kTRUE;
      }
    }

    // Loop over multiple tdc hits within ihit
    for (UInt_t thit = 0; thit < rawPosTdcHit.GetNHits(); thit++) {
      ((THcSignalHit *)frPosTdcTimeRaw->ConstructedAt(nrPosTdcHits))->Set(padnum, rawPosTdcHit.GetTimeRaw(thit));
      ((THcSignalHit *)frPosTdcTime->ConstructedAt(nrPosTdcHits))->Set(padnum, rawPosTdcHit.GetTime(thit));

      nrPosTdcHits++; // FIXME: just use thit? or is it used somewhere else too?
      fTotNumTdcHits++;
      fTotNumPosTdcHits++;
      fNumPosTdcHits.at(padnum - 1) = padnum;
    }

    // Now, repeat for the Neg end
    THcRawTdcHit &rawNegTdcHit = hit->GetRawTdcHitNeg(); // Neg=Neg
    if (rawNegTdcHit.GetNHits() > 0 && rawNegTdcHit.HasRefTime()) {
      // if (rawNegTdcHit.GetNHits() > 0) {

      if (fNegTdcRefTime == kBig) {
        fNegTdcRefTime     = rawNegTdcHit.GetRefTime();
        fNegTdcRefDiffTime = rawNegTdcHit.GetRefDiffTime();
      }

      if (fNegTdcRefTime != rawNegTdcHit.GetRefTime()) {
        problem_flag = kTRUE;
      }
    }

    for (UInt_t thit = 0; thit < rawNegTdcHit.GetNHits(); thit++) {
      ((THcSignalHit *)frNegTdcTimeRaw->ConstructedAt(nrNegTdcHits))->Set(padnum, rawNegTdcHit.GetTimeRaw(thit));
      ((THcSignalHit *)frNegTdcTime->ConstructedAt(nrNegTdcHits))->Set(padnum, rawNegTdcHit.GetTime(thit));

      nrNegTdcHits++; // FIXME: just use thit? or is it used somewhere else too?
      fTotNumTdcHits++;
      fTotNumNegTdcHits++;
      fNumNegTdcHits.at(padnum - 1) = padnum;
    } // thit loop

    // Pos ADC hits
    THcRawAdcHit &rawPosAdcHit = hit->GetRawAdcHitPos(); // Pos=Pos

    if ((rawPosAdcHit.GetNPulses() > 0 || rawPosAdcHit.GetNSamples() > 0) && rawPosAdcHit.HasRefTime()) {

      if (fPosAdcRefTime == kBig) {
        fPosAdcRefTime     = rawPosAdcHit.GetRefTime();
        fPosAdcRefDiffTime = rawPosAdcHit.GetRefDiffTime();
      }

      if (fPosAdcRefTime != rawPosAdcHit.GetRefTime()) {
        problem_flag = kTRUE;
      }
    }

    if (fUseSampWaveform == 0) {

      for (UInt_t thit = 0; thit < rawPosAdcHit.GetNPulses(); thit++) {

        ((THcSignalHit *)frPosAdcPedRaw->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetPedRaw());
        ((THcSignalHit *)frPosAdcPed->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetPed());

        ((THcSignalHit *)frPosAdcPulseIntRaw->ConstructedAt(nrPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetPulseIntRaw(thit));
        ((THcSignalHit *)frPosAdcPulseInt->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetPulseInt(thit));

        ((THcSignalHit *)frPosAdcPulseAmpRaw->ConstructedAt(nrPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetPulseAmpRaw(thit));
        ((THcSignalHit *)frPosAdcPulseAmp->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetPulseAmp(thit));

        ((THcSignalHit *)frPosAdcPulseTimeRaw->ConstructedAt(nrPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetPulseTimeRaw(thit));
        ((THcSignalHit *)frPosAdcPulseTime->ConstructedAt(nrPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetPulseTime(thit) + fAdcTdcOffset);

        // Error flags 0-2
        if (rawPosAdcHit.GetPulseAmpRaw(thit) > 0)
          ((THcSignalHit *)frPosAdcErrorFlag->ConstructedAt(nrPosAdcHits))->Set(padnum, 0);
        if (rawPosAdcHit.GetPulseAmpRaw(thit) <= 0)
          ((THcSignalHit *)frPosAdcErrorFlag->ConstructedAt(nrPosAdcHits))->Set(padnum, 1);
        if (rawPosAdcHit.GetPulseAmpRaw(thit) <= 0 && rawPosAdcHit.GetNSamples() > 0)
          ((THcSignalHit *)frPosAdcErrorFlag->ConstructedAt(nrPosAdcHits))->Set(padnum, 2);

        nrPosAdcHits++;
        fTotNumAdcHits++;
        fTotNumPosAdcHits++;
        fNumPosAdcHits.at(padnum - 1) = padnum;
      }
    }

    // Use Waveform
    if (rawPosAdcHit.GetNSamples() > 0) {
      rawPosAdcHit.SetSampThreshold(fSampThreshold);
      if (fSampNSA == 0)
        fSampNSA = rawPosAdcHit.GetF250_NSA();
      if (fSampNSB == 0)
        fSampNSB = rawPosAdcHit.GetF250_NSB();

      if (!fIsMC)
        rawPosAdcHit.SetF250Params(fSampNSA, fSampNSB, 4); // Set NPED =4

      if (fSampNSAT != 2)
        rawPosAdcHit.SetSampNSAT(fSampNSAT);
      rawPosAdcHit.SetSampIntTimePedestalPeak();
      fPosAdcSampWaveform.push_back(float(padnum));
      fPosAdcSampWaveform.push_back(float(rawPosAdcHit.GetNSamples()));

      for (UInt_t thit = 0; thit < rawPosAdcHit.GetNSamples(); thit++) {
        fPosAdcSampWaveform.push_back(rawPosAdcHit.GetSample(thit)); // ped subtracted sample (mV)
      }
      for (UInt_t thit = 0; thit < rawPosAdcHit.GetNSampPulses(); thit++) {
        ((THcSignalHit *)frPosAdcSampPedRaw->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPedRaw());
        ((THcSignalHit *)frPosAdcSampPed->ConstructedAt(nrSampPosAdcHits))->Set(padnum, rawPosAdcHit.GetSampPed());

        ((THcSignalHit *)frPosAdcSampPulseIntRaw->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseIntRaw(thit));
        ((THcSignalHit *)frPosAdcSampPulseInt->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseInt(thit));

        ((THcSignalHit *)frPosAdcSampPulseAmpRaw->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseAmpRaw(thit));
        ((THcSignalHit *)frPosAdcSampPulseAmp->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseAmp(thit));

        ((THcSignalHit *)frPosAdcSampPulseTimeRaw->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseTimeRaw(thit));
        ((THcSignalHit *)frPosAdcSampPulseTime->ConstructedAt(nrSampPosAdcHits))
            ->Set(padnum, rawPosAdcHit.GetSampPulseTime(thit) + fAdcTdcOffset);

        if (rawPosAdcHit.GetNPulses() == 0 || fUseSampWaveform == 1) {
          ((THcSignalHit *)frPosAdcPedRaw->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetSampPedRaw());
          ((THcSignalHit *)frPosAdcPed->ConstructedAt(nrPosAdcHits))->Set(padnum, rawPosAdcHit.GetSampPed());

          ((THcSignalHit *)frPosAdcPulseIntRaw->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseIntRaw(thit));
          ((THcSignalHit *)frPosAdcPulseInt->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseInt(thit));

          ((THcSignalHit *)frPosAdcPulseAmpRaw->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseAmpRaw(thit));
          ((THcSignalHit *)frPosAdcPulseAmp->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseAmp(thit));

          ((THcSignalHit *)frPosAdcPulseTimeRaw->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseTimeRaw(thit));
          ((THcSignalHit *)frPosAdcPulseTime->ConstructedAt(nrPosAdcHits))
              ->Set(padnum, rawPosAdcHit.GetSampPulseTime(thit) + fAdcTdcOffset);
          ((THcSignalHit *)frPosAdcErrorFlag->ConstructedAt(nrPosAdcHits))->Set(padnum, 3);
          if (fUseSampWaveform == 1)
            ((THcSignalHit *)frPosAdcErrorFlag->ConstructedAt(nrPosAdcHits))->Set(padnum, 0);

          ++nrPosAdcHits;
          fTotNumPosAdcHits++;
          fTotNumAdcHits++;
        }
        ++nrSampPosAdcHits;
      }
    }

    // Neg ADC hits
    THcRawAdcHit &rawNegAdcHit = hit->GetRawAdcHitNeg(); // Neg=Neg
    if ((rawNegAdcHit.GetNPulses() > 0 || rawNegAdcHit.GetNSamples() > 0) && rawNegAdcHit.HasRefTime()) {
      // if ((rawNegAdcHit.GetNPulses() > 0 || rawNegAdcHit.GetNSamples() > 0)) { // Remove RefTime Requirement

      if (fNegAdcRefTime == kBig) {
        fNegAdcRefTime     = rawNegAdcHit.GetRefTime();
        fNegAdcRefDiffTime = rawNegAdcHit.GetRefDiffTime();
      }

      if (fNegAdcRefTime != rawNegAdcHit.GetRefTime()) {
        problem_flag = kTRUE;
      }
    }

    if (fUseSampWaveform == 0) {

      for (UInt_t thit = 0; thit < rawNegAdcHit.GetNPulses(); thit++) {

        ((THcSignalHit *)frNegAdcPedRaw->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetPedRaw());
        ((THcSignalHit *)frNegAdcPed->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetPed());

        ((THcSignalHit *)frNegAdcPulseIntRaw->ConstructedAt(nrNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetPulseIntRaw(thit));
        ((THcSignalHit *)frNegAdcPulseInt->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetPulseInt(thit));

        ((THcSignalHit *)frNegAdcPulseAmpRaw->ConstructedAt(nrNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetPulseAmpRaw(thit));
        ((THcSignalHit *)frNegAdcPulseAmp->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetPulseAmp(thit));

        ((THcSignalHit *)frNegAdcPulseTimeRaw->ConstructedAt(nrNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetPulseTimeRaw(thit));
        ((THcSignalHit *)frNegAdcPulseTime->ConstructedAt(nrNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetPulseTime(thit) + fAdcTdcOffset);

        // Error flags 0-2
        if (rawNegAdcHit.GetPulseAmpRaw(thit) > 0)
          ((THcSignalHit *)frNegAdcErrorFlag->ConstructedAt(nrNegAdcHits))->Set(padnum, 0);
        if (rawNegAdcHit.GetPulseAmpRaw(thit) <= 0)
          ((THcSignalHit *)frNegAdcErrorFlag->ConstructedAt(nrNegAdcHits))->Set(padnum, 1);
        if (rawNegAdcHit.GetPulseAmpRaw(thit) <= 0 && rawNegAdcHit.GetNSamples() > 0)
          ((THcSignalHit *)frNegAdcErrorFlag->ConstructedAt(nrNegAdcHits))->Set(padnum, 2);

        nrNegAdcHits++;
        fTotNumAdcHits++;
        fTotNumNegAdcHits++;
        fNumNegAdcHits.at(padnum - 1) = padnum;
      }
    }

    // Use Waveform 
    if (rawNegAdcHit.GetNSamples() > 0) {
      rawNegAdcHit.SetSampThreshold(fSampThreshold);
      if (fSampNSA == 0)
        fSampNSA = rawNegAdcHit.GetF250_NSA();
      if (fSampNSB == 0)
        fSampNSB = rawNegAdcHit.GetF250_NSB();

      if (!fIsMC)
        rawNegAdcHit.SetF250Params(fSampNSA, fSampNSB, 4); // Set NPED =4

      if (fSampNSAT != 2)
        rawNegAdcHit.SetSampNSAT(fSampNSAT);
      rawNegAdcHit.SetSampIntTimePedestalPeak();
      fNegAdcSampWaveform.push_back(float(padnum));
      fNegAdcSampWaveform.push_back(float(rawNegAdcHit.GetNSamples()));

      for (UInt_t thit = 0; thit < rawNegAdcHit.GetNSamples(); thit++) {
        fNegAdcSampWaveform.push_back(rawNegAdcHit.GetSample(thit)); // ped subtracted sample (mV)
      }
      for (UInt_t thit = 0; thit < rawNegAdcHit.GetNSampPulses(); thit++) {
        ((THcSignalHit *)frNegAdcSampPedRaw->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPedRaw());
        ((THcSignalHit *)frNegAdcSampPed->ConstructedAt(nrSampNegAdcHits))->Set(padnum, rawNegAdcHit.GetSampPed());

        ((THcSignalHit *)frNegAdcSampPulseIntRaw->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseIntRaw(thit));
        ((THcSignalHit *)frNegAdcSampPulseInt->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseInt(thit));

        ((THcSignalHit *)frNegAdcSampPulseAmpRaw->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseAmpRaw(thit));
        ((THcSignalHit *)frNegAdcSampPulseAmp->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseAmp(thit));

        ((THcSignalHit *)frNegAdcSampPulseTimeRaw->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseTimeRaw(thit));
        ((THcSignalHit *)frNegAdcSampPulseTime->ConstructedAt(nrSampNegAdcHits))
            ->Set(padnum, rawNegAdcHit.GetSampPulseTime(thit) + fAdcTdcOffset);

        if (rawNegAdcHit.GetNPulses() == 0 || fUseSampWaveform == 1) {
          ((THcSignalHit *)frNegAdcPedRaw->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetSampPedRaw());
          ((THcSignalHit *)frNegAdcPed->ConstructedAt(nrNegAdcHits))->Set(padnum, rawNegAdcHit.GetSampPed());

          ((THcSignalHit *)frNegAdcPulseIntRaw->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseIntRaw(thit));
          ((THcSignalHit *)frNegAdcPulseInt->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseInt(thit));

          ((THcSignalHit *)frNegAdcPulseAmpRaw->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseAmpRaw(thit));
          ((THcSignalHit *)frNegAdcPulseAmp->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseAmp(thit));

          ((THcSignalHit *)frNegAdcPulseTimeRaw->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseTimeRaw(thit));
          ((THcSignalHit *)frNegAdcPulseTime->ConstructedAt(nrNegAdcHits))
              ->Set(padnum, rawNegAdcHit.GetSampPulseTime(thit) + fAdcTdcOffset);
          ((THcSignalHit *)frNegAdcErrorFlag->ConstructedAt(nrNegAdcHits))->Set(padnum, 3);
          if (fUseSampWaveform == 1)
            ((THcSignalHit *)frNegAdcErrorFlag->ConstructedAt(nrNegAdcHits))->Set(padnum, 0);

          ++nrNegAdcHits;
          fTotNumNegAdcHits++;
          fTotNumAdcHits++;
        }
        ++nrSampNegAdcHits;
      }
    }

    // LHE. Accept more than one TDC hit per paddle
    // Determine good tdc Pos and Neg times
    Int_t n_Pos_hits_max = std::max(rawPosTdcHit.GetNHits(), rawPosAdcHit.GetNSampPulses());
    Int_t n_Neg_hits_max = std::max(rawNegTdcHit.GetNHits(), rawNegAdcHit.GetNSampPulses());

    std::vector<Bool_t> btdcraw_Pos(n_Pos_hits_max, kFALSE);
    std::vector<Bool_t> btdcraw_Neg(n_Neg_hits_max, kFALSE);
    std::vector<Int_t> tdc_Pos(n_Pos_hits_max, -999);
    std::vector<Int_t> tdc_Neg(n_Neg_hits_max, -999);
    std::vector<Double_t> good_ielem_PosTdc(n_Pos_hits_max, -1);
    std::vector<Double_t> good_ielem_NegTdc(n_Neg_hits_max, -1);

    // Good TDC Pos times
    int n_Pos_hit = 0;
    int tdc_Pos_tmp;
    for (UInt_t thit = 0; thit < hit->GetRawTdcHitPos().GetNHits(); thit++) { // Pos=Pos

      tdc_Pos_tmp = hit->GetRawTdcHitPos().GetTime(thit) + fTdcOffset; // Pos=Pos

      if (tdc_Pos_tmp >= fScinTdcMin && tdc_Pos_tmp <= fScinTdcMax) {
        tdc_Pos[n_Pos_hit]           = tdc_Pos_tmp;
        btdcraw_Pos[n_Pos_hit]       = kTRUE;
        good_ielem_PosTdc[n_Pos_hit] = n_Pos_hit;
        n_Pos_hit++;
      }
    }

    // Good TDC Neg times
    int n_Neg_hit = 0;
    int tdc_Neg_tmp;
    for (UInt_t thit = 0; thit < hit->GetRawTdcHitNeg().GetNHits(); thit++) { // Neg=Neg

      tdc_Neg_tmp = hit->GetRawTdcHitNeg().GetTime(thit) + fTdcOffset; // Neg=Neg

      if (tdc_Neg_tmp >= fScinTdcMin && tdc_Neg_tmp <= fScinTdcMax) {
        tdc_Neg[n_Neg_hit]           = tdc_Neg_tmp;
        btdcraw_Neg[n_Neg_hit]       = kTRUE;
        good_ielem_NegTdc[n_Neg_hit] = n_Neg_hit;
        n_Neg_hit++;
      }
    }

    // Adc Neg
    std::vector<Bool_t> badcraw_Neg(n_Neg_hit, kFALSE);
    std::vector<Double_t> adcped_Neg(n_Neg_hit, -999);
    std::vector<Int_t> adcmult_Neg(n_Neg_hit, 0);
    std::vector<Int_t> adchitused_Neg(n_Neg_hit, 0);
    std::vector<Double_t> adcint_Neg(n_Neg_hit, -999);
    std::vector<Double_t> adcamp_Neg(n_Neg_hit, -kBig);
    std::vector<Double_t> adctime_Neg(n_Neg_hit, kBig);
    std::vector<Double_t> adctdcdifftime_Neg(n_Neg_hit, kBig);
    std::vector<Double_t> good_ielem_NegAdc(n_Neg_hit, -1);
    std::vector<Double_t> good_ielem_NegAdc_test2(n_Neg_hit, -1);

    // Adc Pos
    std::vector<Bool_t> badcraw_Pos(n_Pos_hit, kFALSE);
    std::vector<Double_t> adcped_Pos(n_Pos_hit, -999);
    std::vector<Int_t> adcmult_Pos(n_Pos_hit, 0);
    std::vector<Int_t> adchitused_Pos(n_Pos_hit, 0);
    std::vector<Double_t> adcint_Pos(n_Pos_hit, -999);
    std::vector<Double_t> adcamp_Pos(n_Pos_hit, -kBig);
    std::vector<Double_t> adctime_Pos(n_Pos_hit, kBig);
    std::vector<Double_t> adctdcdifftime_Pos(n_Pos_hit, kBig);
    std::vector<Double_t> good_ielem_PosAdc(n_Pos_hit, -1);
    std::vector<Double_t> good_ielem_PosAdc_test2(n_Pos_hit, -1);

    if (fADCMode == kADCDynamicPedestal) {

      // Loop Here over all hits per event for Neg side of plane
      // Try to find the max pulseAmp and corresponding ielem
      // within the given time window for TdcAdcTimeDiff
      for (int i_Neg_hit = 0; i_Neg_hit < n_Neg_hit; i_Neg_hit++) {

        if (good_ielem_NegTdc[i_Neg_hit] != -1) {
          Double_t max_adcamp_test     = -1000.;
          Double_t max_adctdcdiff_test = 1000.;

          for (UInt_t ielem = 0; ielem < rawNegAdcHit.GetNPulses(); ielem++) {

            Double_t pulseAmp       = rawNegAdcHit.GetPulseAmp(ielem);
            Double_t pulseTime      = rawNegAdcHit.GetPulseTime(ielem) + fAdcTdcOffset;
            Double_t TdcAdcTimeDiff = tdc_Neg[i_Neg_hit] * fScinTdcToTime - pulseTime;

            if (rawNegAdcHit.GetPulseAmpRaw(ielem) <= 0)
              pulseAmp = 200.; // do we want to to this? or skip simply this element?

            Bool_t pulseTimeCut = (TdcAdcTimeDiff > fHodoNegAdcTimeWindowMin[index]) &&
                                  (TdcAdcTimeDiff < fHodoNegAdcTimeWindowMax[index]);
            Bool_t is_used       = false;
            Bool_t is_used_test2 = false;
            for (UInt_t i = 0; i < i_Neg_hit; i++) {
              if (good_ielem_NegAdc[i] == ielem) {
                is_used = true;
              }
              if (good_ielem_NegAdc_test2[i] == ielem) {
                is_used_test2 = true;
              }
            }
            if (!is_used && pulseTimeCut && pulseAmp > max_adcamp_test) {
              good_ielem_NegAdc[i_Neg_hit] = ielem;
              max_adcamp_test              = pulseAmp;
            }
            if (!is_used_test2 && abs(TdcAdcTimeDiff) < max_adctdcdiff_test) {
              good_ielem_NegAdc_test2[i_Neg_hit] = ielem;
              max_adctdcdiff_test                = abs(TdcAdcTimeDiff);
            }
          }

          // good_ielem_NegAdc: select the pulse that has TdcAdcTimeDiff within the given range and with maximum
          // pulseAmp good_ielem_NegAdc_test2: selects the pulse with minimum value of TdcAdcTimeDiff
          if (good_ielem_NegAdc[i_Neg_hit] == -1 && good_ielem_NegAdc_test2[i_Neg_hit] != -1)
            good_ielem_NegAdc[i_Neg_hit] = good_ielem_NegAdc_test2[i_Neg_hit];
          if (good_ielem_NegAdc[i_Neg_hit] == -1 && good_ielem_NegAdc_test2[i_Neg_hit] == -1 &&
              rawNegAdcHit.GetNPulses() > 0)
            good_ielem_NegAdc[i_Neg_hit] = 0;

          if (good_ielem_NegAdc[i_Neg_hit] != -1 && good_ielem_NegAdc[i_Neg_hit] < rawNegAdcHit.GetNPulses()) {
            adcped_Neg[i_Neg_hit]     = rawNegAdcHit.GetPed();
            adcmult_Neg[i_Neg_hit]    = rawNegAdcHit.GetNPulses();
            adchitused_Neg[i_Neg_hit] = good_ielem_NegAdc[i_Neg_hit] + 1;
            adcint_Neg[i_Neg_hit]     = rawNegAdcHit.GetPulseInt(good_ielem_NegAdc[i_Neg_hit]);
            adcamp_Neg[i_Neg_hit]     = rawNegAdcHit.GetPulseAmp(good_ielem_NegAdc[i_Neg_hit]);
            if (rawNegAdcHit.GetPulseAmpRaw(good_ielem_NegAdc[i_Neg_hit]) <= 0)
              adcamp_Neg[i_Neg_hit] = 200.;
            adctime_Neg[i_Neg_hit]        = rawNegAdcHit.GetPulseTime(good_ielem_NegAdc[i_Neg_hit]) + fAdcTdcOffset;
            badcraw_Neg[i_Neg_hit]        = kTRUE;
            adctdcdifftime_Neg[i_Neg_hit] = tdc_Neg[i_Neg_hit] * fScinTdcToTime - adctime_Neg[i_Neg_hit];
          }

          // Loop Here over all hits per event for Pos side of plane
          // Try to find the max pulseAmp and corresponding ielem
          // within the given time window for TdcAdcTimeDiff
          for (int i_Pos_hit = 0; i_Pos_hit < n_Pos_hit; i_Pos_hit++) {

            if (good_ielem_PosTdc[i_Pos_hit] != -1) {
              Double_t max_adcamp_test     = -1000.;
              Double_t max_adctdcdiff_test = 1000.;

              for (UInt_t ielem = 0; ielem < rawPosAdcHit.GetNPulses(); ielem++) {

                Double_t pulseAmp       = rawPosAdcHit.GetPulseAmp(ielem);
                Double_t pulseTime      = rawPosAdcHit.GetPulseTime(ielem) + fAdcTdcOffset;
                Double_t TdcAdcTimeDiff = tdc_Pos[i_Pos_hit] * fScinTdcToTime - pulseTime;

                if (rawPosAdcHit.GetPulseAmpRaw(ielem) <= 0)
                  pulseAmp = 200.; // do we want to to this? or skip simply this element?

                Bool_t pulseTimeCut = (TdcAdcTimeDiff > fHodoPosAdcTimeWindowMin[index]) &&
                                      (TdcAdcTimeDiff < fHodoPosAdcTimeWindowMax[index]);
                Bool_t is_used       = false;
                Bool_t is_used_test2 = false;
                for (UInt_t i = 0; i < i_Pos_hit; i++) {
                  if (good_ielem_PosAdc[i] == ielem) {
                    is_used = true;
                  }
                  if (good_ielem_PosAdc_test2[i] == ielem) {
                    is_used_test2 = true;
                  }
                }
                if (!is_used && pulseTimeCut && pulseAmp > max_adcamp_test) {
                  good_ielem_PosAdc[i_Pos_hit] = ielem;
                  max_adcamp_test              = pulseAmp;
                }
                if (!is_used_test2 && abs(TdcAdcTimeDiff) < max_adctdcdiff_test) {
                  good_ielem_PosAdc_test2[i_Pos_hit] = ielem;
                  max_adctdcdiff_test                = abs(TdcAdcTimeDiff);
                }
              }

              // good_ielem_PosAdc: select the pulse that has TdcAdcTimeDiff within the given range and with maximum
              // pulseAmp good_ielem_PosAdc_test2: selects the pulse with minimum value of TdcAdcTimeDiff
              if (good_ielem_PosAdc[i_Pos_hit] == -1 && good_ielem_PosAdc_test2[i_Pos_hit] != -1)
                good_ielem_PosAdc[i_Pos_hit] = good_ielem_PosAdc_test2[i_Pos_hit];
              if (good_ielem_PosAdc[i_Pos_hit] == -1 && good_ielem_PosAdc_test2[i_Pos_hit] == -1 &&
                  rawPosAdcHit.GetNPulses() > 0)
                good_ielem_PosAdc[i_Pos_hit] = 0;

              if (good_ielem_PosAdc[i_Pos_hit] != -1 && good_ielem_PosAdc[i_Pos_hit] < rawPosAdcHit.GetNPulses()) {
                adcped_Pos[i_Pos_hit]     = rawPosAdcHit.GetPed();
                adcmult_Pos[i_Pos_hit]    = rawPosAdcHit.GetNPulses();
                adchitused_Pos[i_Pos_hit] = good_ielem_PosAdc[i_Pos_hit] + 1;
                adcint_Pos[i_Pos_hit]     = rawPosAdcHit.GetPulseInt(good_ielem_PosAdc[i_Pos_hit]);
                adcamp_Pos[i_Pos_hit]     = rawPosAdcHit.GetPulseAmp(good_ielem_PosAdc[i_Pos_hit]);
                if (rawPosAdcHit.GetPulseAmpRaw(good_ielem_PosAdc[i_Pos_hit]) <= 0)
                  adcamp_Pos[i_Pos_hit] = 200.;
                adctime_Pos[i_Pos_hit]        = rawPosAdcHit.GetPulseTime(good_ielem_PosAdc[i_Pos_hit]) + fAdcTdcOffset;
                badcraw_Pos[i_Pos_hit]        = kTRUE;
                adctdcdifftime_Pos[i_Pos_hit] = tdc_Pos[i_Pos_hit] * fScinTdcToTime - adctime_Pos[i_Pos_hit];
              }
            }
          }
        }
      } // End loop over all good Neg TDC hits
    } // if kADCDynamicPedestal

    // Currently not set up to use kADCSampleIntegral or kADCSampIntDynPed
    /*
        else if (fADCMode == kADCSampleIntegral) {
          adcint_Pos  = hit->GetRawAdcHitPos().GetSampleIntRaw() - fPosPed[index]; // Pos=Pos
          adcint_Neg  = hit->GetRawAdcHitNeg().GetSampleIntRaw() - fNegPed[index]; // Neg=Neg
          badcraw_Pos = badcraw_Neg = kTRUE;

        } else if (fADCMode == kADCSampIntDynPed) {
          adcint_Pos  = hit->GetRawAdcHitPos().GetSampleInt(); // Pos=Pos
          adcint_Neg  = hit->GetRawAdcHitNeg().GetSampleInt(); // Neg=Neg
          badcraw_Pos = badcraw_Neg = kTRUE;

        } else {
          // same as using kADCSampleIntegral
          adcint_Pos  = hit->GetRawAdcHitPos().GetPulseIntRaw() - fPosPed[index]; // Pos=Pos
          adcint_Neg  = hit->GetRawAdcHitNeg().GetPulseIntRaw() - fNegPed[index]; // Neg=Neg
          badcraw_Pos = badcraw_Neg = kTRUE;
        }

        // We don't really do anything with these arrays (frPosAdcHits, frNegAdcHits, ..)
        if (adcint_Pos >= fADCDiagCut) {
          ((THcSignalHit *)frPosAdcHits->ConstructedAt(nrPosADCHits))->Set(padnum, adcint_Pos);
          Double_t samplesum = hit->GetRawAdcHitPos().GetSampleIntRaw(); // Pos=Pos
          Double_t pedestal  = hit->GetRawAdcHitPos().GetPedRaw();       // Pos=Pos
          ((THcSignalHit *)frPosAdcSums->ConstructedAt(nrPosADCHits))->Set(padnum, samplesum);
          ((THcSignalHit *)frPosAdcPeds->ConstructedAt(nrPosADCHits++))->Set(padnum, pedestal);
        }
        if (adcint_Neg >= fADCDiagCut) {
          ((THcSignalHit *)frNegAdcHits->ConstructedAt(nrNegADCHits))->Set(padnum, adcint_Neg);
          Double_t samplesum = hit->GetRawAdcHitNeg().GetSampleIntRaw(); // Neg=Neg
          Double_t pedestal  = hit->GetRawAdcHitNeg().GetPedRaw();       // Neg=Neg
          ((THcSignalHit *)frNegAdcSums->ConstructedAt(nrNegADCHits))->Set(padnum, samplesum);
          ((THcSignalHit *)frNegAdcPeds->ConstructedAt(nrNegADCHits++))->Set(padnum, pedestal);
        }
    */

    // Loop over individual TDC/ADC pairs for Pos and Neg

    for (int i_Pos_hit = 0; i_Pos_hit < n_Pos_hit; i_Pos_hit++) {

      if (good_ielem_PosAdc[i_Pos_hit] != -1) {

        // good adc multiplicity
        fTotNumGoodPosAdcHits++;
        fTotNumGoodAdcHits++;

        // good adc occupancy
        fNumGoodPosAdcHits.at(padnum - 1)     = padnum;
        fGoodPosAdcPed.at(padnum - 1)         = adcped_Pos[i_Pos_hit];
        fGoodPosAdcMult.at(padnum - 1)        = adcmult_Pos[i_Pos_hit];
        fGoodPosAdcHitUsed.at(padnum - 1)     = adchitused_Pos[i_Pos_hit];
        fGoodPosAdcPulseInt.at(padnum - 1)    = adcint_Pos[i_Pos_hit];
        fGoodPosAdcPulseAmp.at(padnum - 1)    = adcamp_Pos[i_Pos_hit];
        fGoodPosAdcPulseTime.at(padnum - 1)   = adctime_Pos[i_Pos_hit];
        fGoodPosAdcTdcDiffTime.at(padnum - 1) = adctdcdifftime_Pos[i_Pos_hit];
      }

      // DEFINE THE "GOOD +TDC Multiplicities and Occupancies"
      if (good_ielem_PosTdc[i_Pos_hit] != -1) {
        fTotNumGoodPosTdcHits++;
        fTotNumGoodTdcHits++;
        // good tdc occupancy
        fNumGoodPosTdcHits.at(padnum - 1) = padnum;
      }
    }

    for (int i_Neg_hit = 0; i_Neg_hit < n_Neg_hit; i_Neg_hit++) {

      if (good_ielem_NegAdc[i_Neg_hit] != -1) {

        // good adc multiplicity
        fTotNumGoodNegAdcHits++;
        fTotNumGoodAdcHits++;

        // good adc occupancy
        fNumGoodNegAdcHits.at(padnum - 1)     = padnum;
        fGoodNegAdcPed.at(padnum - 1)         = adcped_Neg[i_Neg_hit];
        fGoodNegAdcMult.at(padnum - 1)        = adcmult_Neg[i_Neg_hit];
        fGoodNegAdcHitUsed.at(padnum - 1)     = adchitused_Neg[i_Neg_hit];
        fGoodNegAdcPulseInt.at(padnum - 1)    = adcint_Neg[i_Neg_hit];
        fGoodNegAdcPulseAmp.at(padnum - 1)    = adcamp_Neg[i_Neg_hit];
        fGoodNegAdcPulseTime.at(padnum - 1)   = adctime_Neg[i_Neg_hit];
        fGoodNegAdcTdcDiffTime.at(padnum - 1) = adctdcdifftime_Neg[i_Neg_hit];
      }

      if (good_ielem_NegTdc[i_Neg_hit] != -1) {
        fTotNumGoodNegTdcHits++;
        fTotNumGoodTdcHits++;
        // good tdc occupancy
        fNumGoodNegTdcHits.at(padnum - 1) = padnum;
      }
    }

    // Match Pos and Neg TDC/ADC Pairs
    vector<int> good_ielem_Pos_Tdc_Full(n_Pos_hit, -1);
    vector<int> good_ielem_Neg_Tdc_Full(n_Neg_hit, -1);
    // vector<int> good_ielem_Pos_Adc_Full(n_Pos_hit, -1);
    // vector<int> good_ielem_Neg_Adc_Full(n_Neg_hit, -1);
    int n_Pos_hit_full = 0;
    for (int i_Pos_hit = 0; i_Pos_hit < n_Pos_hit; i_Pos_hit++) {
      for (int i_Neg_hit = 0; i_Neg_hit < n_Neg_hit; i_Neg_hit++) {
        if (good_ielem_PosAdc[i_Pos_hit] != -1 && good_ielem_NegAdc[i_Neg_hit] != -1) {
          if (std::find(good_ielem_Pos_Tdc_Full.begin(), good_ielem_Pos_Tdc_Full.end(), good_ielem_PosTdc[i_Pos_hit]) !=
              good_ielem_Pos_Tdc_Full.end()) {
            continue;
          }
          if (std::find(good_ielem_Neg_Tdc_Full.begin(), good_ielem_Neg_Tdc_Full.end(), good_ielem_NegTdc[i_Neg_hit]) !=
              good_ielem_Neg_Tdc_Full.end()) {
            continue;
          }
          double dt = tdc_Pos[i_Pos_hit] * fScinTdcToTime - tdc_Neg[i_Neg_hit] * fScinTdcToTime;
          if (abs(dt) < fTDC_match_window) { // Hard coded to 50ns
            good_ielem_Pos_Tdc_Full[n_Pos_hit_full] = good_ielem_PosTdc[i_Pos_hit];
            good_ielem_Neg_Tdc_Full[n_Pos_hit_full] = good_ielem_NegTdc[i_Neg_hit];
            // good_ielem_Pos_Adc_Full[n_Pos_hit_full] = good_ielem_PosAdc[i_Pos_hit];
            // good_ielem_Neg_Adc_Full[n_Pos_hit_full] = good_ielem_NegAdc[i_Neg_hit];
            n_Pos_hit_full++;
          }
        }
      }
    }

    for (int i_good_hit = 0; i_good_hit < n_Pos_hit_full; i_good_hit++) {
      if (good_ielem_Pos_Tdc_Full[i_good_hit] != -1 && good_ielem_Neg_Tdc_Full[i_good_hit] != -1) {
        int i_good_Pos_tdc_elem = good_ielem_Pos_Tdc_Full[i_good_hit];
        int i_good_Neg_tdc_elem = good_ielem_Neg_Tdc_Full[i_good_hit];
        int i_good_Pos_adc_elem = good_ielem_Pos_Tdc_Full[i_good_hit];
        int i_good_Neg_adc_elem = good_ielem_Neg_Tdc_Full[i_good_hit];

        // DEFINE THE "GOOD -TDC  Multiplicities and Occupancies"

        new ((*fHodoHits)[fNScinHits])
            HYPScintHit(tdc_Pos[i_good_Pos_tdc_elem], tdc_Neg[i_good_Neg_tdc_elem], adcint_Pos[i_good_Pos_adc_elem],
                          adcint_Neg[i_good_Neg_adc_elem], hit->fCounter, this);

        ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetPosADCpeak(adcamp_Pos[i_good_Pos_adc_elem]);
        ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetNegADCpeak(adcamp_Neg[i_good_Neg_adc_elem]);
        ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetPosADCtime(adctime_Pos[i_good_Pos_adc_elem]);
        ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetNegADCtime(adctime_Neg[i_good_Neg_adc_elem]);

        // Calculate Time-Walk Correction

        // LHE: Start section 1. Need to rewrite this later
        // Define GoodTdcUnCorrTime
        if (btdcraw_Pos[i_good_Pos_tdc_elem] && badcraw_Pos[i_good_Pos_adc_elem]) {
          fGoodPosTdcTimeUnCorr.at(padnum - 1) = tdc_Pos[i_good_Pos_tdc_elem] * fScinTdcToTime;

          tw_corr_Pos = 1. / pow(adcamp_Pos[i_good_Pos_adc_elem] / fTdc_Thrs, fHodoPos_c2[padnum - 1]) -
                        1. / pow(200. / fTdc_Thrs, fHodoPos_c2[padnum - 1]);

          fGoodPosTdcTimeWalkCorr.at(padnum - 1) = tdc_Pos[i_good_Pos_tdc_elem] * fScinTdcToTime - tw_corr_Pos;
        }
        if (btdcraw_Neg[i_good_Neg_tdc_elem] && badcraw_Neg[i_good_Neg_adc_elem]) {
          fGoodNegTdcTimeUnCorr.at(padnum - 1) = tdc_Neg[i_good_Neg_tdc_elem] * fScinTdcToTime;

          // tw_corr_Neg = fHodoNeg_c1[padnum-1]/pow(adcamp_Neg/fTdc_Thrs,fHodoNeg_c2[padnum-1]) -
          // fHodoNeg_c1[padnum-1]/pow(200./fTdc_Thrs, fHodoNeg_c2[padnum-1]);

          tw_corr_Neg = 1. / pow(adcamp_Neg[i_good_Neg_adc_elem] / fTdc_Thrs, fHodoNeg_c2[padnum - 1]) -
                        1. / pow(200. / fTdc_Thrs, fHodoNeg_c2[padnum - 1]);

          fGoodNegTdcTimeWalkCorr.at(padnum - 1) = tdc_Neg[i_good_Neg_tdc_elem] * fScinTdcToTime - tw_corr_Neg;
        }
        // LHE: End section 1. Need to rewrite this later

        // Do corrections if valid TDC on both ends of bar (both ends should always be valid)
        if ((btdcraw_Pos[i_good_Pos_tdc_elem] && btdcraw_Neg[i_good_Neg_tdc_elem]) &&
            (badcraw_Pos[i_good_Pos_adc_elem] && badcraw_Neg[i_good_Neg_adc_elem])) {
          // Do the pulse height correction to the time.  (Position dependent corrections later)
          Double_t adc_timec_Pos = adctime_Pos[i_good_Pos_adc_elem];
          Double_t adc_timec_Neg = adctime_Neg[i_good_Neg_adc_elem];
          Double_t timec_Pos, timec_Neg;
          // FADC style. Removed fTofUsingInvAdc
          timec_Pos = tdc_Pos[i_good_Pos_tdc_elem] * fScinTdcToTime - tw_corr_Pos + fHodo_LCoeff[index];
          timec_Neg = tdc_Neg[i_good_Neg_tdc_elem] * fScinTdcToTime - tw_corr_Neg - 2 * fHodoCableFit[index] +
                      fHodo_LCoeff[index];
          adc_timec_Pos = adc_timec_Pos - tw_corr_Pos + fHodo_LCoeff[index];
          adc_timec_Neg = adc_timec_Neg - tw_corr_Neg - 2 * fHodoCableFit[index] + fHodo_LCoeff[index];

          Double_t TWCorrDiff = fGoodNegTdcTimeWalkCorr.at(padnum - 1) - 2 * fHodoCableFit[index] -
                                fGoodPosTdcTimeWalkCorr.at(padnum - 1);

          Double_t fHitDistCorr = 0.5 * TWCorrDiff * fHodoVelFit[index];

          fGoodDiffDistTrack.at(index) = fHitDistCorr;
          fGoodHitTimeDiff.at(index)   = TWCorrDiff;

          Double_t vellight = fHodoVelLight[index]; // read from hodo_cuts.param, where it is set fixed to 15.0

          Double_t dist_from_center = 0.5 * (timec_Neg - timec_Pos) * vellight;
          Double_t scint_center     = 0.5 * (fPosLeft[padnum - 1] + fPosRight[padnum - 1]);
          Double_t hit_position     = scint_center + dist_from_center;
          hit_position              = TMath::Min(hit_position, fPosLeft[padnum - 1]);
          hit_position              = TMath::Max(hit_position, fPosRight[padnum - 1]);
          Double_t scin_corrected_time, Postime, Negtime;
          Double_t adc_Postime = adc_timec_Pos;
          Double_t adc_Negtime = adc_timec_Neg;

          // Removed fTofUsingInvAdc
          scin_corrected_time = 0.5 * (timec_Neg + timec_Pos);
          // timec_Pos                   = scin_corrected_time;
          // timec_Neg                   = scin_corrected_time;
          Double_t adc_time_corrected = 0.5 * (adc_timec_Pos + adc_timec_Neg);
          // LHE: Need to change this to match LAD
          // if (fCosmicFlag) {
          //   Postime     = timec_Pos + (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   Negtime     = timec_Neg + (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   adc_Postime = adc_time_corrected + (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   adc_Negtime = adc_time_corrected + (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          // } else {
          //   Postime     = timec_Pos - (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   Negtime     = timec_Neg - (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   adc_Postime = adc_time_corrected - (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          //   adc_Negtime = adc_time_corrected - (fZpos + (index % 2) * fDzpos) / (29.979 * fBetaNominal);
          // }

          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetPaddleCenter(fPosCenter[index]);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))
              ->SetCorrectedTimes(timec_Pos, timec_Neg, Postime, Negtime, scin_corrected_time);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetPosADCpeak(adcamp_Pos[i_good_Pos_adc_elem]);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetNegADCpeak(adcamp_Neg[i_good_Neg_adc_elem]);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetPosADCCorrtime(adc_Postime);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetNegADCCorrtime(adc_Negtime);
          ((HYPScintHit *)fHodoHits->At(fNScinHits))->SetCalcPosition(fHitDistCorr); //

          fGoodPosTdcTimeCorr.at(padnum - 1)    = timec_Pos;
          fGoodNegTdcTimeCorr.at(padnum - 1)    = timec_Neg;
          fGoodPosTdcTimeTOFCorr.at(padnum - 1) = Postime;
          fGoodNegTdcTimeTOFCorr.at(padnum - 1) = Negtime;
          fGoodHitTimeAvg.at(padnum - 1)        = scin_corrected_time;
        } else {
          cout << "HYPScintillatorPlane::ProcessHits. Good hit has bad ADC or TDC on some end" << endl;
        }
        fNScinHits++;
      }
    }
    ihit++;
  } // while loop

  if (problem_flag) {
    cout << "HYPScintillatorPlane::ProcessHits " << fPlaneNum << " " << nexthit << "/" << nrawhits << endl;
    cout << " Ref problem end *******" << endl;
  }
  return (ihit);
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::CoarseProcess(TClonesArray &tracks) {
  // Do nothing
  return 0;
}

//_______________________________________________________________________________________
Int_t HYPScintillatorPlane::FineProcess(TClonesArray &tracks) {
  // Do nothing
  return 0;
}

//_____________________________________________________________________________
Int_t HYPScintillatorPlane::AccumulatePedestals(TClonesArray *rawhits, Int_t nexthit) {
  /*! \brief Extract the data for this plane from raw hit list THcRawHodoHit, accumulating into arrays for calculating
   * pedestals.
   *
   * - Loop through raw data for scintillator plane
   */
  Int_t nrawhits = rawhits->GetLast() + 1;
  // cout << "THcHYPScintillatorPlane::AcculatePedestals " << fPlaneNum << " " << nexthit << "/" << nrawhits << endl;

  Int_t ihit = nexthit;
  while (ihit < nrawhits) {
    THcRawHodoHit *hit = (THcRawHodoHit *)rawhits->At(ihit);
    if (hit->fPlane > fPlaneNum) {
      break;
    }
    Int_t element = hit->fCounter - 1;                       // Should check if in range
    Int_t adcPos  = hit->GetRawAdcHitPos().GetPulseIntRaw(); // Pos=Pos
    Int_t adcNeg  = hit->GetRawAdcHitNeg().GetPulseIntRaw(); // Neg=Neg

    if (adcPos <= fPosPedLimit[element]) {
      fPosPedSum[element] += adcPos;
      fPosPedSum2[element] += adcPos * adcPos;
      fPosPedCount[element]++;
      if (fPosPedCount[element] == fMinPeds / 5) {
        fPosPedLimit[element] = 100 + fPosPedSum[element] / fPosPedCount[element];
      }
    }
    if (adcNeg <= fNegPedLimit[element]) {
      fNegPedSum[element] += adcNeg;
      fNegPedSum2[element] += adcNeg * adcNeg;
      fNegPedCount[element]++;
      if (fNegPedCount[element] == fMinPeds / 5) {
        fNegPedLimit[element] = 100 + fNegPedSum[element] / fNegPedCount[element];
      }
    }
    ihit++;
  }

  fNPedestalEvents++;

  return (ihit);
}

//_______________________________________________________________________________________
void HYPScintillatorPlane::CalculatePedestals() {
  /*! \brief   Calculate pedestals from arrays made in THcHYPScintillatorPlane::AccumulatePedestals
   *
   * - Calculate pedestals from arrays made in THcHYPScintillatorPlane::AccumulatePedestals
   * - In old fortran ENGINE code, a comparison was made between calculated pedestals and the pedestals read in by the
   * FASTBUS modules for zero supression. This is not implemented.
   */
  for (UInt_t i = 0; i < fNelem; i++) {

    // Pos tubes
    fPosPed[i]    = ((Double_t)fPosPedSum[i]) / TMath::Max(1, fPosPedCount[i]);
    fPosThresh[i] = fPosPed[i] + 15;

    // Bottom tubes
    fNegPed[i]    = ((Double_t)fNegPedSum[i]) / TMath::Max(1, fNegPedCount[i]);
    fNegThresh[i] = fNegPed[i] + 15;

    //    cout <<"Pedestals "<< i+1 << " " << fPosPed[i] << " " << fNegPed[i] << endl;
  }
}

//_____________________________________________________________________________
void HYPScintillatorPlane::InitializePedestals() {
  /*! \brief   called by THcHodoPlane::ReadDatabase
   *
   * - Initialize variables used in  THcHYPScintillatorPlane::AccumulatePedestals and
   * THcHYPScintillatorPlane::CalculatePedestals
   * - Minimum number of pedestal events needed for calculation, fMinPeds, hadrcoded to 500
   */
  fNPedestalEvents = 0;
  fMinPeds         = 500; // In engine, this is set in parameter file
  fPosPedSum       = new Int_t[fNelem];
  fPosPedSum2      = new Int_t[fNelem];
  fPosPedLimit     = new Int_t[fNelem];
  fPosPedCount     = new Int_t[fNelem];
  fNegPedSum       = new Int_t[fNelem];
  fNegPedSum2      = new Int_t[fNelem];
  fNegPedLimit     = new Int_t[fNelem];
  fNegPedCount     = new Int_t[fNelem];

  fPosPed    = new Double_t[fNelem];
  fNegPed    = new Double_t[fNelem];
  fPosThresh = new Double_t[fNelem];
  fNegThresh = new Double_t[fNelem];
  for (UInt_t i = 0; i < fNelem; i++) {
    fPosPedSum[i]   = 0;
    fPosPedSum2[i]  = 0;
    fPosPedLimit[i] = 1000; // In engine, this are set in parameter file
    fPosPedCount[i] = 0;
    fNegPedSum[i]   = 0;
    fNegPedSum2[i]  = 0;
    fNegPedLimit[i] = 1000; // In engine, this are set in parameter file
    fNegPedCount[i] = 0;
  }
}
//____________________________________________________________________________

ClassImp(HYPScintillatorPlane)

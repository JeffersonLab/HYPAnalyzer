#include "HYPCherenkov.h"
#include "THaEvData.h"
#include "THaDetMap.h"
#include "THcDetectorMap.h"
#include "THcGlobals.h"
#include "THaCutList.h"
#include "THcParmList.h"
#include "THaApparatus.h"
#include "VarDef.h"
#include "VarType.h"
#include "THaTrack.h"
#include "TClonesArray.h"
#include "TMath.h"
#include "THaTrackProj.h"
#include "THcRawAdcHit.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

//_____________________________________________________________________
HYPCherenkov::HYPCherenkov( const char* name, const char* description,
		      THaApparatus* apparatus) :
  THaNonTrackingDetector(name, description, apparatus), 
  fNhits(0), fPresentP(0)
{

}

//_____________________________________________________________________
HYPCherenkov::HYPCherenkov() :
  THaNonTrackingDetector(), fNhits(0), fPresentP(0)
{

}
//_____________________________________________________________________
HYPCherenkov::~HYPCherenkov()
{
  // Destructor
  RemoveVariables();

  /*
  delete [] fAdcPosTimeWindowMin; fAdcPosTimeWindowMin = nullptr;
  delete [] fAdcPosTimeWindowMax; fAdcPosTimeWindowMax = nullptr;
  delete [] fAdcNegTimeWindowMin; fAdcNegTimeWindowMin = nullptr;
  delete [] fAdcNegTimeWindowMax; fAdcNegTimeWindowMax = nullptr;
  */
}

//__________________________________________________________________
THaAnalysisObject::EStatus HYPCherenkov::Init(const TDatime &date)
{

  //  cout << "HYPCherenkov::Init" << endl;

  string EngineDID = string(GetApparatus()->GetName()).substr(0, 1) + GetName();
  std::transform(EngineDID.begin(), EngineDID.end(), EngineDID.begin(), ::toupper);
  if(gHcDetectorMap->FillMap(fDetMap, EngineDID.c_str()) < 0) {
    static const char* const here = "Init()";
    Error(Here(here), "Error filling detectormap for %s.", EngineDID.c_str());
    return kInitError;
  }

  EStatus status;
  if((status = THaNonTrackingDetector::Init( date )))
    return fStatus=status;

  InitHitList(fDetMap, "THcCherenkovHit", fDetMap->GetTotNumChan()+1, 0, fADC_RefTimeCut);
  
  fPresentP = 0;
  THaVar* vpresent = gHaVars->Find(Form("%s.present",GetApparatus()->GetName()));
  if(vpresent) {
    fPresentP = (Bool_t *) vpresent->GetValuePointer();
  }
  
  return fStatus = kOK;
}

//_____________________________________________________________________
void HYPCherenkov::Clear( Option_t* opt )
{
  fNhits = 0;
  fPosDataRaw.clear();
  fNegDataRaw.clear();
  fPosData.clear();
  fNegData.clear();

  fPosSampDataRaw.clear();
  fNegSampDataRaw.clear();
  fPosSampData.clear();
  fNegSampData.clear();

  fPosErrorFlag.clear();
  fNegErrorFlag.clear();
}

//_____________________________________________________________________
Int_t HYPCherenkov::ReadDatabase( const TDatime& date )
{
  //  cout << "HYPCherenkov::ReadDatabase" << endl;

  string prefix = string(GetApparatus()->GetName()).substr(0, 1) + GetName();
  std::transform(prefix.begin(), prefix.end(), prefix.begin(), ::tolower);

  CreateMissReportParms(prefix.c_str());

  DBRequest list_1[] = {
    {"_nelem", &fNelem, kInt},
    {nullptr}
  };

  gHcParms->LoadParmValues(list_1, prefix.c_str());

  DBRequest list[]={
    {"_SampThreshold",     &fSampThreshold,   kDouble,0,1},
    {"_SampNSA",           &fSampNSA,         kInt,0,1},
    {"_SampNSAT",          &fSampNSAT,        kInt,0,1},
    {"_SampNSB",           &fSampNSB,         kInt,0,1},
    {"_UseSampWaveform",   &fUseSampWaveform, kInt,0,1},
    {"_adcrefcut",         &fADC_RefTimeCut,  kInt,0,1},
    {"_debug_adc",         &fDebugAdc,        kInt,0,1},
    {nullptr}
  };

  // Default values
  fADC_RefTimeCut = 0;
  fSampThreshold = 5.;
  fSampNSA = 0;   // use value stored in event 125 info
  fSampNSB = 0;   // use value stored in event 125 info
  fSampNSAT = 2;  // default value in THcRawHit::SetF250Params
  fUseSampWaveform = 0; // 0= do not use , 1 = use Sample Waveform
  fDebugAdc = 0;

  gHcParms->LoadParmValues((DBRequest*)&list, prefix.c_str());

  fPosDataRaw.reserve(fNelem);
  fNegDataRaw.reserve(fNelem);
  fPosData.reserve(fNelem);
  fNegData.reserve(fNelem);
  fPosSampDataRaw.reserve(fNelem);
  fNegSampDataRaw.reserve(fNelem);
  fPosSampData.reserve(fNelem);
  fNegSampData.reserve(fNelem);

  fIsInit = true;

  return kOK;
}

//_____________________________________________________________________
Int_t HYPCherenkov::DefineVariables( EMode mode )
{

  if (fDebugAdc) {
    RVarDef vars[] = {
      // FIXME; put the counters back
      // {"numPosAdcHits",        "Number of Positive ADC Hits Per PMT",      "fNumPosAdcHits"},        // Aerogel occupancy
      // {"totNumPosAdcHits",     "Total Number of Positive ADC Hits",        "fTotNumPosAdcHits"},     // Aerogel multiplicity
      // {"numNegAdcHits",        "Number of Negative ADC Hits Per PMT",      "fNumNegAdcHits"},        // Aerogel occupancy
      // {"totNumNegAdcHits",     "Total Number of Negative ADC Hits",        "fTotNumNegAdcHits"},     // Aerogel multiplicity
      // {"totnumAdcHits",       "Total Number of ADC Hits Per PMT",          "fTotNumAdcHits"},        // Aerogel multiplicity
      {"posPadNum",          "Paddle number",                     "fPosDataRaw.paddle"},
      {"posAdcPedRaw",       "Positive Raw ADC pedestals",        "fPosDataRaw.Ped"},
      {"posAdcPulseIntRaw",  "Positive Raw ADC pulse integrals",  "fPosDataRaw.PulseInt"},
      {"posAdcPulseAmpRaw",  "Positive Raw ADC pulse amplitudes", "fPosDataRaw.PulseAmp"},
      {"posAdcPulseTimeRaw", "Positive Raw ADC pulse times",      "fPosDataRaw.PulseTime"},
      {"posAdcPed",          "Positive ADC pedestals",            "fPosData.Ped"},
      {"posAdcPulseInt",     "Positive ADC pulse integrals",      "fPosData.PulseInt"},
      {"posAdcPulseAmp",     "Positive ADC pulse amplitudes",     "fPosData.PulseAmp"},
      {"posAdcPulseTime",    "Positive ADC pulse times",          "fPosData.PulseTime"},
      {"negPadNum",          "Paddle number",                     "fNegDataRaw.paddle"},
      {"negAdcPedRaw",       "Negative Raw ADC pedestals",        "fNegDataRaw.Ped"},
      {"negAdcPulseIntRaw",  "Negative Raw ADC pulse integrals",  "fNegDataRaw.PulseInt"},
      {"negAdcPulseAmpRaw",  "Negative Raw ADC pulse amplitudes", "fNegDataRaw.PulseAmp"},
      {"negAdcPulseTimeRaw", "Negative Raw ADC pulse times",      "fNegDataRaw.PulseTime"},
      {"negAdcPed",          "Negative ADC pedestals",            "fNegData.Ped"},
      {"negAdcPulseInt",     "Negative ADC pulse integrals",      "fNegData.PulseInt"},
      {"negAdcPulseAmp",     "Negative ADC pulse amplitudes",     "fNegData.PulseAmp"},
      {"negAdcPulseTime",    "Negative ADC pulse times",          "fNegData.PulseTime"},
      {"posErrorFlag",       "Error Flag for When FPGA Fails",    "fPosErrorFlag"},
      {"negErrorFlag",       "Error Flag for When FPGA Fails",    "fNegErrorFlag"},
      { nullptr }
    };
    DefineVarsFromList( vars, mode);
  }

  // return DefineVarsFromList(vars, mode);
  return kOK;

}

//_____________________________________________________________________
Int_t HYPCherenkov::Decode( const THaEvData& evdata )
{
  Bool_t present = kTRUE;	// Suppress reference time warnings
  if(fPresentP) {		      // if this spectrometer not part of trigger
    present = *fPresentP;
  }

  fNhits = DecodeToHitList(evdata, !present);

  // FIXME: Define a function to store data and call it for pos/neg
  Int_t ihit = 0;
  while(ihit < fNhits) {
    THcCherenkovHit* hit         = (THcCherenkovHit*) fRawHitList->At(ihit);
    Int_t            npmt        = hit->fCounter;
    THcRawAdcHit&    rawPosAdcHit = hit->GetRawAdcHitPos();
    THcRawAdcHit&    rawNegAdcHit = hit->GetRawAdcHitNeg();

    Int_t errorflag = 999;
    if ( fUseSampWaveform == 0 ) {
      for (UInt_t thit = 0; thit < rawPosAdcHit.GetNPulses(); thit++) {

      FADCHitData posdata_raw;
      FADCHitData posdata;

      posdata_raw.paddle = npmt;
      posdata_raw.Ped = rawPosAdcHit.GetPedRaw();
      posdata_raw.PulseInt = rawPosAdcHit.GetPulseIntRaw();
      posdata_raw.PulseAmp = rawPosAdcHit.GetPulseAmpRaw();
      posdata_raw.PulseTime = rawPosAdcHit.GetPulseTimeRaw();
       
      posdata.paddle = npmt;
      posdata.Ped = rawPosAdcHit.GetPed();
      posdata.PulseInt = rawPosAdcHit.GetPulseInt();
      posdata.PulseAmp = rawPosAdcHit.GetPulseAmp();
      posdata.PulseTime = rawPosAdcHit.GetPulseTime();

      if(posdata_raw.PulseAmp > 0)  errorflag = 0;
      if(posdata_raw.PulseAmp <= 0) errorflag = 1;
      if(posdata_raw.PulseAmp <= 0 && rawPosAdcHit.GetNSamples() > 0) errorflag = 2;

      fPosDataRaw.emplace_back(posdata_raw);
      fPosData.emplace_back(posdata);
      // FIXME: Add an option to use pedestal from DB
      }
    }// Using Pulse Data

    // Sample Data
    if (rawPosAdcHit.GetNSamples() >0 ) {
      rawPosAdcHit.SetSampThreshold(fSampThreshold);
      if (fSampNSA == 0) fSampNSA=rawPosAdcHit.GetF250_NSA();
      if (fSampNSB == 0) fSampNSB=rawPosAdcHit.GetF250_NSB();
      rawPosAdcHit.SetF250Params(fSampNSA,fSampNSB,4); // Set NPED =4
      if (fSampNSAT != 2) rawPosAdcHit.SetSampNSAT(fSampNSAT);
      rawPosAdcHit.SetSampIntTimePedestalPeak();
      
      // FIXME: Do we want to save waveform data?
      for (UInt_t thit = 0; thit < rawPosAdcHit.GetNSampPulses(); thit++) {

        FADCHitData possampdata_raw;
        FADCHitData possampdata;

        possampdata_raw.paddle = npmt;
        possampdata_raw.Ped = rawPosAdcHit.GetSampPedRaw();
        possampdata_raw.PulseInt = rawPosAdcHit.GetSampPulseIntRaw();
        possampdata_raw.PulseAmp = rawPosAdcHit.GetSampPulseAmpRaw();
        possampdata_raw.PulseTime = rawPosAdcHit.GetSampPulseTimeRaw();
        
        possampdata.paddle = npmt;
        possampdata.Ped = rawPosAdcHit.GetSampPed();
        possampdata.PulseInt = rawPosAdcHit.GetSampPulseInt();
        possampdata.PulseAmp = rawPosAdcHit.GetSampPulseAmp();
        possampdata.PulseTime = rawPosAdcHit.GetSampPulseTime();

        fPosSampDataRaw.emplace_back(possampdata_raw);
        fPosSampData.emplace_back(possampdata);

        if ( rawPosAdcHit.GetNPulses() ==0 || fUseSampWaveform ==1 ) {

          errorflag = 3;
          if(fUseSampWaveform) errorflag = 0;

          fPosDataRaw.emplace_back(possampdata_raw);
          fPosData.emplace_back(possampdata);
        }
      }// samp pulse loop
    }
    fPosErrorFlag.emplace_back(errorflag);

    // Negative PMT
    errorflag = 999;
    if ( fUseSampWaveform == 0 ) {
      for (UInt_t thit = 0; thit < rawNegAdcHit.GetNPulses(); thit++) {

      FADCHitData negdata_raw;
      FADCHitData negdata;

      negdata_raw.paddle = npmt;
      negdata_raw.Ped = rawNegAdcHit.GetPedRaw();
      negdata_raw.PulseInt = rawNegAdcHit.GetPulseIntRaw();
      negdata_raw.PulseAmp = rawNegAdcHit.GetPulseAmpRaw();
      negdata_raw.PulseTime = rawNegAdcHit.GetPulseTimeRaw();
       
      negdata.paddle = npmt;
      negdata.Ped = rawNegAdcHit.GetPed();
      negdata.PulseInt = rawNegAdcHit.GetPulseInt();
      negdata.PulseAmp = rawNegAdcHit.GetPulseAmp();
      negdata.PulseTime = rawNegAdcHit.GetPulseTime();

      if(negdata_raw.PulseAmp> 0) errorflag = 0;
      if(negdata_raw.PulseAmp <= 0) errorflag = 1;
      if(negdata_raw.PulseAmp <= 0 && rawNegAdcHit.GetNSamples() > 0) errorflag = 2;

      fNegDataRaw.emplace_back(negdata_raw);
      fNegData.emplace_back(negdata);
      // FIXME: Add an option to use pedestal from DB
      }
    }
    if (rawNegAdcHit.GetNSamples() >0 ) {
      rawNegAdcHit.SetSampThreshold(fSampThreshold);
      if (fSampNSA == 0) fSampNSA=rawNegAdcHit.GetF250_NSA();
      if (fSampNSB == 0) fSampNSB=rawNegAdcHit.GetF250_NSB();
      rawNegAdcHit.SetF250Params(fSampNSA,fSampNSB,4); // Set NPED =4
      if (fSampNSAT != 2) rawNegAdcHit.SetSampNSAT(fSampNSAT);
      rawNegAdcHit.SetSampIntTimePedestalPeak();
      
      // FIXME: Do we want to save waveform data?
      for (UInt_t thit = 0; thit < rawNegAdcHit.GetNSampPulses(); thit++) {

        FADCHitData negsampdata_raw;
        FADCHitData negsampdata;

        negsampdata_raw.paddle = npmt;
        negsampdata_raw.Ped = rawNegAdcHit.GetSampPedRaw();
        negsampdata_raw.PulseInt = rawNegAdcHit.GetSampPulseIntRaw();
        negsampdata_raw.PulseAmp = rawNegAdcHit.GetSampPulseAmpRaw();
        negsampdata_raw.PulseTime = rawNegAdcHit.GetSampPulseTimeRaw();
        
        negsampdata.paddle = npmt;
        negsampdata.Ped = rawNegAdcHit.GetSampPed();
        negsampdata.PulseInt = rawNegAdcHit.GetSampPulseInt();
        negsampdata.PulseAmp = rawNegAdcHit.GetSampPulseAmp();
        negsampdata.PulseTime = rawNegAdcHit.GetSampPulseTime();

        fNegSampDataRaw.emplace_back(negsampdata_raw);
        fNegSampData.emplace_back(negsampdata);

        if ( rawNegAdcHit.GetNPulses() ==0 || fUseSampWaveform ==1 ) {

          errorflag = 3;
          if(fUseSampWaveform) errorflag = 0;

          fNegDataRaw.emplace_back(negsampdata_raw);
          fNegData.emplace_back(negsampdata);
        }
      }// samp pulse loop
    }// Negative PMT
    fNegErrorFlag.emplace_back(errorflag);

    ihit++;
  }// while
  return ihit;
}

//_____________________________________________________________________
Int_t HYPCherenkov::CoarseProcess( TClonesArray& tracks )
{
  // Do nothing here. 
  // Reconstruction should be done in each derived class for AC and WC
  return 0;

}

//_____________________________________________________________________
Int_t HYPCherenkov::FineProcess( TClonesArray& tracks )
{
  return 0;
}

//_____________________________________________________________________

ClassImp(HYPCherenkov)

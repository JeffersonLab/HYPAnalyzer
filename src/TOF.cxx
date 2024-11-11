// Class for TOF detectors

#include "TOF.h"
#include "THaEvData.h"
#include "THaGlobals.h"
#include "THaVarList.h"
#include "VarDef.h"
#include "VarType.h"
#include "THaApparatus.h"

#include <iostream>

using namespace std;

//________________________________________________________________
TOF::TOF( const char* name, const char* description,
		      THaApparatus* apparatus) :
  THaNonTrackingDetector(name, description, apparatus)
{

}

//________________________________________________________________
TOF::~TOF()
{
  // Destructor

}

//________________________________________________________________
THaAnalysisObject::EStatus TOF::Init( const TDatime& date )
{

 EStatus status;
  if((status = THaNonTrackingDetector::Init( date )))
    return fStatus = status;

  fPresentP = 0;
  THaVar* vpresent = gHaVars->Find(Form("%s.present", GetApparatus()->GetName()));
  if(vpresent) {
    fPresentP = (Bool_t *)vpresent->GetValuePointer();
  }
  return fStatus = kOK;

}

//________________________________________________________________
void TOF::Clear( Option_t* opt )
{
  fNhits = 0;
  
}

//________________________________________________________________
Int_t TOF::Decode( const THaEvData& evdata )
{

  /*
  Bool_t present = kTRUE;
  if(fPresentP) {
    present = *fPresentP;
  }
  fNhits = DecodeToHitList(evdata, !present);

  return fNhits;
  */

  return 0;
}

//________________________________________________________________
Int_t TOF::ReadDatabase( const TDatime& date )
{

  return kOK;
}

//________________________________________________________________
Int_t TOF::DefineVariables( EMode mode )
{

  return 0;
}

//________________________________________________________________
Int_t TOF::CoarseProcess( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________
Int_t TOF::FineProcess( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________
Int_t TOF::End(THaRunBase* run)
{
  MissReport(Form("%s.%s", GetApparatus()->GetName(), GetName()));
  return 0;
}

ClassImp(TOF)

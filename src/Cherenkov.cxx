// Class for Cherenkov detectors

#include "Cherenkov.h"
#include "THaEvData.h"
#include "THaGlobals.h"
#include "THaVarList.h"
#include "VarDef.h"
#include "VarType.h"
#include "THaApparatus.h"

#include <iostream>

using namespace std;

//________________________________________________________________
Cherenkov::Cherenkov( const char* name, const char* description,
		      THaApparatus* apparatus) :
  THaNonTrackingDetector(name, description, apparatus)
{

}

//________________________________________________________________
Cherenkov::~Cherenkov()
{
  // Destructor

}

//________________________________________________________________
THaAnalysisObject::EStatus Cherenkov::Init( const TDatime& date )
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
void Cherenkov::Clear( Option_t* opt )
{
  fNhits = 0;
  
}

//________________________________________________________________
Int_t Cherenkov::Decode( const THaEvData& evdata )
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
Int_t Cherenkov::ReadDatabase( const TDatime& date )
{

  return kOK;
}

//________________________________________________________________
Int_t Cherenkov::DefineVariables( EMode mode )
{

  return 0;
}

//________________________________________________________________
Int_t Cherenkov::CoarseProcess( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________
Int_t Cherenkov::FineProcess( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________

ClassImp(Cherenkov)

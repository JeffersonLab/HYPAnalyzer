// Class for Drift Chamber

#include "DC.h"
#include "THaEvData.h"
#include "THaGlobals.h"
#include "THaVarList.h"
#include "VarDef.h"
#include "VarType.h"
#include "THaApparatus.h"

#include <iostream>

using namespace std;

//________________________________________________________________
DC::DC(const char* name, const char* description,
       THaApparatus* apparatus) :
  THaTrackingDetector(name, description, apparatus)
{

}

//________________________________________________________________
DC::~DC()
{
  // Destructor

}

//________________________________________________________________
THaAnalysisObject::EStatus DC::Init( const TDatime& date )
{

  // std::cout << "DC::Init" << std::endl;

  EStatus status;
  if((status = THaTrackingDetector::Init( date )))
    return fStatus = status;

  fPresentP = 0;
  THaVar* vpresent = gHaVars->Find(Form("%s.present", GetApparatus()->GetName()));
  if(vpresent) {
    fPresentP = (Bool_t *)vpresent->GetValuePointer();
  }
  return fStatus = kOK;
}
//________________________________________________________________
void DC::Clear( Option_t* opt )
{
  fNhits = 0;

}

//________________________________________________________________
Int_t DC::ReadDatabase( const TDatime& date )
{
  // Read parameters 
  // Called by ThaDetectorBase::Init()

  return kOK;
}

//________________________________________________________________
Int_t DC::Decode( const THaEvData& evdata )
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
Int_t DC::DefineVariables( EMode mode )
{

  return 0;
}

//________________________________________________________________
Int_t DC::CoarseTrack( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________
Int_t DC::FineTrack( TClonesArray& tracks )
{
  return 0;
}

//________________________________________________________________

ClassImp(DC)

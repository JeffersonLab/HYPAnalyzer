#include "HKSSpectrometer.h"

ClassImp(HKSSpectrometer)

//_____________________________________________________________________________
HKSSpectrometer::HKSSpectrometer( const char* name, const char* description ) :
  THaSpectrometer( name, description )
{
  //Default constructor
}

//_____________________________________________________________________________
HKSSpectrometer::~HKSSpectrometer()
{
  // Destructor
  DefineVariables( kDelete );

}

//_____________________________________________________________________________
Int_t HKSSpectrometer::ReadDatabase( const TDatime& date )
{

  return kOK;
  
}

//_____________________________________________________________________________
Int_t HKSSpectrometer::ReadRunDatabase( const TDatime& date )
{

  return kOK;
  
}

//_____________________________________________________________________________
Int_t HKSSpectrometer::DefineVariables( EMode mode )
{

  return kOK;

}

//_____________________________________________________________________________
Int_t HKSSpectrometer::FindVertices( TClonesArray& tracks )
{

  return 0;
}

//_____________________________________________________________________________
Int_t HKSSpectrometer::TrackCalc()
{

  return 0;
}

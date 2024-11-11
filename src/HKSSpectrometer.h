#ifndef HKSSpectrometer_h
#define HKSSpectrometer_h

#include "THaSpectrometer.h"

class HKSSpectrometer : public THaSpectrometer {
 public:  
  HKSSpectrometer( const char* name, const char* description );
  virtual ~HKSSpectrometer();

  virtual Int_t FindVertices( TClonesArray& tracks );
  virtual Int_t TrackCalc();

 protected:

  virtual Int_t ReadDatabase( const TDatime& date );
  virtual Int_t ReadRunDatabase( const TDatime& date );
  virtual Int_t DefineVariables( EMode mode = kDefine );

  ClassDef(HKSSpectrometer,0)

};

#endif /* HKSSpectrometer_h */

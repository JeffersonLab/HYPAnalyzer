#ifndef HYPDC_h
#define HYPDC_h

#include "THaTrackingDetector.h"
#include "HYPDCPlane.h"

class HYPDC : public THaTrackingDetector {
 public:
  HYPDC(const char* name, const char* description="",
     THaApparatus* apparatus = NULL);
  virtual ~HYPDC();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t   Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& run_time );
  virtual Int_t   CoarseTrack( TClonesArray& tracks );
  virtual Int_t   FineTrack( TClonesArray& tracks );
  
 protected:
  
  Int_t fNPlanes;
  std::vector<HYPDCPlane*> fPlanes;
  
  virtual Int_t   ReadDatabase( const TDatime& date );
  virtual Int_t   DefineVariables( EMode mode = kDefine );

  ClassDef(HYPDC,0)

};

#endif

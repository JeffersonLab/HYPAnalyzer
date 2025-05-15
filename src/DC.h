#ifndef DC_h
#define DC_h

// Drift Chamber detector class

#include "TClonesArray.h"
#include "THaTrackingDetector.h"

class DC : public THaTrackingDetector {
 public:
  DC(const char* name, const char* description="",
     THaApparatus* apparatus = NULL);
  virtual ~DC();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t   Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& run_time );
  virtual Int_t   CoarseTrack( TClonesArray& tracks );
  virtual Int_t   FineTrack( TClonesArray& tracks );
  
 protected:

  Int_t   fNhits;
  Bool_t* fPresentP;
  
  virtual Int_t   ReadDatabase( const TDatime& date );
  virtual Int_t   DefineVariables( EMode mode = kDefine );

  ClassDef(DC,0)

};

#endif

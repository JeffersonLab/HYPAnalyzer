#ifndef Cherenkov_h
#define Cherenkov_h

// Cherenkov detector class

#include "TClonesArray.h"
#include "THaNonTrackingDetector.h"
#include "THcHitList.h"

class Cherenkov : public THaNonTrackingDetector, public THcHitList {
 public:
  Cherenkov(const char* name, const char* description="",
	    THaApparatus* apparatus = NULL);
  virtual ~Cherenkov();

  virtual void    Clear( Option_t* opt="" );
  virtual Int_t   Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& date );
  virtual Int_t   End( THaRunBase *r = 0 );
  virtual Int_t   CoarseProcess( TClonesArray& tracks );
  virtual Int_t   FineProcess( TClonesArray& tracks );
  
 protected:

  Int_t fNhits;
  Bool_t fPresentP;

  virtual Int_t ReadDatabase( const TDatime& date );
  virtual Int_t DefineVariables( EMode mode = kDefine );
  
  ClassDef(Cherenkov,0)

};

#endif

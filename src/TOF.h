#ifndef TOF_h
#define TOF_h

// TOF detector class

#include "TClonesArray.h"
#include "THaNonTrackingDetector.h"
#include "THcHitList.h"

class TOF : public THaNonTrackingDetector, public THcHitList {
 public:
  TOF(const char* name, const char* description="",
	    THaApparatus* apparatus = NULL);
  virtual ~TOF();

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
  
  ClassDef(TOF,0)

};

#endif

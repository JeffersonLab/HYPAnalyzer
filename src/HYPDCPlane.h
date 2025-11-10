#ifndef HYPDCPlane_h
#define HYPDCPlane_h

#include "THaSubDetector.h"
#include "TClonesArray.h"
#include "HYPData.h"

using namespace std;
using namespace HYPData;

namespace DC {
  enum Axis{ kX, kU, kV};
}

class HYPDC;

class HYPDCPlane : public THaSubDetector {
  public:
    HYPDCPlane( const char *name, const char* description, THaDetectorBase *parent = nullptr );
    virtual ~HYPDCPlane();

    virtual void    Clear( Option_t *opt = "" );
    virtual EStatus Init( const TDatime &date );
    virtual Int_t   Decode( const THaEvData& );
    virtual Int_t   CoarseProcess( TClonesArray& tracks );
    virtual Int_t   FineProcess( TClonesArray& tracks );
    
    Int_t SetAxis(Int_t axis) { return fAxis = axis; }
    Int_t GetAxis() { return fAxis; }
//    virtual Int_t   Print( Option_t* opt ="" ) const;

  protected:

    Int_t fNHits; // Total number of hits decoded
    Int_t fAxis;

    virtual Int_t ReadDatabase( const TDatime &date );
    virtual Int_t DefineVariables( EMode mode = kDefine );
    virtual Int_t ReadGeometry( FILE* file, const TDatime& date, Bool_t required = false);
    
    HYPDC* fDC; // parent detector
    std::vector<TDCHit> fTDCHit;

  ClassDef(HYPDCPlane, 0);

};

#endif
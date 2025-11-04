#ifndef HYPTOFPlane_h
#define HYPTOFPlane_h

#include "THaSubDetector.h"
#include "TClonesArray.h"
#include "Decoder.h"
#include "Fadc250Module.h"
#include "HYPData.h"

using namespace std;
using namespace HYPData;

class HYPTOFDetector;

class HYPTOFPlane : public THaSubDetector {
  public:
    HYPTOFPlane(const char *name, const char* description, const Int_t iplane, THaDetectorBase *parent = nullptr);
    virtual ~HYPTOFPlane();
    
    virtual void    Clear( Option_t *opt = "" );
    virtual EStatus Init( const TDatime &date );
    virtual Int_t   Decode( const THaEvData& );
    virtual Int_t   CoarseProcess( TClonesArray& tracks );
    virtual Int_t   FineProcess( TClonesArray& tracks );
//    virtual Int_t   Print( Option_t* opt ="" ) const;

    Int_t GetNHits() { return fNHits; }

  protected:

    Int_t fNHits; // Total number of hits decoded

    virtual Int_t ReadDatabase( const TDatime &date );
    virtual Int_t DefineVariables( EMode mode = kDefine );
    virtual Int_t ReadGeometry( FILE* file, const TDatime& date,
              Bool_t required = false);
    virtual Int_t StoreHit( const DigitizerHitInfo_t& hitinfo, UInt_t data );
    
    OptUInt_t LoadData( const THaEvData& evdata, const DigitizerHitInfo_t& hitinfo ) override;

    HYPTOFDetector* fTOF; // parent detector
    FADCData* fFADCData;

  ClassDef(HYPTOFPlane, 0);

};

#endif
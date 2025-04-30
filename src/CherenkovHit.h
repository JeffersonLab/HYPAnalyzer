#include "TObject.h"

class CherenkovHit : public TObject {
 public:
    CherenkovHit();

    virtual CherenkovHit() {};

 protected:
    Int_t fTDC;
    Int_t fADC;
    Double_t fADC_Ped;
    Double_t fADC_Peak;
    Double_t fADC_Time;
    
 private:
    CherenkovHit( const CherenkovHit& );
    CherenkovHit& operator=( const CherenkovHit& );

    ClassDef(CherenkovHit,0)
};

#endif
#ifndef HYPDATA_H
#define HYPDATA_H

#include "THaDetMap.h"
#include "DataType.h"
#include <vector>

// HYP raw data obj: FADC250 and vfTDC

namespace HYPData {

  struct FADCHit {
    UInt_t fChan;
    UInt_t fPulseIntegral;
    UInt_t fPulsePeak;
    UInt_t fPulseTime;
    UInt_t fPedestal;    
    UInt_t fCoarseTime;
    UInt_t fFineTime;
  };

  struct TDCHit {
    Data_t fTimeLE;
    Data_t fTimeTE;
    Data_t fTime;
  };

  // FADC config parameters
  struct FADCConfig {
    UInt_t NSA;
    UInt_t NSB;
    UInt_t NPED;
  };
  
  class FADCData {
  public:  
    FADCData() : fNHits(0) {}
    
    virtual ~FADCData() {}

    Int_t      AddHit( const DigitizerHitInfo_t& hitinfo );
    Int_t      GetNHits() { return fNHits; }
    size_t     GetSize() const { return fPulseData.size(); }
    FADCHit&   GetData( size_t i ) { return fPulseData[i]; }
    std::vector<uint32_t>& GetSampleData() { return fSampleData; }
    void       Clear();
    std::vector<FADCHit>& GetPulseData() { return fPulseData; }

  protected:  

    std::vector<FADCHit> fPulseData;
    std::vector<uint32_t> fSampleData;
  
    Int_t fNHits;
  };

  // TDC module data
  // class TDCData : Podd::TDCData {
  class TDCData {
  public:
    TDCData() {}
    virtual ~TDCData() {}  

    Int_t      AddHit( const DigitizerHitInfo_t& hitinfo, UInt_t data );
    TDCHit& GetData( size_t i ) { return fTDC[i]; }

  protected:

    std::vector<TDCHit> fTDC;
    Int_t fNHits;
  };

} // namespace HYPData

#endif

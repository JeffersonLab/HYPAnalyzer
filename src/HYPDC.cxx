#include "HYPDC.h"

//________________________________________________________________
HYPDC::HYPDC(const char* name, const char* description,
       THaApparatus* apparatus) :
  THaTrackingDetector(name, description, apparatus), fNPlanes(1)
{

}

//________________________________________________________________
HYPDC::~HYPDC()
{
  // Destructor
  RemoveVariables();
  for(auto plane : fPlanes )
    delete plane;
  fPlanes.clear();

}

//________________________________________________________________
THaAnalysisObject::EStatus HYPDC::Init( const TDatime& date )
{

  // std::cout << "HYPDC::Init" << std::endl;

  EStatus status;
  if((status = THaTrackingDetector::Init( date )))
    return fStatus = status;

  // Init sub detectors
  for(auto &plane : fPlanes ){
    status = plane->Init(date);
    if(status != kOK)
      return fStatus = status;
  }

  return fStatus = kOK;
}
//________________________________________________________________
void HYPDC::Clear( Option_t* opt )
{

}

//________________________________________________________________
Int_t HYPDC::ReadDatabase( const TDatime& date )
{
  // Read parameters 
  // Called by ThaDetectorBase::Init()
    FILE* file = OpenFile( date );
    if( !file ) return kFileError;

    string plane_name_str;
    DBRequest request[] = {
        {"nplanes", &fNPlanes, kInt},
        {"names",   &plane_name_str, kString},
        {nullptr}
    };

    Int_t err = LoadDB(file, date, request);
    if(err) {
        fclose(file);
        return err;
    }

    // Get the plane names: 1x1, 1x2, 1u1, ...
    vector<string> plane_names;
    size_t pos1 = 0; 
    size_t pos2 = plane_name_str.find(",");
    while( pos2 != string::npos ) {
      string temp = plane_name_str.substr(pos1, pos2 - pos1);
      plane_names.push_back(temp);
      pos1 = pos2 + 1;
      pos2 = plane_name_str.find(",",pos1);
    }

    // Define planes
    for(Int_t i = 0; i < fNPlanes; i++) {
        fPlanes.emplace_back(new HYPDCPlane(Form("%s", plane_names[i].c_str()), Form("DC Plane %s", plane_names[i].c_str()), this));
    }

  return kOK;
}

//________________________________________________________________
Int_t HYPDC::Decode( const THaEvData& evdata )
{
  for(Int_t i = 0; i < fNPlanes; i++){
    fPlanes[i]->Decode(evdata);
  }

  return 0;
}

//________________________________________________________________
Int_t HYPDC::DefineVariables( EMode mode )
{

  return 0;
}

//________________________________________________________________
Int_t HYPDC::CoarseTrack( TClonesArray& tracks )
{

  return 0;
}

//________________________________________________________________
Int_t HYPDC::FineTrack( TClonesArray& tracks )
{
  return 0;
}

//________________________________________________________________

ClassImp(HYPDC)

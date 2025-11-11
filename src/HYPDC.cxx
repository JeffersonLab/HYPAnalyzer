#include "HYPDC.h"
#include <sstream>

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
    // remove ""
    plane_name_str.erase(0,1);
    plane_name_str.pop_back();
    stringstream ss(plane_name_str);
    string temp_name;
    while(ss >> temp_name)
      plane_names.emplace_back(temp_name);
    
    // Define planes
    for(Int_t i = 0; i < fNPlanes; i++) {
    //  cout << "Plane Names: " << plane_names[i] << endl;
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

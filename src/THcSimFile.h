/////////////////////////////////////////////////////////////////////
//
//   SBSSimFile
//
//   Interface to an input file with simulated SoLID data
//
//   Ole Hansen (ole@jlab.org)  December 2011
//
/////////////////////////////////////////////////////////////////////

#ifndef __THcSimFile_h
#define __THcSimFile_h

#include "THaRunBase.h"
#include "TString.h"
#include "THcSimEvent.h"
#include "ha_compiledata.h"

#include <set>

class TFile;
class TTree;
class TBranch;
class THcSimEvent;
 
//const char* treeName = "T";
#define treeName "T"
class THcSimFile : public THaRunBase {
 public:
  THcSimFile(const char* filename, const char *experiment="gmn", const char* description = "");
  //THcSimFile(const char* filename, const char* description, std::vector<TString> det_list);
  THcSimFile(const THcSimFile &run);
  virtual ~THcSimFile();
  virtual THcSimFile &operator=(const THaRunBase &rhs);
  // for ROOT RTTI
  THcSimFile() : fROOTFile(0), fTree(0), fEvent(0), fEntry(0) {}

  virtual void  Print( Option_t* opt="" ) const;

  Int_t         Close();
  virtual Int_t Compare( const TObject* obj ) const;
#if ANALYZER_VERSION_CODE >= 67072  // ANALYZER_VERSION(1,6,0)
  const UInt_t* GetEvBuffer() const;
#else
  const  Int_t* GetEvBuffer() const;
#endif
  Int_t         Init();
  const char*   GetFileName() const { return fROOTFileName.Data(); }
  Int_t         Open();
  Int_t         ReadEvent();
  void          SetFileName( const char* name ) { fROOTFileName = name; }

  void          SetVerbose(int v){fVerbose = v;};
  void          GetExperiment(const char* experiment);
  
 protected:
  virtual Int_t ReadDatabase();

  TString fROOTFileName;  //  Name of input file
  TFile* fROOTFile;       //! Input ROOT file
  TTree* fTree;           //! Input Tree with simulation data
  THcSimEvent* fEvent;   //! Current event

  //std::vector<TString> fDetList;
  
  ULong64_t fNEntries;    //! Number of entries in tree
  ULong64_t fEntry;       //! Current entry number

  Int_t fVerbose;       //! Current entry number

  //TString fExperiment;
  //std::set<TString> fValidExperiments;

  std::set<Exp_t> fValidExperiments;
  Exp_t fExperiment;
  
  ClassDef(THcSimFile,1) // Interface to input file with simulated SoLID data
};

#endif

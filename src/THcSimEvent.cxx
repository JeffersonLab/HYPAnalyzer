#include <iostream>
#include "THcSimEvent.h"
#include "TTree.h"

//_____________________________________________________________________________
//THcSimEvent::THcSimEvent(TTree* tree, TString experiment) {
THcSimEvent::THcSimEvent(TTree* tree, Exp_t experiment) {
  std::cout << "Initializing THcSimEvent" << std::endl;
  RunID = EvtID = 0;

  fExperiment = experiment;

  //Now we need to initialize the appropriate Tree structure based on experiment:
  //We should probably use an enum or something simple to make this less clunky than doing a string comparison each time we open the file
  //or load the event:

  Tdig = new tree_digitized(tree);

  Clear();
}

//_____________________________________________________________________________
void THcSimEvent::Clear( const Option_t* opt )
{
  // do nothing...
}

//_____________________________________________________________________________
void THcSimEvent::Print( const Option_t* opt ) const
{
  //std::cout << RunID << " " << EvtID << " " << ev_sigma*ev_solang << std::endl;
}

//_____________________________________________________________________________
Int_t THcSimEvent::GetEntry( Long64_t entry )
{
  EvtID = entry;

  return Tdig->GetEntry(entry);
}

//-----------------------------------------------------------------------------
ClassImp(THcSimEvent)

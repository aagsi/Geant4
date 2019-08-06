// ====================================================================
//   TrackerSD.cc
//
// ====================================================================
#include "G4VPhysicalVolume.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4SystemOfUnits.hh"
#include "TrackerSD.hh"
#include "TrackerHit.hh"
//#include "AnaStudio.hh"

//////////////////////////////////////////
TrackerSD::TrackerSD(const G4String& name)
  : G4VSensitiveDetector(name)
//////////////////////////////////////////
{
}

///////////////////////
TrackerSD::~TrackerSD()
///////////////////////
{
}

///////////////////////////////////////////
void TrackerSD::Initialize(G4HCofThisEvent*)
////////////////////////////////////////////
{
	
  // clear hit buffer
  hitbuf[0].clear();
  hitbuf[1].clear();
 
}

///////////////////////////////////////////////////////
G4bool TrackerSD::ProcessHits(G4Step* step, 
                                  G4TouchableHistory* )
///////////////////////////////////////////////////////
{
  G4Track* track = step-> GetTrack();
  G4double charge = track-> GetParticleDefinition()-> GetPDGCharge();
  if (charge == 0.) return false;

  // get step information from "PreStepPoint"
  const G4StepPoint* preStepPoint= step-> GetPreStepPoint();
  G4TouchableHistory* touchable=
    (G4TouchableHistory*)(preStepPoint-> GetTouchable());
  G4int id= touchable-> GetReplicaNumber();

  G4int tid = track-> GetTrackID();
  G4int pid = track-> GetParticleDefinition()-> GetPDGEncoding();
  G4ThreeVector pos = preStepPoint-> GetPosition();
  G4double mom = (track-> GetMomentum()).mag();
  G4double de= step-> GetTotalEnergyDeposit();
  G4double time = track-> GetGlobalTime();
  
  if (time > 100.*ns) return false; // timing cut


  if (hitbuf[id].find(tid) == hitbuf[id].end()) {
    hitbuf[id][tid] = new TrackerHit(pid, tid, pos.x(), pos.y(), mom, 0., time);
  }
  hitbuf[id][tid]-> AccumulateEdep(de);
 
 G4cout<< "################## time  "<<time<<G4endl;

  return true;
}

/////////////////////////////////////////////
void TrackerSD::EndOfEvent(G4HCofThisEvent* )
/////////////////////////////////////////////
{
  
//  AnaStudio* AS = AnaStudio::GetAnaStudio();
//
//  std::map<G4int, TrackerHit*>::iterator p;
//  for(p = hitbuf[0].begin(); p != hitbuf[0].end(); p++) {
//    AS-> AddHit(p->second, 0);
//  }
//  for(p = hitbuf[1].begin(); p != hitbuf[1].end(); p++) {
//    AS-> AddHit(p->second, 1);
//  }
 
}

/////////////////////////
void TrackerSD::DrawAll()
/////////////////////////
{
}

//////////////////////////
void TrackerSD::PrintAll()
//////////////////////////
{
}


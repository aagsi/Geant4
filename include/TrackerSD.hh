// ====================================================================
//   TrackerSD.hh
//
// ====================================================================
#ifndef TRACKER_SD_H
#define TRACKER_SD_H
 
#include "G4VSensitiveDetector.hh"
#include <map>

class G4HCofThisEvent;
class G4Step;
class G4TouchableHistory;
class TrackerHit;

class TrackerSD : public G4VSensitiveDetector {
private:
  // hit buffer by track id
  std::map<G4int, TrackerHit*> hitbuf[3];

public:
  TrackerSD(const G4String& name);
  virtual ~TrackerSD();

  // virtual methods
  virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory*);
  virtual void Initialize(G4HCofThisEvent*);
  virtual void EndOfEvent(G4HCofThisEvent*);

  virtual void DrawAll();
  virtual void PrintAll(); 
 
};

#endif

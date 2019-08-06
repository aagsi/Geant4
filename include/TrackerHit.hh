// ====================================================================
//   TrackerHit.hh
//
// ====================================================================
#ifndef TRACKER_HIT_H
#define TRACKER_HIT_H
 
#include "G4VHit.hh"

class TrackerHit : public G4VHit {
private:
  G4int pid;
  G4int tid;
  G4double x;
  G4double y;
  G4double mom;
  G4double edep;
  G4double time;

public:
  TrackerHit();
  TrackerHit(G4int apid, G4int atid, G4double ax, G4double ay,
             G4double amom, G4double aedep, G4double atime);
  virtual ~TrackerHit();

  // copy constructor & assignment operator
  TrackerHit(const TrackerHit& right);
  const TrackerHit& operator=(const TrackerHit& right);
  G4int operator==(const TrackerHit& right) const;
  
  // get functions
  G4int GetPID() const { return pid; }
  G4int GetTrackID() const { return tid; }
  G4int GetX() const { return x; }
  G4int GetY() const { return y; }
  G4double GetMomentum() const { return mom; }  
  G4double GetEdep() const { return edep; }  
  G4double GetTime() const { return time; }

  void AccumulateEdep(G4double de) { edep+=de; }

  // methods
  virtual void Draw();
  virtual void Print();
};

// ====================================================================
// inline functions
// ====================================================================
inline TrackerHit::TrackerHit(const TrackerHit& right)
  : G4VHit()
{
  pid = right.pid;
  tid = right.tid;
  x = right.x;
  y = right.y;
  mom = right.mom;
  edep = right.edep;
  time = right.time; 
}

inline const TrackerHit& TrackerHit::operator=(const TrackerHit& right)
{
  pid = right.pid;
  tid = right.tid;
  x = right.x;
  y = right.y;
  mom = right.mom;
  edep = right.edep;
  time = right.time; 
  return *this;
}

inline G4int TrackerHit::operator==(const TrackerHit& right) const 
{
   return (this==&right) ? 1 : 0; 
}

#endif

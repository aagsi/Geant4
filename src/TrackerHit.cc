// ====================================================================
//   TrackerHit.cc
//
// ====================================================================
#include "TrackerHit.hh"
#include "G4SystemOfUnits.hh"
#include <iomanip>

/////////////////////////////////////////////////////////
TrackerHit::TrackerHit()
  : pid(-999), tid(-1), x(0.), y(0.), edep(0.), time(-1.)
/////////////////////////////////////////////////////////
{
}

///////////////////////////////////////////////////////////////////////////
TrackerHit::TrackerHit(G4int apid, G4int atid, G4double ax, G4double ay,
                       G4double amom, G4double aedep, G4double atime)
  : pid(apid), tid(atid), x(ax), y(ay), mom(amom), edep(aedep), time(atime)
///////////////////////////////////////////////////////////////////////////
{
}

/////////////////////////
TrackerHit::~TrackerHit()
/////////////////////////
{
}


///////////////////////
void TrackerHit::Draw()
///////////////////////
{
}

////////////////////////
void TrackerHit::Print()
////////////////////////
{
  G4cout << "Tracker Hit: ( " << pid << ", " << tid << ", " 
	 << std::setprecision(3) << x/cm << "cm, " 
	 << std::setprecision(3) << y/cm << "cm, " 
	 << std::setprecision(3) << time/ns << "ns, "
	 << std::setprecision(4) << mom/MeV << "MeV, " 
	 << std::setprecision(3) << edep/MeV << "MeV )" 
	 << G4endl;
}


#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "G4PhysicsListHelper.hh"
#include "G4ParticleTypes.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class PhysicsList: public G4VUserPhysicsList
{
public:
  PhysicsList();
  ~PhysicsList();
  
protected:
  // Construct particle and physics
  void ConstructParticle();
  void ConstructProcess();
  void SetCuts();
  
public: 
  // Set Cuts
  void SetGammaCut(G4double);
  void SetElectronCut(G4double);
  void SetPositronCut(G4double);
  void SetProtonCut(G4double);
  
  void SetGammaLowLimit(G4double);
  void SetElectronLowLimit(G4double);
  void SetGEPLowLimit(G4double);

  void SetGELowLimit(G4double);
  
private:
  
  G4double fCutForGamma;
  G4double fCutForElectron;
  G4double fCutForPositron;
  G4double fCutForProton;
  
protected:
  // these methods Construct particles 
  void ConstructBosons();
  void ConstructLeptons();
  void ConstructBarions();
  
protected:
  // these methods Construct physics processes and register them
  void ConstructGeneral();
  void ConstructEM();
  
private:
  
};
#endif




#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"

#include "TrackerSD.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{  
    // Get nist material manager
    G4NistManager* nist = G4NistManager::Instance();
    
    
    
    // Option to switch on/off checking of volumes overlaps
    //
    G4bool checkOverlaps = true;
    
    //
    // World
    //
    
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
    
    G4Box* solidWorld = new G4Box("world", 5.*m, 5.*m, 5.*m);
    
    G4LogicalVolume* worldLV =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
    
    G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      worldLV,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
    
    
    
    
    // ==============================================================
    // target
    // ==============================================================
    G4Tubs* targetSolid= new G4Tubs("targrt", 0., 50.*cm, 2.5*cm, 0., 360.*deg);
    
    
    G4Material* target_mat = nist->FindOrBuildMaterial("G4_Al");
    G4LogicalVolume* targetLV= new G4LogicalVolume(targetSolid, target_mat, "target");
    
    
    
    new G4PVPlacement(0, G4ThreeVector(0., 0., -2.5*m),
                      targetLV, "target", worldLV,
                      false, 0);
    
    // ==============================================================
    // tracker
    // ==============================================================
    G4Box* trkSolid= new G4Box("tracker", 50.*cm, 50.*cm, 5.*mm);
    
    G4Material* tracker_mat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    trkLV= new G4LogicalVolume(trkSolid, tracker_mat, "tracker");
    
    new G4PVPlacement(0, G4ThreeVector(0.,0.,0.*m),
                      trkLV, "tracker", worldLV,
                      false, 0);
    
    new G4PVPlacement(0, G4ThreeVector(0., 0., 1.*m),
                      trkLV, "tracker", worldLV,
                      false, 1);
    
    
    new G4PVPlacement(0, G4ThreeVector(0., 0., 2.*m),
                      trkLV, "tracker", worldLV,
                      false, 2);
    
    
    
    
    
    // ==============================================================
    // return the world volume
    // ==============================================================
    return physWorld;
}



void DetectorConstruction::ConstructSDandField()
{
    
    // Sensitive detectors
    TrackerSD* trackerSD = new TrackerSD("trackerSD");
    G4SDManager::GetSDMpointer()->AddNewDetector(trackerSD);
    SetSensitiveDetector("tracker",trackerSD);
    
    
    // Magnetic field
    
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

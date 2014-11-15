#ifndef ArmorClass_H
#define ArmorClass_H
#include "Misc.h"
#include "RPGObject.h"
#include "InventoryClass.h"
/*
#define HEAD      0
#define CHEST     1
#define SHOULDER  2
#define ARMS      3
#define HAND      4
#define LEGS      5
#define FEET      6
*/
namespace RPGCls
{
 namespace ArmorCls
 {
           typedef enum {All=0,Head,Chest,Shoulder,Arm,Hand,Leg,Foot} ArmorType;
           class Armor : public InventoryCls::InventoryObject
           {
                  private:
                          int iArmorValue;
                          ArmorType atType;
                          std::vector<int> vWeaknesses;
                          std::vector<int> vStrengths;
                  public:
                          Armor(int vID);            
                          Armor(int vID,std::string vName);
                          Armor(int vID,std::string vName,std::string vDescription);
                          Armor(int vID,std::string vName,std::string vDescription,ArmorType vArmorType);

                          void SetArmorValue(int Value);
                          int GetArmorValue();
                          void SetArmorType(ArmorType Value);
                          ArmorType GetArmorType();
                          void AddWeakness(int DamageTypeID);
                          void DeleteWeakness(int DamageTypeID);
                          void DeleteWeaknessAll(int DamageTypeID);
                          void AddStrength(int DamageTypeID);
                          void DeleteStrength(int DamageTypeID);
                          void DeleteStrengthAll(int DamageTypeID);
                          bool ContainsWeakness(int DamageTypeID);
                          bool ContainsStrength(int DamageTypeID);
           };
 }// ArmorCls
}// RPGCls
#endif

//---------------------------------------------------------------------------
#include "RPGClass.h"
#include "Functions.h"
#include <ctime> 
#include <iostream>
#include <stdlib.h>
//---------------------------------------------------------------------------


using namespace std;
namespace RPGCls
{

//---------------------------------------------------------------------------
RPG::RPG()
{
  uCharacterHandles=0;
  uWeaponHandles=0;
  uArmorHandles=0;
  uDamageTypeHandles=0;
  uAmmoTypeHandles=0;
  uWeaponTypeHandles=0;
  uInventoryHandles=0;
  iQuiet=1;
 vCharacters.clear();
 vWeapons.clear();
 WeaponCls::Weapon wpnNone(uWeaponHandles++);
 //Keine Waffe - wird benutzt wenn ID nicht bekannt
 
 //AttributesCls::Attributes wpnNoneAttribs;
 wpnNone.SetName("none");
 wpnNone.SetDamagePerHit(0);
// wpnNone.SetNeededAttributes(wpnNoneAttribs);
// wpnNone.ID=;
 vWeapons.push_back(wpnNone);
 InventoryCls::Inventory invNone(uInventoryHandles++);
 vInventories.push_back(invNone);
 
}
//---------------------------------------------------------------------------
WeaponCls::Weapon *RPG::GetWeaponByID(unsigned ID)
{

 for (unsigned i=0; i < vWeapons.size();i++)
    {
     if( ID == vWeapons[i].GetID())
     return &vWeapons[i];
    }
return &vWeapons[0];

}
//---------------------------------------------------------------------------
CharacterCls::Character *RPG::GetCharacterByID(unsigned ID)
{
 for (unsigned i=0; i < vCharacters.size();i++)
    {
     if( ID == vCharacters[i].GetID())
     return &vCharacters[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
attackResult RPG::attack(unsigned attackingCharID,unsigned attackedCharID,unsigned uAimAt)
{
 srand(time(NULL));
 attackResult arRet;
 CharacterCls::Character *attackingChar=GetCharacterByID(attackingCharID);
 CharacterCls::Character *attackedChar=GetCharacterByID(attackedCharID);
 //AttributesCls::Attributes attackingAttrib;
 //attackingAttrib=attackingChar->GetAttributes();
 
 WeaponCls::Weapon *RightWeapAttackingChar = GetWeaponByID(attackingChar->GetRightHandWeaponID());
 WeaponCls::Weapon *LeftWeapAttackingChar = GetWeaponByID(attackingChar->GetLeftHandWeaponID());

 WeaponCls::Weapon *RightWeapAttackedChar = GetWeaponByID(attackingChar->GetRightHandWeaponID());
 WeaponCls::Weapon *LeftWeapAttackedChar = GetWeaponByID(attackingChar->GetLeftHandWeaponID());

 //Chance to hit or chance to evade= dexterity - attacked dexterity* (strength-(weight of weapon/2)) + randon number between -50 and 50

 int iTCAttacking=attackingChar->GetAttributes()->GetDex() * (attackingChar->GetAttributes()->GetStr()- (RightWeapAttackingChar->GetWeight() /2)) + ((rand() % 100) -50);
 int iTCAttacked=attackedChar->GetAttributes()->GetDex() * (attackedChar->GetAttributes()->GetStr()  - (RightWeapAttackingChar->GetWeight() /2)) + ((rand() % 100) -50);
 int abzTPwA;
 int abzTP;
 if(!iQuiet)
 {
        cout << "[CPP] Right hand: Chance to hit :" << iTCAttacking << "\r\n";
        cout << "[CPP] Right hand: Chance to evade :" << iTCAttacked << "\r\n";
 }
 if(iTCAttacked + ((iTCAttacked * uAimAt) /100 > iTCAttacking ))
 {
        arRet.bHit=0;
        arRet.iDmg=0;
        arRet.iDmgwA=0;
        arRet.bAttackedDead=false;
 }
 else
 {
        //Schadenspunkte=Waffenschaden * (Stärke-(Waffengewicht/2))
        double dMultiply=1;
        //AttributesCls::Attributes *attackedAttrib;
        //attackedAttrib=&attackedChar->Char_Attributes;
        //if(GetArmorByID(attackedChar->ArmorID)->

        unsigned iAttackedArmorID;
        switch (uAimAt)
        {
        case AIM_AT_CHEST     : iAttackedArmorID=attackedChar->GetChestArmorID();break;
        case AIM_AT_HEAD      : iAttackedArmorID=attackedChar->GetHeadArmorID();break;
        case AIM_AT_SHOULDER  : iAttackedArmorID=attackedChar->GetShoulderArmorID();break;
        case AIM_AT_ARM      : iAttackedArmorID=attackedChar->GetArmArmorID();break;
        case AIM_AT_LEG      : iAttackedArmorID=attackedChar->GetLegArmorID();break;
        case AIM_AT_HAND      : iAttackedArmorID=attackedChar->GetHandArmorID();break;
        case AIM_AT_FOOT      : iAttackedArmorID=attackedChar->GetFootArmorID();break;
        }
        if(GetArmorByID(iAttackedArmorID)->ContainsWeakness(RightWeapAttackingChar->GetDamageTypeID()))
        {
           cout << RightWeapAttackingChar->GetName() << " does more damage to " << GetArmorByID(iAttackedArmorID)->GetName();                                                                                                 
           dMultiply=0.5;   
        }                                                                                

        if(GetArmorByID(iAttackedArmorID)->ContainsStrength(RightWeapAttackingChar->GetDamageTypeID()))
        {
           cout << RightWeapAttackingChar->GetName() << " does lesser damage to " << GetArmorByID(iAttackedArmorID)->GetName();                                                                                                 
           dMultiply=2;   
        }  
        // int abzTP;
        abzTPwA=RightWeapAttackingChar->GetDamagePerHit() *(attackingChar->GetAttributes()->GetStr() - (RightWeapAttackingChar->GetWeight() /2));                                                                     
        abzTP=RightWeapAttackingChar->GetDamagePerHit() *(attackingChar->GetAttributes()->GetStr() - (RightWeapAttackingChar->GetWeight() /2)) - (GetArmorByID(iAttackedArmorID)->GetArmorValue() * dMultiply);
 }
 iTCAttacking=attackingChar->GetAttributes()->GetDex() * (attackingChar->GetAttributes()->GetStr()- (LeftWeapAttackingChar->GetWeight() /2)) + ((rand() % 100) -50);
 iTCAttacked=attackedChar->GetAttributes()->GetDex() * (attackedChar->GetAttributes()->GetStr()  - (LeftWeapAttackingChar->GetWeight() /2)) + ((rand() % 100) -50);
 if(!iQuiet)
 {
        cout << "[CPP] Right hand: Chance to hit :" << iTCAttacking << "\r\n";
        cout << "[CPP] Right hand: Chance to evade :" << iTCAttacked << "\r\n";
 }
 if(iTCAttacked + ((iTCAttacked * uAimAt) /100 > iTCAttacking ))
 {
        arRet.bHit=0;
        arRet.iDmg=0;
        arRet.iDmgwA=0;
        arRet.bAttackedDead=true;
 }
 else
 {
        //Schadenspunkte=Waffenschaden * (Stärke-(Waffengewicht/2))
        double dMultiply=1;
        //AttributesCls::Attributes *attackedAttrib;
        //attackedAttrib=&attackedChar->Char_Attributes;
        //if(GetArmorByID(attackedChar->ArmorID)->

        unsigned iAttackedArmorID;
        switch (uAimAt)
        {
        case AIM_AT_CHEST     : iAttackedArmorID=attackedChar->GetChestArmorID();break;
        case AIM_AT_HEAD      : iAttackedArmorID=attackedChar->GetHeadArmorID();break;
        case AIM_AT_SHOULDER  : iAttackedArmorID=attackedChar->GetShoulderArmorID();break;
        case AIM_AT_ARM      : iAttackedArmorID=attackedChar->GetArmArmorID();break;
        case AIM_AT_LEG      : iAttackedArmorID=attackedChar->GetLegArmorID();break;
        case AIM_AT_HAND      : iAttackedArmorID=attackedChar->GetHandArmorID();break;
        case AIM_AT_FOOT      : iAttackedArmorID=attackedChar->GetFootArmorID();break;
        }
        if(GetArmorByID(iAttackedArmorID)->ContainsWeakness(LeftWeapAttackingChar->GetDamageTypeID()))
        {
           cout << LeftWeapAttackingChar->GetName() << " does more damage to " << GetArmorByID(iAttackedArmorID)->GetName();                                                                                                 
           dMultiply=0.5;   
        }                                                                                

        if(GetArmorByID(iAttackedArmorID)->ContainsStrength(LeftWeapAttackingChar->GetDamageTypeID()))
        {
           cout << LeftWeapAttackingChar->GetName() << " does lesser damage to " << GetArmorByID(iAttackedArmorID)->GetName();                                                                                                 
           dMultiply=2;   
        }  
        // int abzTP;

        abzTPwA+=LeftWeapAttackingChar->GetDamagePerHit() *(attackingChar->GetAttributes()->GetStr() - (LeftWeapAttackingChar->GetWeight() /2));                                                                     
        abzTP+=LeftWeapAttackingChar->GetDamagePerHit() *(attackingChar->GetAttributes()->GetStr() - (LeftWeapAttackingChar->GetWeight() /2)) - (GetArmorByID(iAttackedArmorID)->GetArmorValue() * dMultiply);
        
        arRet.bHit=1;
        arRet.iDmg=abzTP;
        arRet.iDmgwA=abzTPwA;
        attackedChar->GetAttributes()->SetTP(attackedChar->GetAttributes()->GetTP() -abzTP);
        cout << attackingChar->GetAttributes()->GetTP() << endl;
        if(attackedChar->GetAttributes()->GetTP() <= 0)
        {
         arRet.bAttackedDead=1;
        }
        else
        {
         arRet.bAttackedDead=0;
        }
 }

 return arRet;
}
//---------------------------------------------------------------------------
int RPG::addWeapon(string asName,int wTypeID,int DamagePerHit/*,AttributesCls::Attributes NeededAttr*/,int Weight)
{
 unsigned iNewID=uWeaponHandles++;
 WeaponCls::Weapon wTemp(iNewID);
 wTemp.SetName(asName);
 wTemp.SetTypeID(wTypeID);
 wTemp.SetDamagePerHit(DamagePerHit);
 //wTemp.SetNeededAttributes(NeededAttr);
 //wTemp.ID=uWeaponHandles++;
 wTemp.SetWeight(Weight);
  
 vWeapons.push_back(wTemp);
 return iNewID;//wTemp.GetID();
}
//---------------------------------------------------------------------------
int RPG::addCharacter(std::string sName)
{
 unsigned iNewID=uCharacterHandles++;
 CharacterCls::Character tempChar(iNewID);
 tempChar.SetName(sName);
 vCharacters.push_back(tempChar);
 return iNewID;//tempChar.GetID();
}
//---------------------------------------------------------------------------
int RPG::addDamageType(std::string sName,std::string  sDescription)
{
 unsigned iNewID=uDamageTypeHandles++;
// cout << iNewID << endl;
 RPG_Misc::DamageType tempDmgType(iNewID);
 tempDmgType.SetName(sName);
 tempDmgType.SetDescription(sDescription);
 vDamageTypes.push_back(tempDmgType);
 return iNewID;//tempDmgType.GetID();
}
//---------------------------------------------------------------------------
int RPG::addAmmoType(std::string sName,std::string sDescription,unsigned DamageTypeID)
{
 unsigned iNewID=uAmmoTypeHandles++;
 WeaponCls::AmmoType tempAmmoType(iNewID);
// tempAmmoType.SetID();
 tempAmmoType.SetName(sName);
 tempAmmoType.SetDescription(sDescription);
 tempAmmoType.SetDamageTypeID(DamageTypeID);
 vAmmoTypes.push_back(tempAmmoType);
 return iNewID;//tempAmmoType.GetID();
}
//---------------------------------------------------------------------------
int RPG::addWeaponType(std::string sName,std::string sDescription,unsigned AmmoTypeID)
{
 unsigned iNewID=uWeaponTypeHandles++;
 WeaponCls::WeaponType tempWeaponType(iNewID);
// tempWeaponType.ID=uWeaponTypeHandles++;
 tempWeaponType.SetName(sName);
 tempWeaponType.SetDescription(sDescription);
 tempWeaponType.SetAmmoTypeID(AmmoTypeID);
 vWeaponTypes.push_back(tempWeaponType);
 return iNewID;//tempWeaponType.GetID();
}
//---------------------------------------------------------------------------
int RPG::addArmor(std::string asName,std::string sDescription)
{
 unsigned iNewID = uArmorHandles++;
 ArmorCls::Armor tempArmor(iNewID);
 tempArmor.SetName(asName);
 tempArmor.SetDescription(sDescription);
 vArmors.push_back(tempArmor);
 return iNewID;//tempArmor.GetID();
}
//---------------------------------------------------------------------------
int RPG::addInventory(std::string sName,std::string sDescription,int iMaxStorage)
{
 unsigned iNewID = uInventoryHandles++;
 InventoryCls::Inventory tempInventory(iNewID);
 tempInventory.SetName(sName);
 tempInventory.SetDescription(sDescription);
 tempInventory.SetMaxStorage(iMaxStorage);
 vInventories.push_back(tempInventory);
 return iNewID;
 }
//---------------------------------------------------------------------------
ArmorCls::Armor *RPG::GetArmorByID(unsigned ID)
{
 for (unsigned i=0; i < vArmors.size();i++)
    {
     if( ID == vArmors[i].GetID())
     return &vArmors[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
RPG_Misc::DamageType *RPG::GetDamageTypeByID(unsigned ID)
{
 for (unsigned i=0; i < vDamageTypes.size();i++)
    {
     if( ID == vDamageTypes[i].GetID())
     return &vDamageTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
WeaponCls::AmmoType *RPG::GetAmmoTypeByID(unsigned ID)
{
 for (unsigned i=0; i < vAmmoTypes.size();i++)
    {
     if( ID == vAmmoTypes[i].GetID())
     return &vAmmoTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
WeaponCls::WeaponType *RPG::GetWeaponTypeByID(unsigned ID)
{
 for (unsigned i=0; i < vWeaponTypes.size();i++)
    {
     if( ID == vWeaponTypes[i].GetID())
     return &vWeaponTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
InventoryCls::Inventory *RPG::GetInventoryByID(unsigned ID)
{
 for (unsigned i=0; i < vInventories.size();i++)
    {
     if( ID == vInventories[i].GetID())
     return &vInventories[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
void RPG::SetQuiet(int Value)
{
 iQuiet=Value;
}
//---------------------------------------------------------------------------
int RPG::GetQuiet()
{
 return iQuiet;
}
//---------------------------------------------------------------------------
bool RPG::MoveObjectIntoInventory(InventoryCls::InventoryObject *Object,unsigned uInventoryID)
{
    unsigned uOldInventory=Object->GetInventoryID();
    if( uOldInventory != 0)
    {
    GetInventoryByID(uOldInventory)->TakeFromInventory(*Object);
    }
    if(Object->GetInventoryIndex() != 0)
    {
    Object->SetInventoryIndex(0);
    }
    std::vector<InventoryCls::InventoryObject *>::iterator iterInv;
    if(!GetInventoryByID(uInventoryID)->PutIntoInventory(Object, &iterInv))
    {
      GetInventoryByID(uOldInventory)->PutIntoInventory(Object, &iterInv);
      return false;
    }
 return true;
}
bool RPG::SetArmor(unsigned CharacterID,unsigned ArmorID)
{
 using namespace ArmorCls; 
 ArmorType atTemp=GetArmorByID(ArmorID)->GetArmorType();
 switch (atTemp)
 {
  case Head : GetCharacterByID(CharacterID)->SetHeadArmorID(ArmorID);return true;
  case Chest : GetCharacterByID(CharacterID)->SetChestArmorID(ArmorID);return true;
  case Shoulder : GetCharacterByID(CharacterID)->SetShoulderArmorID(ArmorID);return true;
  case Arm : GetCharacterByID(CharacterID)->SetArmArmorID(ArmorID);return true;
  case Hand : GetCharacterByID(CharacterID)->SetHandArmorID(ArmorID);return true;
  case Leg : GetCharacterByID(CharacterID)->SetLegArmorID(ArmorID);return true;
  case Foot : GetCharacterByID(CharacterID)->SetFootArmorID(ArmorID);return true;
 }
 return false;
}
//---------------------------------------------------------------------------
std::vector<CharacterCls::Character> RPG::getCharacters()
{
 return vCharacters;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::Weapon> RPG::getWeapons()
{
 return vWeapons;
}
//---------------------------------------------------------------------------
std::vector<ArmorCls::Armor> RPG::getArmors()
{
 return vArmors;
}
//---------------------------------------------------------------------------
std::vector<RPG_Misc::DamageType> RPG::getDamageTypes()
{
 return vDamageTypes;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::AmmoType> RPG::getAmmoTypes()
{
 return vAmmoTypes;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::WeaponType> RPG::getWeaponTypes()
{
 return vWeaponTypes;
}
//---------------------------------------------------------------------------
std::vector<InventoryCls::Inventory> RPG::getInventories()
{
 return vInventories;
}
//---------------------------------------------------------------------------
}
#pragma package(smart_init)


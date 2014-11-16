//---------------------------------------------------------------------------
//RPG Library
//A Library to manage rpg-objects
//
//This Library manages all characters, weapons ,armors ,inventories and powers
//needed for an RPG
//
//Copyright (C) 2005  Karsten Bock
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//---------------------------------------------------------------------------
#include "RPGClass.h"
#include "Functions.h"
#include <ctime>
#include <iostream>
//---------------------------------------------------------------------------


using namespace std;
namespace RPGCls
{
RPG * RPG::Instance = 0;
bool RPG::IsLocked = false;
//---------------------------------------------------------------------------
RPG::RPG()
{
 Language="english";
 ClearAll();
 Quiet=true;

}
//---------------------------------------------------------------------------
WeaponCls::Weapon *RPG::getWeaponByID(unsigned argID)
{

 for (unsigned i=0; i < Weapons.size();i++)
    {
     if( argID == Weapons[i].getID())
     return &Weapons[i];
    }
return &Weapons[0];

}
//---------------------------------------------------------------------------
CharacterCls::Character *RPG::getCharacterByID(unsigned argID)
{
 for (unsigned i=0; i < Characters.size();i++)
    {
     if( argID == Characters[i].getID())
     return &Characters[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
attackResult RPG::attack(unsigned attackingCharID,unsigned attackedCharID,unsigned uAimAt)
{
 srand(time(NULL));
 attackResult arRet;
 CharacterCls::Character *attackingChar=getCharacterByID(attackingCharID);
 CharacterCls::Character *attackedChar=getCharacterByID(attackedCharID);
 //AttributesCls::Attributes attackingAttrib;
 //attackingAttrib=attackingChar->getAttributes();

 WeaponCls::Weapon *RightWeapAttackingChar = getWeaponByID(attackingChar->getRightHandWeaponID());
 WeaponCls::Weapon *LeftWeapAttackingChar = getWeaponByID(attackingChar->getLeftHandWeaponID());

 WeaponCls::Weapon *RightWeapAttackedChar = getWeaponByID(attackingChar->getRightHandWeaponID());
 WeaponCls::Weapon *LeftWeapAttackedChar = getWeaponByID(attackingChar->getLeftHandWeaponID());

 //Chance to hit or chance to evade= dexterity - attacked dexterity* (strength-(weight of weapon/2)) + randon number between -50 and 50

 int iTCAttacking=attackingChar->getAttributes()->getDexterity() * (attackingChar->getAttributes()->getStrength()- (RightWeapAttackingChar->getWeight() /2)) + ((rand() % 100) -50);
 int iTCAttacked=attackedChar->getAttributes()->getDexterity() * (attackedChar->getAttributes()->getStrength()  - (RightWeapAttackingChar->getWeight() /2)) + ((rand() % 100) -50);
 int abzHitPointswA;
 int abzHitPoints;
 if(!Quiet)
 {
        string sOut=translateText("Right hand: Chance to hit : $ChanceToHit",Language);
        sOut.replace(sOut.find("$ChanceToHit"),12, convertIntegerToString(iTCAttacking));
        cout << "[CPP] " << sOut << "\r\n";
        sOut=translateText("Right hand: Chance to evade : $ChanceToEvade",Language);
        sOut.replace(sOut.find("$ChanceToEvade"),12, convertIntegerToString(iTCAttacked));
        cout << "[CPP] " << sOut << "\r\n";
 }
 if(iTCAttacked + ((iTCAttacked * uAimAt) /100 > iTCAttacking ))
 {
        arRet.Hitted=false;
        arRet.Damage=0;
        arRet.DamageWithoutArmor=0;
        arRet.AttackedDead=false;
 }
 else
 {
        //Schadenspunkte=Waffenschaden * (Stärke-(Waffengewicht/2))
        double Multiply=1;
        //AttributesCls::Attributes *attackedAttrib;
        //attackedAttrib=&attackedChar->Char_Attributes;
        //if(getArmorByID(attackedChar->ArmorID)->

        unsigned iAttackedArmorID;
        switch (uAimAt)
        {
        case AIM_AT_CHEST     : iAttackedArmorID=attackedChar->getChestArmorID();break;
        case AIM_AT_HEAD      : iAttackedArmorID=attackedChar->getHeadArmorID();break;
        case AIM_AT_SHOULDER  : iAttackedArmorID=attackedChar->getShoulderArmorID();break;
        case AIM_AT_ARM      : iAttackedArmorID=attackedChar->getArmArmorID();break;
        case AIM_AT_LEG      : iAttackedArmorID=attackedChar->getLegArmorID();break;
        case AIM_AT_HAND      : iAttackedArmorID=attackedChar->getHandArmorID();break;
        case AIM_AT_FOOT      : iAttackedArmorID=attackedChar->getFootArmorID();break;
        }
        if(getArmorByID(iAttackedArmorID)->containsWeakness(RightWeapAttackingChar->getDamageTypeID()))
        {
           string sOut=translateText("$AttackingRightWeaponName does more damage to $AttackedArmorName",Language);
           sOut.replace(sOut.find("$AttackingRightWeaponName"),24, RightWeapAttackingChar->getName());
           sOut.replace(sOut.find("$AttackedArmorName"),18, getArmorByID(iAttackedArmorID)->getName());
           cout << sOut;
//         cout << RightWeapAttackingChar->getName() << " does more damage to " << getArmorByID(iAttackedArmorID)->getName();
           Multiply=0.5;
        }

        if(getArmorByID(iAttackedArmorID)->containsStrength(RightWeapAttackingChar->getDamageTypeID()))
        {
           string sOut=translateText("$AttackingRightWeaponName does lesser damage to $AttackedArmorName",Language);
           sOut.replace(sOut.find("$AttackingRightWeaponName"),24, RightWeapAttackingChar->getName());
           sOut.replace(sOut.find("$AttackedArmorName"),18, getArmorByID(iAttackedArmorID)->getName());
           cout << sOut;
           //cout << RightWeapAttackingChar->getName() << " does lesser damage to " << getArmorByID(iAttackedArmorID)->getName();
           Multiply=2;
        }
        // int abzHitPoints;
        abzHitPointswA=RightWeapAttackingChar->getDamagePerHit() *(attackingChar->getAttributes()->getStrength() - (RightWeapAttackingChar->getWeight() /2));
        abzHitPoints=int(RightWeapAttackingChar->getDamagePerHit() *(attackingChar->getAttributes()->getStrength() - (RightWeapAttackingChar->getWeight() /2)) - (getArmorByID(iAttackedArmorID)->getArmorValue() * Multiply));
 }
 iTCAttacking=attackingChar->getAttributes()->getDexterity() * (attackingChar->getAttributes()->getStrength()- (LeftWeapAttackingChar->getWeight() /2)) + ((rand() % 100) -50);
 iTCAttacked=attackedChar->getAttributes()->getDexterity() * (attackedChar->getAttributes()->getStrength()  - (LeftWeapAttackingChar->getWeight() /2)) + ((rand() % 100) -50);
 if(!Quiet)
 {
        string sOut=translateText("Left hand: Chance to hit : $ChanceToHit",Language);
        sOut.replace(sOut.find("$ChanceToHit"),12, convertIntegerToString(iTCAttacking));
        cout << "[CPP] " << sOut << "\r\n";
        sOut=translateText("Left hand: Chance to evade : $ChanceToEvade",Language);
        sOut.replace(sOut.find("$ChanceToEvade"),12, convertIntegerToString(iTCAttacked));
        cout << "[CPP] " << sOut << "\r\n";
 }
 if(iTCAttacked + ((iTCAttacked * uAimAt) /100 > iTCAttacking ))
 {
        arRet.Hitted=false;
        arRet.Damage=0;
        arRet.DamageWithoutArmor=0;
        arRet.AttackedDead=true;
 }
 else
 {
        //Schadenspunkte=Waffenschaden * (Stärke-(Waffengewicht/2))
        double Multiply=1;
        //AttributesCls::Attributes *attackedAttrib;
        //attackedAttrib=&attackedChar->Char_Attributes;
        //if(getArmorByID(attackedChar->ArmorID)->

        unsigned iAttackedArmorID;
        switch (uAimAt)
        {
        case AIM_AT_CHEST     : iAttackedArmorID=attackedChar->getChestArmorID();break;
        case AIM_AT_HEAD      : iAttackedArmorID=attackedChar->getHeadArmorID();break;
        case AIM_AT_SHOULDER  : iAttackedArmorID=attackedChar->getShoulderArmorID();break;
        case AIM_AT_ARM      : iAttackedArmorID=attackedChar->getArmArmorID();break;
        case AIM_AT_LEG      : iAttackedArmorID=attackedChar->getLegArmorID();break;
        case AIM_AT_HAND      : iAttackedArmorID=attackedChar->getHandArmorID();break;
        case AIM_AT_FOOT      : iAttackedArmorID=attackedChar->getFootArmorID();break;
        }
        if(getArmorByID(iAttackedArmorID)->containsWeakness(LeftWeapAttackingChar->getDamageTypeID()))
        {
           //
           string sOut=translateText("$AttackingLeftWeaponName does more damage to $AttackedArmorName",Language);
           sOut.replace(sOut.find("$AttackingLeftWeaponName"),24, LeftWeapAttackingChar->getName());
           sOut.replace(sOut.find("$AttackedArmorName"),18, getArmorByID(iAttackedArmorID)->getName());
           cout << sOut; //LeftWeapAttackingChar->getName() << " does more damage to " << getArmorByID(iAttackedArmorID)->getName();
           Multiply=0.5;
        }

        if(getArmorByID(iAttackedArmorID)->containsStrength(LeftWeapAttackingChar->getDamageTypeID()))
        {
           string sOut=translateText("$AttackingLeftWeaponName does lesser damage to $AttackedArmorName",Language);
           sOut.replace(sOut.find("$AttackingLeftWeaponName"),24, LeftWeapAttackingChar->getName());
           sOut.replace(sOut.find("$AttackedArmorName"),18, getArmorByID(iAttackedArmorID)->getName());
           cout << sOut;
           //cout << LeftWeapAttackingChar->getName() << " does lesser damage to " << getArmorByID(iAttackedArmorID)->getName();
           Multiply=2;
        }
        // int abzHitPoints;

        abzHitPointswA+=LeftWeapAttackingChar->getDamagePerHit() *(attackingChar->getAttributes()->getStrength() - (LeftWeapAttackingChar->getWeight() /2));
        abzHitPoints+=int(LeftWeapAttackingChar->getDamagePerHit() *(attackingChar->getAttributes()->getStrength() - (LeftWeapAttackingChar->getWeight() /2)) - (getArmorByID(iAttackedArmorID)->getArmorValue() * Multiply));

        arRet.Hitted=true;
        arRet.Damage=abzHitPoints;
        arRet.DamageWithoutArmor=abzHitPointswA;
        attackedChar->getAttributes()->setHitPoints(attackedChar->getAttributes()->getHitPoints() -abzHitPoints);
        cout << attackingChar->getAttributes()->getHitPoints() << endl;
        if(attackedChar->getAttributes()->getHitPoints() <= 0)
        {
         arRet.AttackedDead=true;
        }
        else
        {
         arRet.AttackedDead=false;
        }
 }

 return arRet;
}
//---------------------------------------------------------------------------
int RPG::addWeapon(string argName,int wTypeID,int DamagePerHit/*,AttributesCls::Attributes NeededAttr*/,int Weight)
{
 unsigned NewID=WeaponHandles++;
 WeaponCls::Weapon wTemp(NewID,InventoryObjectHandles++);
 wTemp.setName(argName);
 wTemp.setTypeID(wTypeID);
 wTemp.setDamagePerHit(DamagePerHit);
 //wTemp.setNeededAttributes(NeededAttr);
 //wTemp.ID=WeaponHandles++;
 wTemp.setWeight(Weight);

 Weapons.push_back(wTemp);
 InventoryObjects.push_back(&wTemp);
 return NewID;//wTemp.getID();
}
//---------------------------------------------------------------------------
int RPG::addCharacter(std::string argName)
{
 unsigned NewID=CharacterHandles++;
 CharacterCls::Character tempChar(NewID);
 tempChar.setName(argName);
 Characters.push_back(tempChar);
 return NewID;//tempChar.getID();
}
//---------------------------------------------------------------------------
int RPG::addDamageType(std::string argName,std::string  argDescription)
{
 unsigned NewID=DamageTypeHandles++;
// cout << NewID << endl;
 RPG_Misc::DamageType tempDmgType(NewID,argName,argDescription);
 DamageTypes.push_back(tempDmgType);
 return NewID;//tempDmgType.getID();
}
//---------------------------------------------------------------------------
int RPG::addAmmoType(std::string argName,std::string argDescription,unsigned argDamageTypeID)
{
 unsigned NewID=AmmoTypeHandles++;
 WeaponCls::AmmoType tempAmmoType(NewID);
// tempAmmoType.setID();
 tempAmmoType.setName(argName);
 tempAmmoType.setDescription(argDescription);
 tempAmmoType.setDamageTypeID(argDamageTypeID);
 AmmoTypes.push_back(tempAmmoType);
 return NewID;//tempAmmoType.getID();
}
//---------------------------------------------------------------------------
int RPG::addWeaponType(std::string argName,std::string argDescription,unsigned argAmmoTypeID)
{
 unsigned NewID=WeaponTypeHandles++;
 WeaponCls::WeaponType tempWeaponType(NewID);
// tempWeaponType.ID=WeaponTypeHandles++;
 tempWeaponType.setName(argName);
 tempWeaponType.setDescription(argDescription);
 tempWeaponType.setAmmoTypeID(argAmmoTypeID);
 WeaponTypes.push_back(tempWeaponType);
 return NewID;//tempWeaponType.getID();
}
//---------------------------------------------------------------------------
int RPG::addArmor(std::string aargName,std::string argDescription)
{
 unsigned NewID = ArmorHandles++;
 ArmorCls::Armor tempArmor(NewID,InventoryObjectHandles++);
 tempArmor.setName(aargName);
 tempArmor.setDescription(argDescription);
 Armors.push_back(tempArmor);
 InventoryObjects.push_back(&tempArmor);
 return NewID;//tempArmor.getID();
}
//---------------------------------------------------------------------------
int RPG::addInventory(std::string argName,std::string argDescription,int argiMaxStorage)
{
 unsigned NewID = InventoryHandles++;
 InventoryCls::Inventory tempInventory(NewID,InventoryObjectHandles++,argName,argDescription,argiMaxStorage);
 Inventories.push_back(tempInventory);
 InventoryObjects.push_back(&tempInventory);
 return NewID;
 }
//---------------------------------------------------------------------------
ArmorCls::Armor *RPG::getArmorByID(unsigned argID)
{
 for (unsigned i=0; i < Armors.size();i++)
    {
     if( argID == Armors[i].getID())
     return &Armors[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
RPG_Misc::DamageType *RPG::getDamageTypeByID(unsigned argID)
{
 for (unsigned i=0; i < DamageTypes.size();i++)
    {
     if( argID == DamageTypes[i].getID())
     return &DamageTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
WeaponCls::AmmoType *RPG::getAmmoTypeByID(unsigned argID)
{
 for (unsigned i=0; i < AmmoTypes.size();i++)
    {
     if( argID == AmmoTypes[i].getID())
     return &AmmoTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
WeaponCls::WeaponType *RPG::getWeaponTypeByID(unsigned argID)
{
 for (unsigned i=0; i < WeaponTypes.size();i++)
    {
     if( argID == WeaponTypes[i].getID())
     return &WeaponTypes[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
InventoryCls::Inventory *RPG::getInventoryByID(unsigned argID)
{
 for (unsigned i=0; i < Inventories.size();i++)
    {
     if( argID == Inventories[i].getID())
     return &Inventories[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
InventoryCls::InventoryObject* RPG::getInventoryObjectByID(unsigned argID)
{
 for (unsigned i=0; i < InventoryObjects.size();i++)
    {
     if( argID == InventoryObjects[i]->getInventoryObjectID())
     return InventoryObjects[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
void RPG::setQuiet(bool Value)
{
 Quiet=Value;
}
//---------------------------------------------------------------------------
bool RPG::getQuiet()
{
 return Quiet;
}
//---------------------------------------------------------------------------
bool RPG::moveObjectIntoInventory(InventoryCls::InventoryObject *argObject,unsigned argInventoryID)
{
    unsigned uOldInventory=argObject->getInventoryID();
    if( uOldInventory != 0)
    {
    getInventoryByID(uOldInventory)->takeFromInventory(*argObject);
    }
    if(argObject->getInventoryIndex() != 0)
    {
    argObject->setInventoryIndex(0);
    }
    std::vector<InventoryCls::InventoryObject *>::iterator iterInv;
    if(!getInventoryByID(argInventoryID)->putIntoInventory(argObject, &iterInv))
    {
      getInventoryByID(uOldInventory)->putIntoInventory(argObject, &iterInv);
      return false;
    }
 return true;
}
//---------------------------------------------------------------------------
bool RPG::setArmor(unsigned argCharacterID,unsigned ArmorID)
{
 using namespace ArmorCls;
 ArmorType atTemp=getArmorByID(ArmorID)->getArmorType();
 switch (atTemp)
 {
  case Head : getCharacterByID(argCharacterID)->setHeadArmorID(ArmorID);return true;
  case Chest : getCharacterByID(argCharacterID)->setChestArmorID(ArmorID);return true;
  case Shoulder : getCharacterByID(argCharacterID)->setShoulderArmorID(ArmorID);return true;
  case Arm : getCharacterByID(argCharacterID)->setArmArmorID(ArmorID);return true;
  case Hand : getCharacterByID(argCharacterID)->setHandArmorID(ArmorID);return true;
  case Leg : getCharacterByID(argCharacterID)->setLegArmorID(ArmorID);return true;
  case Foot : getCharacterByID(argCharacterID)->setFootArmorID(ArmorID);return true;
 }
 return false;
}
//---------------------------------------------------------------------------
void RPG::ClearAll(bool argReInit)
{
//Erase all Objects and create the standard set if needed
Characters.clear();
Weapons.clear();
Armors.clear();
DamageTypes.clear();
AmmoTypes.clear();
WeaponTypes.clear();
Inventories.clear();
InventoryObjects.clear();
Powers.clear();

CharacterHandles=0;
WeaponHandles=0;
ArmorHandles=0;
DamageTypeHandles=0;
AmmoTypeHandles=0;
WeaponTypeHandles=0;
InventoryHandles=0;
PowerHandles=0;



if(argReInit)
{
 WeaponCls::AmmoType atNone(AmmoTypeHandles++);
 atNone.setName(translateText("No ammo type",Language));
 AmmoTypes.push_back(atNone);

 WeaponCls::WeaponType wtNone(WeaponTypeHandles++);
 wtNone.setName(translateText("No weapon type",Language));
 WeaponTypes.push_back(wtNone);

 RPG_Misc::DamageType dtNone(DamageTypeHandles++,translateText("No damage type",Language));
 DamageTypes.push_back(dtNone);

 WeaponCls::Weapon wpnNone(WeaponHandles++,InventoryObjectHandles++,translateText("No weapon",Language));
 Weapons.push_back(wpnNone);

 ArmorCls::Armor armNone(ArmorHandles++,InventoryObjectHandles++,translateText("No Armor",Language));
 Armors.push_back(armNone);

 InventoryCls::Inventory invNone(InventoryHandles++,InventoryObjectHandles++,translateText("No inventory",Language));
 Inventories.push_back(invNone);

}
}
//---------------------------------------------------------------------------
std::vector<CharacterCls::Character> RPG::getCharacters()
{
 return Characters;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::Weapon> RPG::getWeapons()
{
 return Weapons;
}
//---------------------------------------------------------------------------
std::vector<ArmorCls::Armor> RPG::getArmors()
{
 return Armors;
}
//---------------------------------------------------------------------------
std::vector<RPG_Misc::DamageType> RPG::getDamageTypes()
{
 return DamageTypes;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::AmmoType> RPG::getAmmoTypes()
{
 return AmmoTypes;
}
//---------------------------------------------------------------------------
std::vector<WeaponCls::WeaponType> RPG::getWeaponTypes()
{
 return WeaponTypes;
}
//---------------------------------------------------------------------------
std::vector<InventoryCls::Inventory> RPG::getInventories()
{
 return Inventories;
}
//---------------------------------------------------------------------------
int RPG::setLanguage(std::string argLanguage)
{
 //TODO: Check if LanguageFile Exists
 Language=argLanguage;
}
//---------------------------------------------------------------------------
std::string RPG::getLanguage()
{
 return Language;
}
//---------------------------------------------------------------------------
RPG *RPG::getInstance()
{
 if(!IsLocked)
 {
  IsLocked=true;
  if(!Instance)
  {
    Instance= new RPG();
  }
 }
 return Instance;
}
//---------------------------------------------------------------------------
void RPG::Destroy()
{
 delete Instance;
 Instance=NULL;
 IsLocked=false;
}
//---------------------------------------------------------------------------
RPGObjectCls::RPGObject *RPG::getCurrentTarget()
{
    return CurrentTarget;
}
//---------------------------------------------------------------------------
void RPG::setCurrentTarget(RPGObjectCls::RPGObject *argTarget)
{
    CurrentTarget=argTarget;
}
//---------------------------------------------------------------------------
int RPG::addPower(std::string argName,std::string argDescription)
{
unsigned NewID=PowerHandles++;
 PowersCls::Power pTemp(NewID,argName,argDescription);

 Powers.push_back(pTemp);
 return NewID;
}
//---------------------------------------------------------------------------
PowersCls::Power *RPG::getPowerByID(unsigned argID)
{
 for (unsigned i=0; i < Powers.size();i++)
    {
     if( argID == Powers[i].getID())
     return &Powers[i];
    }
return NULL;
}
//---------------------------------------------------------------------------
std::vector<PowersCls::Power> RPG::getPowers()
{
    return Powers;
}
//---------------------------------------------------------------------------
int RPG::executePower(unsigned argExecutorID,unsigned argPowerID)
{
try
{
    CharacterCls::Character *Caster=getCharacterByID(argExecutorID);
    if(Caster->ContainsPower(argPowerID))
    {

        PowersCls::Power *ExecutedPower = getPowerByID(argPowerID);
        if(ExecutedPower)
        {
            int iCheck=(rand() % 100);
            if( iCheck > ExecutedPower->getDifficultySum())
            {
                std::vector<PowersCls::PowersEffect *> Effects = ExecutedPower->getEffects();
                ExecutedPower->Execute(Caster);
                Message(mtCombat,ExecutedPower->getName() + " executed Successfully");

            }
            else
            {
                Message(mtCombat, "Executing " + ExecutedPower->getName() + " failed (" +convertIntegerToString(ExecutedPower->getDifficultySum()) + "% failure chance)");
                return 1;
            }
        }
    }
    else
    {
    }
}
catch(...)
{
}
}
//---------------------------------------------------------------------------
RPG::~RPG()
{
}
//---------------------------------------------------------------------------
void RPG::Message(MessageType argType, std::string argMessage)
{
 if(argType == mtGeneral)
 {
     if (bShowGeneralMessages)
     {
         std::cout << "General: " << argMessage.c_str() << endl;
     }
 }
 else if(argType == mtStatus)
 {
     if (bShowStatusMessages)
     {
         std::cout << "Status: " << argMessage.c_str() << endl;
     }
 }
 else if(argType == mtCombat)
 {
     if (bShowCombatMessages)
     {
         std::cout << "Combat: " << argMessage.c_str() << endl;
     }
 }
 else if(argType == mtError)
 {
     if (bShowCombatMessages)
     {
         std::cout << "Error: " << argMessage.c_str() << endl;
     }
 }
}
//---------------------------------------------------------------------------
}
#pragma package(smart_init)



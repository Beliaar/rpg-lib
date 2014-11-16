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
#ifndef RPGClassH
#define RPGClassH
#include "PowersClass.h"
#include "AttributesClass.h"
#include "CharacterClass.h"
#include "WeaponClass.h"
#include "ArmorClass.h"
#include "InventoryClass.h"
#include "Misc.h"
#include <string>
#include <vector>
#include <boost\variant.hpp>
#include "RPGObject.h"
//---------------------------------------------------------------------------
#define AIM_AT_CHEST     0
#define AIM_AT_HEAD      70
#define AIM_AT_SHOULDER  20
#define AIM_AT_ARM       30
#define AIM_AT_LEG       35
#define AIM_AT_HAND      50
#define AIM_AT_FOOT      60
//---------------------------------------------------------------------------


namespace RPGCls
{
//typedef boost::variant<RPGObjectCls::RPGObject *,CharacterCls::Character *> TargetType;
typedef enum {mtGeneral=0,mtStatus,mtCombat,mtError} MessageType;
struct attackResult
{
        bool Hitted;
        int Damage;
        int DamageWithoutArmor;
        bool AttackedDead;

};

class RPG
{
 private:
            unsigned CharacterHandles;
            unsigned WeaponHandles;
            unsigned ArmorHandles;
            unsigned DamageTypeHandles;
            unsigned AmmoTypeHandles;
            unsigned WeaponTypeHandles;
            unsigned InventoryHandles;
            unsigned InventoryObjectHandles;
            unsigned PowerHandles;

            std::vector<CharacterCls::Character> Characters;
            std::vector<WeaponCls::Weapon> Weapons;
            std::vector<ArmorCls::Armor> Armors;
            std::vector<RPG_Misc::DamageType> DamageTypes;
            std::vector<WeaponCls::AmmoType> AmmoTypes;
            std::vector<WeaponCls::WeaponType> WeaponTypes;
            std::vector<InventoryCls::Inventory> Inventories;
            std::vector<PowersCls::Power> Powers;

            bool Quiet;
            std::string Language;
            std::vector<InventoryCls::InventoryObject *> InventoryObjects;
            RPGObjectCls::RPGObject *CurrentTarget;
            static RPG* Instance;
            RPG();
            ~RPG();
            RPG(const RPG& cc){}
            RPG& operator= (const RPG&);
            static bool IsLocked;
            bool bShowGeneralMessages;
            bool bShowStatusMessages;
            bool bShowCombatMessages;
 protected:
 public:

        WeaponCls::Weapon *getWeaponByID(unsigned argID);
        CharacterCls::Character *getCharacterByID(unsigned argID);
        ArmorCls::Armor *getArmorByID(unsigned argID);
        RPG_Misc::DamageType *getDamageTypeByID(unsigned argID);
        WeaponCls::AmmoType *getAmmoTypeByID(unsigned argID);
        WeaponCls::WeaponType *getWeaponTypeByID(unsigned argID);
        InventoryCls::Inventory *getInventoryByID(unsigned argID);
        InventoryCls::InventoryObject *getInventoryObjectByID(unsigned argID);
        PowersCls::Power *getPowerByID(unsigned argID);
        attackResult attack(unsigned argAttackingCharID,unsigned argAttackedCharID,unsigned argAimAt=AIM_AT_CHEST);
        int addWeapon(std::string argName,int argTypeID,int argDamagePerHit,int argWeight);
        int addCharacter(std::string argName);
        int addArmor(std::string argName,std::string argDescription="");
        int addDamageType(std::string argName,std::string argDescription="");
        int addAmmoType(std::string argName,std::string argDescription="",unsigned argDamageTypeID=0);
        int addWeaponType(std::string argName,std::string argDescription="",unsigned argAmmoTypeID=0);
        int addInventory(std::string argName,std::string argDescription="",int argiMaxStorage=-1);
        int addPower(std::string argName,std::string argDescription="");
        bool moveObjectIntoInventory(InventoryCls::InventoryObject *argObject,unsigned argInventoryID);
        bool setArmor(unsigned argCharacterID,unsigned argArmorID);

        void ClearAll(bool argReInit=true);

        std::vector<CharacterCls::Character> getCharacters();
        std::vector<WeaponCls::Weapon> getWeapons();
        std::vector<ArmorCls::Armor> getArmors();
        std::vector<RPG_Misc::DamageType> getDamageTypes();
        std::vector<WeaponCls::AmmoType> getAmmoTypes();
        std::vector<WeaponCls::WeaponType> getWeaponTypes();
        std::vector<InventoryCls::Inventory> getInventories();
        std::vector<PowersCls::Power> getPowers();

        void setQuiet(bool argValue);
        bool getQuiet();
        int setLanguage(std::string argLanguage);
        std::string getLanguage();

        RPGObjectCls::RPGObject *getCurrentTarget();
        void setCurrentTarget(RPGObjectCls::RPGObject *argTarget);
        static RPG *getInstance();
        static void Destroy();

        int executePower(unsigned argExecutorID,unsigned argPowerID);
        //Executes the Power
        //Return Values:
        //0 = OK
        //1 = Not enough PowerPoints
        //2 = Execution failed DifficultyCheck
        void Message(MessageType argType, std::string argMessage);

};
}
//---------------------------------------------------------------------------
#endif

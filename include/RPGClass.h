//---------------------------------------------------------------------------
// 2005 by Beliar
// RPGClass
// A class to manage rpg-objects
//
// This class manages all characters, weapons ,armors ,inventories and powers
// It also contains the 'battle script'
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

struct attackResult
{
        int bHit;          //1 = hit; 0 = no hit
        int iDmg;           //Damage
        int iDmgwA;         //Damage without Armor
        bool bAttackedDead; //1 = Attacked is dead; 0 = attacked is not dead
        
};
class RPG
{
 private:
            unsigned uCharacterHandles;
            unsigned uWeaponHandles;
            unsigned uArmorHandles;
            unsigned uDamageTypeHandles;
            unsigned uAmmoTypeHandles;
            unsigned uWeaponTypeHandles;
            unsigned uInventoryHandles;
            std::vector<CharacterCls::Character> vCharacters;
            std::vector<WeaponCls::Weapon> vWeapons;
            std::vector<ArmorCls::Armor> vArmors;
            std::vector<RPG_Misc::DamageType> vDamageTypes;
            std::vector<WeaponCls::AmmoType> vAmmoTypes;
            std::vector<WeaponCls::WeaponType> vWeaponTypes;
            std::vector<InventoryCls::Inventory> vInventories;
            int iQuiet;

 protected:
 public:

        WeaponCls::Weapon *GetWeaponByID(unsigned ID);
        CharacterCls::Character *GetCharacterByID(unsigned ID);
        ArmorCls::Armor *GetArmorByID(unsigned ID);
        RPG_Misc::DamageType *GetDamageTypeByID(unsigned ID);
        WeaponCls::AmmoType *GetAmmoTypeByID(unsigned ID);
        WeaponCls::WeaponType *GetWeaponTypeByID(unsigned ID);
        InventoryCls::Inventory *GetInventoryByID(unsigned ID);
        attackResult attack(unsigned attackingCharID,unsigned attackedCharID,unsigned uAimAt=AIM_AT_CHEST);
        int addWeapon(std::string asName,int wTypeID,int DamagePerHit,int Weight);
        int addCharacter(std::string sName);
        int addArmor(std::string sName,std::string sDescription="");
        int addDamageType(std::string sName,std::string sDescription="");
        int addAmmoType(std::string sName,std::string sDescription="",unsigned DamageTypeID=0);
        int addWeaponType(std::string sName,std::string sDescription="",unsigned AmmoTypeID=0);
        int addInventory(std::string sName,std::string sDescription="",int iMaxStorage=-1);
        bool MoveObjectIntoInventory(InventoryCls::InventoryObject *Object,unsigned uInventoryID);
        bool SetArmor(unsigned CharacterID,unsigned ArmorID); 
              
        std::vector<CharacterCls::Character> getCharacters();
        std::vector<WeaponCls::Weapon> getWeapons();
        std::vector<ArmorCls::Armor> getArmors();
        std::vector<RPG_Misc::DamageType> getDamageTypes();
        std::vector<WeaponCls::AmmoType> getAmmoTypes();
        std::vector<WeaponCls::WeaponType> getWeaponTypes();
        std::vector<InventoryCls::Inventory> getInventories();

        void SetQuiet(int Value);
        int GetQuiet();
        RPG();
};
}

//---------------------------------------------------------------------------
#endif

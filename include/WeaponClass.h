//---------------------------------------------------------------------------

#ifndef WeaponClassH
#define WeaponClassH
#include <string>
#include "Misc.h"
#include "AttributesClass.h"
#include "InventoryClass.h"

namespace RPGCls
{
namespace WeaponCls
{
//---------------------------------------------------------------------------
class AmmoType : public RPGObjectCls::RPGObject
{
 private:
        unsigned uDamageTypeID;
 public:
        AmmoType(unsigned vID);
        AmmoType(unsigned vID,std::string vName);
        AmmoType(unsigned vID,std::string vName,std::string vDescription);
        AmmoType(unsigned vID,std::string vName,std::string vDescription,unsigned vDamageTypeID);
        void SetDamageTypeID(unsigned Value);
        unsigned GetDamageTypeID();

};
//---------------------------------------------------------------------------
class WeaponType : public RPGObjectCls::RPGObject
{
 private:
        unsigned uAmmoTypeID;
 public:
        WeaponType(unsigned vID);
        WeaponType(unsigned vID,std::string vName);
        WeaponType(unsigned vID,std::string vName,std::string vDescription);
        WeaponType(unsigned vID,std::string vName,std::string vDescription,unsigned vAmmoTypeID);
        void SetAmmoTypeID(unsigned Value);
        unsigned GetAmmoTypeID();
};
//---------------------------------------------------------------------------
class Weapon : public InventoryCls::InventoryObject
{
 private:
        int uTypeID;
        int uDamageTypeID;
        int iDamagePerHit;
        //RPGCls::AttributesCls::Attributes fNeededAttributes;
 public:
        Weapon(unsigned vID);
        Weapon(unsigned vID,std::string vName);
        Weapon(unsigned vID,std::string vName,unsigned vTypeID);
        Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID);
        Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID,int vDamagePerHit );
        Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID,int vDamagePerHit, int vWeight );
        void SetTypeID(unsigned Value);
        unsigned GetTypeID();
        void SetDamageTypeID(unsigned Value);
        unsigned GetDamageTypeID();
        void SetDamagePerHit(int Value);
        int GetDamagePerHit();

};
//---------------------------------------------------------------------------
}//WeaponCls
}//RPGCls
#endif

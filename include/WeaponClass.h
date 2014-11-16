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
        unsigned DamageTypeID;
 public:
        AmmoType(unsigned argID,std::string argName="",std::string argDescription="",unsigned argDamageTypeID=0);
        void setDamageTypeID(unsigned argValue);
        unsigned getDamageTypeID();

};
//---------------------------------------------------------------------------
class WeaponType : public RPGObjectCls::RPGObject
{
 private:
        unsigned AmmoTypeID;
 public:
        WeaponType(unsigned argID,std::string argName="",std::string argDescription="",unsigned argAmmoTypeID=0);
        void setAmmoTypeID(unsigned argValue);
        unsigned getAmmoTypeID();
};
//---------------------------------------------------------------------------
class Weapon : public InventoryCls::InventoryObject
{
 private:
        int TypeID;
        int DamageTypeID;
        int DamagePerHit;
        //RPGCls::AttributesCls::Attributes fNeededAttributes;
 public:
        Weapon(unsigned argID,unsigned argInventoryObjectID,std::string argName="",std::string argDescription="",unsigned argTypeID=0,unsigned argDamageTypeID=0,int argDamagePerHit=0,int argSpaceUsed=0,int argWeight=0 );
        void setTypeID(unsigned argTypeID);
        unsigned getTypeID();
        void setDamageTypeID(unsigned argDamageTypeID);
        unsigned getDamageTypeID();
        void setDamagePerHit(int argDamagePerHit);
        int getDamagePerHit();

};
//---------------------------------------------------------------------------
class RPGObjectWithWeapon : public RPGObjectCls::RPGObject
{
    private:
        unsigned WeaponID;
    public:
        RPGObjectWithWeapon(unsigned argID,std::string argName,std::string argDescription);
        virtual ~RPGObjectWithWeapon();
        unsigned getWeaponID();
        void setWeaponID(unsigned argWeaponID);
};
//---------------------------------------------------------------------------
}//WeaponCls
}//RPGCls
#endif

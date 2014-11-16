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
#include "WeaponClass.h"
namespace RPGCls
{
namespace WeaponCls
{

//---------------------------------------------------------------------------
AmmoType::AmmoType(unsigned argID,std::string argName,std::string argDescription,unsigned argDamageTypeID) : RPGObject(argID,argName,argDescription)
{
  DamageTypeID=argDamageTypeID;
}
//---------------------------------------------------------------------------
void AmmoType::setDamageTypeID(unsigned argDamageTypeID)
{
 DamageTypeID= argDamageTypeID;
}
//---------------------------------------------------------------------------
unsigned AmmoType::getDamageTypeID()
{
 return DamageTypeID;
}
//---------------------------------------------------------------------------
WeaponType::WeaponType(unsigned argID,std::string argName,std::string argDescription,unsigned argAmmoTypeID) : RPGObject(argID,argName,argDescription)
{
 AmmoTypeID=argAmmoTypeID;
}
//---------------------------------------------------------------------------
void WeaponType::setAmmoTypeID(unsigned argAmmoTypeID)
{
 AmmoTypeID= AmmoTypeID;
}
//---------------------------------------------------------------------------
unsigned WeaponType::getAmmoTypeID()
{
 return AmmoTypeID;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription,unsigned argTypeID,unsigned argDamageTypeID,int argDamagePerHit,int argSpaceUsed,int argWeight ) : InventoryObject(argID,argInventoryObjectID,argName,argDescription,argSpaceUsed,argWeight)
{
 TypeID=argTypeID;
 DamageTypeID=argDamageTypeID;
 DamagePerHit=argDamagePerHit;
}
//---------------------------------------------------------------------------
void Weapon::setTypeID(unsigned argTypeID)
{
 TypeID=argTypeID;
}
//---------------------------------------------------------------------------
unsigned Weapon::getTypeID()
{
 return TypeID;
}
//---------------------------------------------------------------------------
void Weapon::setDamageTypeID(unsigned argDamageTypeID)
{
 DamageTypeID=argDamageTypeID;
}
//---------------------------------------------------------------------------
unsigned Weapon::getDamageTypeID()
{
 return DamageTypeID;
}
//---------------------------------------------------------------------------
void Weapon::setDamagePerHit(int argDamagePerHit)
{
 DamagePerHit=argDamagePerHit;
}
//---------------------------------------------------------------------------
int Weapon::getDamagePerHit()
{
 return DamagePerHit;
}
//---------------------------------------------------------------------------
unsigned RPGObjectWithWeapon::getWeaponID()
{
    return WeaponID;
}
//---------------------------------------------------------------------------
void RPGObjectWithWeapon::setWeaponID(unsigned argWeaponID)
{
    WeaponID=argWeaponID;
}
//---------------------------------------------------------------------------
RPGObjectWithWeapon::RPGObjectWithWeapon(unsigned argID,std::string argName,std::string argDescription) : RPGObject(argID,argName,argDescription)
{
}
//---------------------------------------------------------------------------
RPGObjectWithWeapon::~RPGObjectWithWeapon()
{
}
//---------------------------------------------------------------------------
}
}

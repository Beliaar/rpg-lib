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

#ifndef CharacterClassH
#define CharacterClassH
#include "RPGObject.h"
#include <string>
#include "AttributesClass.h"
#include <vector>

namespace RPGCls
{
namespace CharacterCls
{
class Character: public AttributesCls::RPGObjectWithAttributes
{
 private:
         unsigned LeftHandWeaponID;
         unsigned RightHandWeaponID;
         unsigned LeftHandObjectID;
         unsigned RightHandObjectID;
         unsigned HeadArmorID;
         unsigned ShoulderArmorID;
         unsigned ChestArmorID;
         unsigned ArmArmorID;
         unsigned HandArmorID;
         unsigned LegArmorID;
         unsigned FootArmorID;
         unsigned InventoryID;

         std::vector<unsigned> Powers;
 public:
         Character(unsigned argID,std::string argName="nobody", std::string argDescription="");

         void setLeftHandWeaponID(unsigned argLeftHandWeaponID);
         unsigned getLeftHandWeaponID();
         void setRightHandWeaponID(unsigned argRightHandWeaponID);
         unsigned getRightHandWeaponID();

         void setLeftHandObjectID(unsigned argLeftHandObjectID);
         unsigned getLeftHandObjectID();
         void setRightHandObjectID(unsigned argRightHandObjectID);
         unsigned getRightHandObjectID();

         void setHeadArmorID(unsigned argHeadArmorID);
         unsigned getHeadArmorID();
         void setShoulderArmorID(unsigned argShoulderArmorID);
         unsigned getShoulderArmorID();
         void setChestArmorID(unsigned argChestArmorID);
         unsigned getChestArmorID();
         void setArmArmorID(unsigned argArmArmorID);
         unsigned getArmArmorID();
         void setHandArmorID(unsigned argHandArmorID);
         unsigned getHandArmorID();
         void setLegArmorID(unsigned argLegArmorID);
         unsigned getLegArmorID();
         void setFootArmorID(unsigned argFootArmorID);
         unsigned getFootArmorID();

         void setInventoryID(unsigned argInventoryID);
         unsigned getInventoryID();
         void addPower(unsigned argPowerID);
         void deletePower(std::vector<unsigned>::iterator argToDelete);
         std::vector<unsigned> getPowers();
         bool ContainsPower(unsigned argPowerID);
         void setAttributes(RPGCls::AttributesCls::Attributes argAttributes);

};
//---------------------------------------------------------------------------
}//CharacterCls
}//RPGCls
#endif

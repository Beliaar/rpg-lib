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
#include "CharacterClass.h"
#include "Functions.h"
#include <iostream>
#include "RPGClass.h"
namespace RPGCls
{
namespace CharacterCls
{
//---------------------------------------------------------------------------
Character::Character(unsigned argID,std::string argName, std::string argDescription) :  RPGObjectWithAttributes(argID,argName,argDescription)
{
 LeftHandWeaponID=0;
 RightHandWeaponID=0;
 LeftHandObjectID=0;
 RightHandObjectID=0;
 HeadArmorID=0;
 ShoulderArmorID=0;
 ChestArmorID=0;
 ArmArmorID=0;
 HandArmorID=0;
 LegArmorID=0;
 FootArmorID=0;
}
//---------------------------------------------------------------------------
void Character::setLeftHandWeaponID(unsigned argLeftHandWeaponID)
{
 LeftHandWeaponID = argLeftHandWeaponID;
}
//---------------------------------------------------------------------------
unsigned Character::getLeftHandWeaponID()
{
 return LeftHandWeaponID;
}
//---------------------------------------------------------------------------
void Character::setRightHandWeaponID(unsigned argRightHandWeaponID)
{
 RightHandWeaponID=argRightHandWeaponID;
}
//---------------------------------------------------------------------------
unsigned Character::getRightHandWeaponID()
{
 return RightHandWeaponID;
}
//---------------------------------------------------------------------------

void Character::setLeftHandObjectID(unsigned argLeftHandObjectID)
{
 LeftHandObjectID=argLeftHandObjectID;
}
//---------------------------------------------------------------------------
unsigned Character::getLeftHandObjectID()
{
 return LeftHandObjectID;
}
//---------------------------------------------------------------------------
void Character::setRightHandObjectID(unsigned argRightHandObjectID)
{
 RightHandObjectID=argRightHandObjectID;
}
//---------------------------------------------------------------------------
unsigned Character::getRightHandObjectID()
{
 return RightHandObjectID;
}
//---------------------------------------------------------------------------

void Character::setHeadArmorID(unsigned argHeadArmorID)
{
 HeadArmorID=argHeadArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getHeadArmorID()
{
 return HeadArmorID;
}
//---------------------------------------------------------------------------
void Character::setShoulderArmorID(unsigned argShoulderArmorID)
{
 ShoulderArmorID=argShoulderArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getShoulderArmorID()
{
 return ShoulderArmorID;
}
//---------------------------------------------------------------------------
void Character::setChestArmorID(unsigned argChestArmorID)
{
 ChestArmorID=argChestArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getChestArmorID()
{
 return ChestArmorID;
}
//---------------------------------------------------------------------------
void Character::setArmArmorID(unsigned argArmArmorID)
{
 ArmArmorID=argArmArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getArmArmorID()
{
 return ArmArmorID;
}
//---------------------------------------------------------------------------
void Character::setHandArmorID(unsigned argHandArmorID)
{
 HandArmorID=argHandArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getHandArmorID()
{
 return HandArmorID;
}
//---------------------------------------------------------------------------
void Character::setLegArmorID(unsigned argLegArmorID)
{
 LegArmorID=argLegArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getLegArmorID()
{
 return LegArmorID;
 }
//---------------------------------------------------------------------------
void Character::setFootArmorID(unsigned argFootArmorID)
{
 FootArmorID=argFootArmorID;
}
//---------------------------------------------------------------------------
unsigned Character::getFootArmorID()
{
 return FootArmorID;
}
//---------------------------------------------------------------------------
void Character::setInventoryID(unsigned argInventoryID)
{
 InventoryID=argInventoryID;
}
//---------------------------------------------------------------------------
unsigned Character::getInventoryID()
{
 return InventoryID;
}
//---------------------------------------------------------------------------
void Character::addPower(unsigned argPowerID)
{
    Powers.push_back(argPowerID);
}
//---------------------------------------------------------------------------
void Character::deletePower(std::vector<unsigned>::iterator argToDelete)
{
    Powers.erase(argToDelete);
}
//---------------------------------------------------------------------------
std::vector<unsigned> Character::getPowers()
{
    return Powers;
}
//---------------------------------------------------------------------------
bool Character::ContainsPower(unsigned argPowerID)
{
 std::vector<unsigned>::iterator start=Powers.begin();
 std::vector<unsigned>::iterator end=Powers.end();
 std::vector<unsigned>::iterator iter=find(start,end,argPowerID);
 if(iter!= end)
 {
    return true;
 }
 return false;
}
//---------------------------------------------------------------------------
void Character::setAttributes(RPGCls::AttributesCls::Attributes argAttributes)
{
    RPGObjectWithAttributes::setAttributes(argAttributes);
}
//---------------------------------------------------------------------------
}//CharacterCls
}//RPGCls

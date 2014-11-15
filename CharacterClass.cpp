#include "CharacterClass.h"

#include <iostream>
namespace RPGCls
{
namespace CharacterCls
{
//---------------------------------------------------------------------------
Character::Character(unsigned vID)
{
 uID=vID;
 sName="Nobody";
 uLeftHandWeaponID=0;
 uRightHandWeaponID=0;
 uLeftHandObjectID=0;
 uRightHandObjectID=0;
 uHeadArmorID=0;
 uChestArmorID=0;
 uArmArmorID=0;
 uHandArmorID=0;
 uLegArmorID=0;
 uFootArmorID=0;
}
//---------------------------------------------------------------------------
Character::Character(unsigned vID,std::string vName)
{
 uID=vID;
 sName=vName;
 uLeftHandWeaponID=0;
 uRightHandWeaponID=0;
 uLeftHandObjectID=0;
 uRightHandObjectID=0;
 uHeadArmorID=0;
 uShoulderArmorID=0;
 uChestArmorID=0;
 uArmArmorID=0;
 uHandArmorID=0;
 uLegArmorID=0;
 uFootArmorID=0;
}
//---------------------------------------------------------------------------
void Character::SetLeftHandWeaponID(unsigned Value)
{
 uLeftHandWeaponID = Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetLeftHandWeaponID()
{
 return uLeftHandWeaponID;
}
//---------------------------------------------------------------------------
void Character::SetRightHandWeaponID(unsigned Value)
{
 uRightHandWeaponID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetRightHandWeaponID()
{
 return uRightHandWeaponID;
}
//---------------------------------------------------------------------------

void Character::SetLeftHandObjectID(unsigned Value)
{
 uLeftHandObjectID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetLeftHandObjectID()
{
 return uLeftHandObjectID;
}
//---------------------------------------------------------------------------
void Character::SetRightHandObjectID(unsigned Value)
{
 uRightHandObjectID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetRightHandObjectID()
{
 return uRightHandObjectID;
}
//---------------------------------------------------------------------------

void Character::SetHeadArmorID(unsigned Value)
{
 uHeadArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetHeadArmorID()
{
 return uHeadArmorID;
}
//---------------------------------------------------------------------------
void Character::SetShoulderArmorID(unsigned Value)
{
 uShoulderArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetShoulderArmorID()
{
 return uShoulderArmorID;
}
//---------------------------------------------------------------------------
void Character::SetChestArmorID(unsigned Value)
{
 uChestArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetChestArmorID()
{
 return uChestArmorID;
}
//---------------------------------------------------------------------------
void Character::SetArmArmorID(unsigned Value)
{
 uArmArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetArmArmorID()
{
 return uArmArmorID;
}
//---------------------------------------------------------------------------
void Character::SetHandArmorID(unsigned Value)
{
 uHandArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetHandArmorID()
{
 return uHandArmorID;
}
//---------------------------------------------------------------------------
void Character::SetLegArmorID(unsigned Value)
{
 uLegArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetLegArmorID()
{
 return uLegArmorID;
 }
//---------------------------------------------------------------------------
void Character::SetFootArmorID(unsigned Value)
{
 uFootArmorID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetFootArmorID()
{
 return uFootArmorID;
}
//---------------------------------------------------------------------------
void Character::SetAttributes(RPGCls::AttributesCls::Attributes Value)
{
 attrChar_Attributes=Value;
}
//---------------------------------------------------------------------------
RPGCls::AttributesCls::Attributes *Character::GetAttributes()
{
 return &attrChar_Attributes;
}
//---------------------------------------------------------------------------
void Character::SetInventoryID(unsigned Value)
{
 uInventoryID=Value;
}
//---------------------------------------------------------------------------
unsigned Character::GetInventoryID()
{
 return uInventoryID;
}
//---------------------------------------------------------------------------
}//CharacterCls
}//RPGCls

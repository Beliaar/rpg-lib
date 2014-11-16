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

#include <string>
#include "ArmorClass.h"
using namespace std;
//---------------------------------------------------------------------------
namespace RPGCls
{
namespace ArmorCls
{
//---------------------------------------------------------------------------
Armor::Armor(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription,ArmorType argArmorType,int argSpaceUsed,int argWeight) : InventoryObject(argID,argInventoryObjectID,argName,argDescription,argSpaceUsed,argWeight)
{
    Type=argArmorType;
    ArmorValue=0;

}
//---------------------------------------------------------------------------
void Armor::setArmorValue(int argArmorValue)
{
    ArmorValue=argArmorValue;
}
//---------------------------------------------------------------------------
int Armor::getArmorValue()
{
    return ArmorValue;
}
//---------------------------------------------------------------------------
void Armor::setArmorType(ArmorType argType)
{
 Type=argType;
}
//---------------------------------------------------------------------------
ArmorType Armor::getArmorType()
{
 return Type;
}
//---------------------------------------------------------------------------
void Armor::addWeakness(int argDamageTypeID)
{
 Weaknesses.push_back(argDamageTypeID);
}
//---------------------------------------------------------------------------
void Armor::deleteWeakness(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Weaknesses.begin(); iIter != Weaknesses.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
  {
     Weaknesses.erase(iIter);
     return;
  }
 }
}
//---------------------------------------------------------------------------
void Armor::deleteWeaknessAll(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Weaknesses.begin(); iIter != Weaknesses.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
  {
     Weaknesses.erase(iIter);
  }
 }
}
//---------------------------------------------------------------------------
void Armor::addStrength(int argDamageTypeID)
{
     Strengths.push_back(argDamageTypeID);
}
//---------------------------------------------------------------------------
void Armor::deleteStrength(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Strengths.begin(); iIter != Strengths.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
  {
     Strengths.erase(iIter);
     return;
  }
 }
}
//---------------------------------------------------------------------------
void Armor::deleteStrengthAll(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Strengths.begin(); iIter != Strengths.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
  {
     Strengths.erase(iIter);
  }
 }
}
//---------------------------------------------------------------------------
bool Armor::containsWeakness(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Weaknesses.begin(); iIter != Weaknesses.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
     return true;
 }
 return false;
}
//---------------------------------------------------------------------------
bool Armor::containsStrength(int argDamageTypeID)
{
 for(vector<int>::iterator iIter=Strengths.begin(); iIter != Strengths.end(); iIter++)
 {
  if (argDamageTypeID==*iIter)
     return true;
 }
 return false;
}
//---------------------------------------------------------------------------
RPGObjectWithArmor::RPGObjectWithArmor(unsigned argID,std::string argName,std::string argDescription) : RPGObject(argID,argName,argDescription)
{
}
//---------------------------------------------------------------------------
unsigned RPGObjectWithArmor::getArmorID()
{
    return ArmorID;
}
//---------------------------------------------------------------------------
void RPGObjectWithArmor::setArmorID(unsigned argArmorID)
{
    ArmorID=argArmorID;
}
//---------------------------------------------------------------------------
RPGObjectWithArmor::~RPGObjectWithArmor()
{
}
//---------------------------------------------------------------------------
}
}


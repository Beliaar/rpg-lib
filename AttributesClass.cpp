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
#include "AttributesClass.h"
using namespace std;
namespace RPGCls
{
namespace AttributesCls
{

//---------------------------------------------------------------------------
int  Attributes::getMaxHitPoints()
{
 return (Condition * 10) /3;
}
//---------------------------------------------------------------------------
int  Attributes::getHitPoints()
{
 return HitPoints;
}
//---------------------------------------------------------------------------

void  Attributes::setHitPoints(int value)
{
 HitPoints = value;
}
//---------------------------------------------------------------------------
int Attributes::getCondition()
{
 return Condition;
}
//---------------------------------------------------------------------------
void Attributes::setCondition(int value)
{
 Condition=value;
}
//---------------------------------------------------------------------------
int Attributes::getStrength()
{
 return Strength;
}
//void---------------------------------------------------------------------------
void Attributes::setStrength(int value)
{
 Strength=value;
}
//---------------------------------------------------------------------------
int Attributes::getDexterity()
{
 return Dexterity;
}
//---------------------------------------------------------------------------
void Attributes::setDexterity(int value)
{
 Dexterity=value;
}
//---------------------------------------------------------------------------
int Attributes::getIntelligence()
{
 return Intelligence;
}
//---------------------------------------------------------------------------
void Attributes::setIntelligence(int value)
{
 Intelligence=value;
}
//---------------------------------------------------------------------------
int Attributes::getMaxPowerPoints()
{
 return (Intelligence * 3) / 2;
}
//---------------------------------------------------------------------------
int Attributes::getPowerPoints()
{
 return PowerPoints;
}
//---------------------------------------------------------------------------
void Attributes::setPowerPoints(int value)
{
 PowerPoints=value;
}
//---------------------------------------------------------------------------
int Attributes::getNaturalResistance()
{
 return NaturalResistance;
}
//---------------------------------------------------------------------------
void Attributes::setNaturalResistance(int argNaturalResistance)
{
    NaturalResistance=argNaturalResistance;
}
//---------------------------------------------------------------------------
int Attributes::getPowerResistance()
{
    return PowerResistance;
}
//---------------------------------------------------------------------------
void Attributes::setPowerResistance(int argPowerResistance)
{
    PowerResistance=argPowerResistance;
}
//---------------------------------------------------------------------------
Attributes::Attributes()
{
 Condition=0;
 Strength=0;
 Dexterity=0;
 Intelligence=0;

 HitPoints=0;
 PowerPoints=0;
}
//---------------------------------------------------------------------------
void Attributes::operator+=(Attributes A)
{
 Condition+=A.getCondition();
 Strength+=A.getStrength();
 Dexterity+=A.getDexterity();
 Intelligence+=A.getIntelligence();
 PowerPoints+=A.getPowerPoints();
}
//---------------------------------------------------------------------------
void Attributes::operator-=(Attributes A)
{
 Condition-=A.getCondition();
 Strength-=A.getStrength();
 Dexterity-=A.getDexterity();
 Intelligence-=A.getIntelligence();
 PowerPoints-=A.getPowerPoints();
}
//---------------------------------------------------------------------------
void Attributes::operator*=(Attributes A)
{
 Condition*=A.getCondition();
 Strength*=A.getStrength();
 Dexterity*=A.getDexterity();
 Intelligence*=A.getIntelligence();
 PowerPoints*=A.getPowerPoints();
}
//---------------------------------------------------------------------------
void Attributes::operator/=(Attributes A)
{
 Condition/=A.getCondition();
 Strength/=A.getStrength();
 Dexterity/=A.getDexterity();
 Intelligence/=A.getIntelligence();
 PowerPoints/=A.getPowerPoints();

}
//---------------------------------------------------------------------------
void Attributes::operator=(Attributes A)
{
 Condition=A.getCondition();
 Strength=A.getStrength();
 Dexterity=A.getDexterity();
 Intelligence=A.getIntelligence();
 PowerPoints=A.getPowerPoints();
}
//---------------------------------------------------------------------------
void Attributes::operator+=(int A)
{
 Condition+=A;
 Strength+=A;
 Dexterity+=A;
 Intelligence+=A;
 PowerPoints+=A;
}
//---------------------------------------------------------------------------
void Attributes::operator-=(int A)
{
 Condition-=A;
 Strength-=A;
 Dexterity-=A;
 Intelligence-=A;
 PowerPoints-=A;
}
//---------------------------------------------------------------------------
void Attributes::operator*=(int A)
{
 Condition*=A;
 Strength*=A;
 Dexterity*=A;
 Intelligence*=A;
 PowerPoints*=A;
}
//---------------------------------------------------------------------------
void Attributes::operator/=(int A)
{
 Condition/=A;
 Strength/=A;
 Dexterity/=A;
 Intelligence/=A;
 PowerPoints/=A;
}
//---------------------------------------------------------------------------
void Attributes::operator=(int A)
{
 Condition=A;
 Strength=A;
 Dexterity=A;
 Intelligence=A;
 PowerPoints=A;
}
//---------------------------------------------------------------------------
RPGObjectWithAttributes::RPGObjectWithAttributes(unsigned argID,std::string argName,std::string argDescription) : RPGObject(argID,argName,argDescription)
{
}
//---------------------------------------------------------------------------
void RPGObjectWithAttributes::setAttributes(RPGCls::AttributesCls::Attributes argAttributes)
{
 ObjAttributes=argAttributes;
}
//---------------------------------------------------------------------------
AttributesCls::Attributes *RPGObjectWithAttributes::getAttributes()
{
 return &ObjAttributes;
}
//---------------------------------------------------------------------------
RPGObjectWithAttributes::~RPGObjectWithAttributes()
{
}
//---------------------------------------------------------------------------
RPGObjectWithAttributes *RPGObjectWithAttributes::getCurrentTarget()
{
    return CurrentTarget;
}
//---------------------------------------------------------------------------
void RPGObjectWithAttributes::setCurrentTarget(RPGObjectWithAttributes *argTarget)
{
    CurrentTarget=argTarget;
}
//---------------------------------------------------------------------------
}//Attributes
}//RPGCls
//---------------------------------------------------------------------------
#pragma package(smart_init)




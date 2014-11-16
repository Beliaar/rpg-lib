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
#include "PowersClass.h"
#include "RPGClass.h"
using namespace std;
namespace RPGCls
{
namespace PowersCls
{
//---------------------------------------------------------------------------
 PowersEffect::PowersEffect(unsigned argID,std::string argName,std::string argDescription,float argDifficulty) : RPGObject(argID,argName,argDescription)
 {
  BaseDifficulty=argDifficulty;
  Difficulty=int(BaseDifficulty);
 }
//---------------------------------------------------------------------------
 int PowersEffect::getDifficulty()
 {
  return Difficulty;
 }
//---------------------------------------------------------------------------
PowersEffect::~PowersEffect()
{
}
//---------------------------------------------------------------------------
 void PowersEffect::setPowerStrength(int argPowerStrength)
 {

     PowerStrength=argPowerStrength;
     if(PowerStrength > 0)
     {
         Difficulty = int(BaseDifficulty * PowerStrength);
     }
     else if(PowerStrength < 0)
     {
         Difficulty = int(BaseDifficulty * (PowerStrength * -1));
     }
 }
//---------------------------------------------------------------------------
 int PowersEffect::getPowerStrength()
 {
   return PowerStrength;
 }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
PowersEffectChangeAttribute::PowersEffectChangeAttribute(std::string argName,std::string argDescription,float argDifficulty)  : PowersEffect(0,argName,argDescription,argDifficulty)
{
}
//---------------------------------------------------------------------------
void PowersEffectChangeAttribute::setChangedAttribute(TargetAttribute argChangedAttribute)
{
    ChangedAttribute=argChangedAttribute;
}
//---------------------------------------------------------------------------
TargetAttribute PowersEffectChangeAttribute::getChangedAttribute()
{
    return ChangedAttribute;
}
//---------------------------------------------------------------------------
void PowersEffectChangeAttribute::Execute(AttributesCls::RPGObjectWithAttributes *argCaster,int StrengthModifier)
{

 AttributesCls::Attributes *tempAttributes=argCaster->getCurrentTarget()->getAttributes();
 switch(ChangedAttribute)
 {
     case taCondition: tempAttributes->setCondition(tempAttributes->getCondition() + (getPowerStrength() + StrengthModifier));break;
     case taStrength: tempAttributes->setStrength(tempAttributes->getStrength() + (getPowerStrength() + StrengthModifier));break;
     case taDexterity: tempAttributes->setDexterity(tempAttributes->getDexterity() + (getPowerStrength() + StrengthModifier));break;
     case taIntelligence: tempAttributes->setIntelligence(tempAttributes->getIntelligence() + (getPowerStrength() + StrengthModifier));break;
     case taHitPoints: tempAttributes->setHitPoints(tempAttributes->getHitPoints() + (getPowerStrength() + StrengthModifier));break;
     case taPowerPoints: tempAttributes->setPowerPoints(tempAttributes->getPowerPoints() + (getPowerStrength() + StrengthModifier));break;
     case taNaturalResistance: tempAttributes->setNaturalResistance(tempAttributes->getNaturalResistance() + (getPowerStrength() + StrengthModifier));break;
     case taPowerResistance: tempAttributes->setPowerResistance(tempAttributes->getPowerResistance() + (getPowerStrength() + StrengthModifier));break;
 }

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Power::Power (unsigned argID,std::string argName,std::string argDescription) : RPGObject(argID,argName,argDescription)
{
}

int Power::getDifficultySum()
{
 int DifficultySum=0;
 for(std::vector<PowersEffect *>::iterator iter= Effects.begin();iter != Effects.end(); iter++)
 {
  PowersEffect *Effect= dynamic_cast<PowersEffect *>(*iter);
  try
  {
   DifficultySum += Effect->getDifficulty();
  }
  catch(...)
  {

  }
 }
 return DifficultySum;
}
//---------------------------------------------------------------------------
std::vector<PowersEffect *> Power::getEffects()
{
 return Effects;
}
//---------------------------------------------------------------------------
void Power::addEffect(PowersEffect *argEffect)
{
    Effects.push_back(argEffect);
}
//---------------------------------------------------------------------------
void Power::Execute(AttributesCls::RPGObjectWithAttributes *argCaster)
{
 for(std::vector<PowersEffect *>::iterator iter= Effects.begin();iter != Effects.end(); iter++)
 {
  PowersEffect *Effect= dynamic_cast<PowersEffect *>(*iter);
  try
  {
   Effect->Execute(argCaster,getTotalStrength());
  }
  catch(...)
  {

  }
 }
}
//---------------------------------------------------------------------------
int Power::getTotalStrength()
{
 int TotalStrength=0;
 for(std::vector<PowersEffect *>::iterator iter= Effects.begin();iter != Effects.end(); iter++)
 {
  PowersEffect *Effect= dynamic_cast<PowersEffect *>(*iter);
  try
  {
   TotalStrength += Effect->getPowerStrength();
  }
  catch(...)
  {

  }
 }
 return TotalStrength;
}
//---------------------------------------------------------------------------
PowersEffectConsumeCasterAttribute::PowersEffectConsumeCasterAttribute(std::string argName,std::string argDescription,float argDifficulty)  : PowersEffect(0,argName,argDescription,argDifficulty)
{
}
//---------------------------------------------------------------------------
void PowersEffectConsumeCasterAttribute::setChangedAttribute(TargetAttribute argChangedAttribute)
{
 ChangedAttribute=argChangedAttribute;
}
//---------------------------------------------------------------------------
TargetAttribute PowersEffectConsumeCasterAttribute::getChangedAttribute()
{
    return ChangedAttribute;
}
//---------------------------------------------------------------------------
void PowersEffectConsumeCasterAttribute::Execute(AttributesCls::RPGObjectWithAttributes *argCaster,int StrengthModifier)
{
 AttributesCls::Attributes *tempAttributes=argCaster->getCurrentTarget()->getAttributes();
 switch(ChangedAttribute)
 {
     case taCondition: tempAttributes->setCondition(tempAttributes->getCondition() - (getPowerStrength() + StrengthModifier));break;
     case taStrength: tempAttributes->setStrength(tempAttributes->getStrength() - (getPowerStrength() + StrengthModifier));break;
     case taDexterity: tempAttributes->setDexterity(tempAttributes->getDexterity() - (getPowerStrength() + StrengthModifier));break;
     case taIntelligence: tempAttributes->setIntelligence(tempAttributes->getIntelligence() - (getPowerStrength() + StrengthModifier));break;
     case taHitPoints: tempAttributes->setHitPoints(tempAttributes->getHitPoints() - (getPowerStrength() + StrengthModifier));break;
     case taPowerPoints: tempAttributes->setPowerPoints(tempAttributes->getPowerPoints() - (getPowerStrength() + StrengthModifier));break;
     case taNaturalResistance: tempAttributes->setNaturalResistance(tempAttributes->getNaturalResistance() - (getPowerStrength() + StrengthModifier));break;
     case taPowerResistance: tempAttributes->setPowerResistance(tempAttributes->getPowerResistance() - (getPowerStrength() + StrengthModifier));break;
 }
}
//---------------------------------------------------------------------------
void PowersEffectConsumeCasterAttribute::setPowerStrength(int argPowerStrength)
{
 if(argPowerStrength >= 0)
 {
     PowersEffect::setPowerStrength(argPowerStrength);
 }
}
//---------------------------------------------------------------------------
}//Powers
}//RPGCls
//---------------------------------------------------------------------------

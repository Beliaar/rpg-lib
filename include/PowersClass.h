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
#ifndef PowersClass_H
#define PowersClass_H
#include "RPGObject.h"
#include "AttributesClass.h"
#include <vector>
//---------------------------------------------------------------------------

namespace RPGCls
{
namespace PowersCls
{
typedef enum  {taCondition=0,taStrength,taDexterity,taIntelligence,taHitPoints,taPowerPoints,taNaturalResistance,taPowerResistance} TargetAttribute;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
  class PowersEffect : public RPGObjectCls::RPGObject
  {
    public:
            virtual int getDifficulty();
            PowersEffect(unsigned argID,std::string argName,std::string argDescription,float argDifficulty);
            virtual ~PowersEffect();
            //virtual int ExecuteEffect()=0;
            virtual void setPowerStrength(int argPowerStrength);
            virtual int getPowerStrength();
            virtual void Execute(AttributesCls::RPGObjectWithAttributes *argCaster,int StrengthModifier)=0;
    private:
            float BaseDifficulty;
            int Difficulty;
            int PowerStrength;

    protected:
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
  class PowersEffectChangeAttribute : public PowersEffect
  {
    public:
            PowersEffectChangeAttribute(std::string argName,std::string argDescription,float argDifficulty);
            void setChangedAttribute(TargetAttribute argChangedAttribute);
            TargetAttribute getChangedAttribute();
            void Execute(AttributesCls::RPGObjectWithAttributes *argCaster,int StrengthModifier);
    private:
            TargetAttribute ChangedAttribute;

  };
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
  class PowersEffectConsumeCasterAttribute : public PowersEffect
  {
    public:
            PowersEffectConsumeCasterAttribute(std::string argName,std::string argDescription,float argDifficulty);
            void setChangedAttribute(TargetAttribute argChangedAttribute);
            TargetAttribute getChangedAttribute();
            void Execute(AttributesCls::RPGObjectWithAttributes *argCaster,int StrengthModifier);
            void setPowerStrength(int argPowerStrength);
    private:
            TargetAttribute ChangedAttribute;

  };
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
  class Power : public RPGObjectCls::RPGObject
  {
      public:
            Power(unsigned argID,std::string argName,std::string argDescription);
            int getDifficultySum();
            std::vector<PowersEffect *> getEffects();
            void addEffect(PowersEffect *argEffect);
            void Execute(AttributesCls::RPGObjectWithAttributes *argCaster);
            int getTotalStrength();
      private:
            std::vector<PowersEffect *> Effects;
  };
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
}//Powers
}//RPGCls
#endif

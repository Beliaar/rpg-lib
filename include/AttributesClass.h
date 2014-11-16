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

#ifndef AttributesClassH
#define AttributesClassH
#include <string>
#include "RPGObject.h"
//---------------------------------------------------------------------------
namespace RPGCls
{
namespace AttributesCls
{
//---------------------------------------------------------------------------
class Attributes
{
private:
        int Condition;
        int Strength;
        int Dexterity;
        int Intelligence;

        int HitPoints;
        int PowerPoints;

        int NaturalResistance;
        int PowerResistance;

public:
        int getCondition();
        void setCondition(int argCondition);
        int getStrength();
        void setStrength(int argStrength);
        int getDexterity();
        void setDexterity(int argDexterity);
        int getIntelligence();
        void setIntelligence(int argIntelligence);
        int getMaxHitPoints();
        int getHitPoints();
        void setHitPoints(int argHitPoints);
        int getMaxPowerPoints();
        int getPowerPoints();
        void setPowerPoints(int argPowerPoints);
        int getNaturalResistance();
        void setNaturalResistance(int argNaturalResistance);
        int getPowerResistance();
        void setPowerResistance(int argPowerResistance);

        void operator+=(Attributes A);
        void  operator-=(Attributes A);
        void  operator*=(Attributes A);
        void  operator/=(Attributes A);
        void  operator=(Attributes A);

        void  operator+=(int A);
        void  operator-=(int A);
        void  operator*=(int A);
        void  operator/=(int A);
        void  operator=(int A);
        Attributes();

};
//---------------------------------------------------------------------------
class RPGObjectWithAttributes : public RPGObjectCls::RPGObject
{
  private:
          RPGObjectWithAttributes *CurrentTarget;
          RPGCls::AttributesCls::Attributes ObjAttributes;
  public:
          RPGObjectWithAttributes(unsigned argID,std::string argName,std::string argDescription);
          virtual ~RPGObjectWithAttributes();
          virtual void setAttributes(RPGCls::AttributesCls::Attributes argAttributes);
          virtual RPGCls::AttributesCls::Attributes *getAttributes();
          RPGObjectWithAttributes *getCurrentTarget();
          void setCurrentTarget(RPGObjectWithAttributes *argTarget);
};
//---------------------------------------------------------------------------
}//Attributes
}//RPGCls
//---------------------------------------------------------------------------
#endif

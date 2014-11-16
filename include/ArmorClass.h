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
#ifndef ArmorClass_H
#define ArmorClass_H
#include "Misc.h"
#include "RPGObject.h"
#include "InventoryClass.h"
/*
#define HEAD      0
#define CHEST     1
#define SHOULDER  2
#define ARMS      3
#define HAND      4
#define LEGS      5
#define FEET      6
*/
namespace RPGCls
{
 namespace ArmorCls
 {
           typedef enum {All=0,Head,Chest,Shoulder,Arm,Hand,Leg,Foot} ArmorType;
           class Armor : public InventoryCls::InventoryObject
           {
                  private:
                          int ArmorValue;
                          ArmorType Type;
                          std::vector<int> Weaknesses;
                          std::vector<int> Strengths;
                  public:
                          Armor(unsigned argID,unsigned argInventoryObjectID,std::string argName="",std::string argDescription="",ArmorType argArmorType=All,int argSpaceUsed=0,int argWeight=0);

                          void setArmorValue(int argArmorValue);
                          int getArmorValue();
                          void setArmorType(ArmorType argType);
                          ArmorType getArmorType();
                          void addWeakness(int argDamageTypeID);
                          void deleteWeakness(int argDamageTypeID);
                          void deleteWeaknessAll(int argDamageTypeID);
                          void addStrength(int argDamageTypeID);
                          void deleteStrength(int argDamageTypeID);
                          void deleteStrengthAll(int argDamageTypeID);
                          bool containsWeakness(int argDamageTypeID);
                          bool containsStrength(int argDamageTypeID);
           };
//---------------------------------------------------------------------------
           class RPGObjectWithArmor :  public RPGObjectCls::RPGObject
           {
                private:
                    unsigned ArmorID;
                public:
                    RPGObjectWithArmor(unsigned argID,std::string argName,std::string argDescription);
                    virtual ~RPGObjectWithArmor();
                    unsigned getArmorID();
                    void setArmorID(unsigned argArmorID);
           };

 }// ArmorCls
}// RPGCls
#endif

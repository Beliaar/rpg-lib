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
#ifndef RPGObjectH
#define RPGObjectH
#include <string>
//---------------------------------------------------------------------------
namespace RPGCls
{
 namespace RPGObjectCls
 {
    //typedef enum {otBase=0,otWAttributes,otCharacter,otArmor,otWArmor,otWeapon,otWWeapon,otAmmoType,otWeaponType,otInventory,otInventoryObject,otPower} ObjectType;
    class RPGObject
    {
     private:
            unsigned ID;
            std::string Name;
            std::string Description;

     protected:
            //ObjectType Type;

     public:
            RPGObject(unsigned argID,std::string argName,std::string argDescription);//,ObjectType Type=otBase);
            virtual ~RPGObject();
            unsigned getID();
            void setName(std::string argValue);
            std::string getName();
            void setDescription(std::string argValue);
            std::string getDescription();
            //ObjectType  getObjectType();
    };
//---------------------------------------------------------------------------
 }
}
#endif

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
#include "RPGObject.h"
namespace RPGCls
{
namespace RPGObjectCls
{
//---------------------------------------------------------------------------
RPGObject::RPGObject(unsigned argID,std::string argName,std::string argDescription)
{
    ID=argID;
    Name=argName;
    Description=argDescription;
}
//---------------------------------------------------------------------------
unsigned RPGObject::getID()
{
 return ID;
}
//---------------------------------------------------------------------------
void RPGObject::setName(std::string argValue)
{
 Name=argValue;
}
//---------------------------------------------------------------------------
std::string RPGObject::getName()
{
 return Name;
}
//---------------------------------------------------------------------------
void RPGObject::setDescription(std::string argValue)
{
 Description=argValue;
}
//---------------------------------------------------------------------------
std::string RPGObject::getDescription()
{
 return Description;
}
//---------------------------------------------------------------------------
RPGObject::~RPGObject()
{
}

}
}


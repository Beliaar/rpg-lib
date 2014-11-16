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
#ifndef InventoryClassH
#define InventoryClassH
#include "AttributesClass.h"
#include <vector>

namespace RPGCls
{
 namespace InventoryCls
 {

//---------------------------------------------------------------------------
   class InventoryObject : public AttributesCls::RPGObjectWithAttributes
   {
         protected:
                  int SpaceUsed;
                  int Weight;
                  unsigned InventoryID;
                  unsigned InventoryIndex;
                  unsigned InventoryObjectID;

         public:
                  InventoryObject(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription="",int argSpaceUsed=0,int argWeight=0);
                  virtual ~InventoryObject();
                  void setSpaceUsed(int argSpaceUsed);
                  int getSpaceUsed();
                  void setWeight(int argWeight);
                  int getWeight();
                  void setInventoryID(unsigned argInventoryID);
                  unsigned getInventoryID();
                  void setInventoryIndex(unsigned argInventoryIndex);
                  unsigned getInventoryIndex();
                  unsigned getInventoryObjectID();

   };

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
   class Inventory : public InventoryObject
   {
         private:
                  std::vector<InventoryObject *>  ObjectsStored;
                  //Storage capacity of inventory
                  //if set to -1 or lower then the capacity is unlimited
                  int maxStorage;
                  int StorageUsed;
                  //Maximal carrieable weight of inventory
                  //No restriction if set to -1 or lower
                  int maxWeight;
                  int WeightUsed;
         public:
                  Inventory(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription="",int argmaxStorage=0,int argSpaceUsed=0,int argWeight=0);
                  bool putIntoInventory(InventoryObject *argpObject, std::vector<InventoryObject *>::iterator *pIteratorInv);
                  bool takeFromInventory(InventoryObject argObject);
                  void setMaxStorage(int argMaxStorage);
                  int getMaxStorage();
                  int getStorageUsed();
                  void recalculateStorageUsed();
                  void setMaxWeight(int argmaxWeight);
                  int getMaxWeight();
                  int getWeightUsed();

   };
//---------------------------------------------------------------------------
 }
}

#endif

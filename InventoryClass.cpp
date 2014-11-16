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
#include "InventoryClass.h"
namespace RPGCls
{
 namespace InventoryCls
 {
  using namespace std;
//---------------------------------------------------------------------------
InventoryObject::InventoryObject(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription,int argSpaceUsed,int argWeight) :RPGObjectWithAttributes(argID,argName,argDescription)
{
 InventoryObjectID =argInventoryObjectID;
 InventoryID=0;
 InventoryIndex=0;
 SpaceUsed=argSpaceUsed;
 Weight=argWeight;
}
//---------------------------------------------------------------------------
void InventoryObject::setSpaceUsed(int argSpaceUsed)
{
 SpaceUsed=argSpaceUsed;
}
//---------------------------------------------------------------------------
int InventoryObject::getSpaceUsed()
{
 return SpaceUsed;
}
//---------------------------------------------------------------------------
void InventoryObject::setWeight(int argWeight)
{
 Weight=argWeight;
}
//---------------------------------------------------------------------------
int InventoryObject::getWeight()
{
 return Weight;
}
//---------------------------------------------------------------------------
void InventoryObject::setInventoryID(unsigned argInventoryID)
{
 InventoryID=argInventoryID;
}
//---------------------------------------------------------------------------
unsigned InventoryObject::getInventoryID()
{
 return InventoryID;
}
//---------------------------------------------------------------------------
void InventoryObject::setInventoryIndex(unsigned argInventoryIndex)
{
 InventoryIndex=argInventoryIndex;
}
//---------------------------------------------------------------------------
unsigned InventoryObject::getInventoryIndex()
{
 return InventoryIndex;
}
//---------------------------------------------------------------------------
unsigned InventoryObject::getInventoryObjectID()
{
 return InventoryObjectID;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Inventory::Inventory(unsigned argID,unsigned argInventoryObjectID,std::string argName,std::string argDescription,int argmaxStorage,int argSpaceUsed,int argWeight) : InventoryObject(argID,argInventoryObjectID,argName,argDescription,argSpaceUsed,argWeight)
{
 maxStorage=argmaxStorage;
 StorageUsed=0;
 WeightUsed=0;
}
//---------------------------------------------------------------------------
bool Inventory::putIntoInventory(InventoryObject *Object, std::vector<InventoryObject *>::iterator *iterInv)
{
 //Das Objekt darf keinem anderem Inventar zugewiesen sein,
 //ausserdem darf der Platz und Gewicht nicht überschritten werden
 if(Object->getInventoryID() == 0 && Object->getInventoryIndex() == 0 && (maxStorage <= -1 || StorageUsed + Object->getSpaceUsed() < maxStorage) && (maxWeight <= -1 || WeightUsed + Object->getWeight() < maxWeight))
 {
     ObjectsStored.push_back(Object);
     StorageUsed+=Object->getSpaceUsed();
     WeightUsed+=Object->getWeight();
     Object->setInventoryID(getID());
     Object->setInventoryIndex(ObjectsStored.size());
     *iterInv=ObjectsStored.end()-1;
     return true;
 }
 else
 {
     return false;
 }

}
//---------------------------------------------------------------------------
bool Inventory::takeFromInventory(InventoryObject Object)
{
 if(Object.getInventoryID()==getID())
 {
  StorageUsed-=Object.getSpaceUsed();
  WeightUsed-=Object.getWeight();
  vector<InventoryObject *>::iterator TempIterator=ObjectsStored.begin() + Object.getInventoryIndex();
  (*TempIterator)->setInventoryID(0);
  (*TempIterator)->setInventoryIndex(0);
  ObjectsStored.erase(ObjectsStored.begin() + Object.getInventoryIndex());
  return true;
 }
 return false;
}
//---------------------------------------------------------------------------
void Inventory::setMaxStorage(int argmaxStorage)
{
 maxStorage=argmaxStorage;
}
//---------------------------------------------------------------------------
int Inventory::getMaxStorage()
{
 return maxStorage;
}
//---------------------------------------------------------------------------
int Inventory::getStorageUsed()
{
 return StorageUsed;
}
//---------------------------------------------------------------------------
void Inventory::recalculateStorageUsed()
{
 StorageUsed=0;
 for(std::vector<InventoryObject *>::iterator TempIterator= ObjectsStored.begin();TempIterator != ObjectsStored.end();TempIterator++)
 {
  StorageUsed+=(*TempIterator)->getSpaceUsed();
 }
}
//---------------------------------------------------------------------------
void Inventory::setMaxWeight(int maxWeight)
{
 this->maxWeight=maxWeight;
}
//---------------------------------------------------------------------------
int Inventory::getMaxWeight()
{
 return maxWeight;
}
//---------------------------------------------------------------------------
int Inventory::getWeightUsed()
{
 return WeightUsed;
}
//---------------------------------------------------------------------------
InventoryObject::~InventoryObject()
{
}
//---------------------------------------------------------------------------
}
}

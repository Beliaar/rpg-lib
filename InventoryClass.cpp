#include "InventoryClass.h"
namespace RPGCls
{
 namespace InventoryCls
 {
  using namespace std;
//---------------------------------------------------------------------------
InventoryObject::InventoryObject()
{
 uInventoryID=0;
 uInventoryIndex=0;
 iSpaceUsed = 0;
 iWeight=0;
}
//---------------------------------------------------------------------------
InventoryObject::InventoryObject(int SpaceUsed)
{
 uInventoryID=0;
 uInventoryIndex=0;
 iSpaceUsed = SpaceUsed;
 iWeight=0;
}
//---------------------------------------------------------------------------
InventoryObject::InventoryObject(int SpaceUsed,int Weight)
{
 uInventoryID=0;
 uInventoryIndex=0;
 iSpaceUsed = SpaceUsed;
 iWeight=Weight;
}
//---------------------------------------------------------------------------
void InventoryObject::InventoryObject::SetSpaceUsed(int Value)
{
iSpaceUsed = Value;
}
//---------------------------------------------------------------------------
int InventoryObject::InventoryObject::GetSpaceUsed()
{
 return iSpaceUsed;
}
//---------------------------------------------------------------------------
void InventoryObject::InventoryObject::SetWeight(int Value)
{
iWeight = Value;
}
//---------------------------------------------------------------------------
int InventoryObject::InventoryObject::GetWeight()
{
return iWeight;
}
//---------------------------------------------------------------------------
void InventoryObject::SetInventoryID(unsigned InventoryID)
{
 uInventoryID=InventoryID;
}
//---------------------------------------------------------------------------
unsigned InventoryObject::GetInventoryID()
{
 return uInventoryID;
}
//---------------------------------------------------------------------------
void InventoryObject::SetInventoryIndex(unsigned InventoryIndex)
{
 uInventoryIndex=InventoryIndex;
}
//---------------------------------------------------------------------------
unsigned InventoryObject::GetInventoryIndex()
{
 return uInventoryIndex;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
Inventory::Inventory()
{
 iMaxStorage=0;
}
//---------------------------------------------------------------------------
Inventory::Inventory(int MaxStorage)
{
 iMaxStorage=MaxStorage;
}
//---------------------------------------------------------------------------
bool Inventory::PutIntoInventory(InventoryObject *Object, std::vector<InventoryObject *>::iterator *iterInv)
{
 //Das Objekt darf keinem anderem Inventar zugewiesen sein, 
 //ausserdem darf der Platz und Gewicht nicht überschritten werden
 if(Object->GetInventoryID() == 0 && Object->GetInventoryIndex() == 0 && (iStorageUsed + Object->GetSpaceUsed() < iMaxStorage || iMaxStorage==-1) && (iWeightUsed + Object->GetWeight() < iMaxWeight || iMaxWeight == -1))
 {
     ObjectsStored.push_back(Object);
     iStorageUsed+=Object->GetSpaceUsed();
     iWeightUsed+=Object->GetWeight();
     Object->SetInventoryID(uID);
     Object->SetInventoryIndex(ObjectsStored.size());
     *iterInv=ObjectsStored.end()-1;
     return true;
 }
 else
 {
     return false;
 }
     
}
//---------------------------------------------------------------------------
bool Inventory::TakeFromInventory(InventoryObject Object)
{
 if(Object.GetInventoryID()==uID)
 {
  iStorageUsed-=Object.GetSpaceUsed();
  iWeightUsed-=Object.GetWeight();
  vector<InventoryObject *>::iterator iterTemp=ObjectsStored.begin() + Object.GetInventoryIndex();
  (*iterTemp)->SetInventoryID(0);
  (*iterTemp)->SetInventoryIndex(0);
  ObjectsStored.erase(ObjectsStored.begin() + Object.GetInventoryIndex());
  return true;
 }
 return false;
}
//---------------------------------------------------------------------------
void Inventory::SetMaxStorage(int Value)
{
 iMaxStorage=Value;
}
//---------------------------------------------------------------------------
int Inventory::GetMaxStorage()
{
 return iMaxStorage;
}
//---------------------------------------------------------------------------
int Inventory::GetStorageUsed()
{
 return iStorageUsed;
}
//---------------------------------------------------------------------------
void Inventory::RecalculateStorageUsed()
{
 iStorageUsed=0;
 for(std::vector<InventoryObject *>::iterator iterTemp= ObjectsStored.begin();iterTemp != ObjectsStored.end();iterTemp++)
 {
  iStorageUsed+=(*iterTemp)->GetSpaceUsed(); 
 }
}
//---------------------------------------------------------------------------
void Inventory::SetMaxWeight(int MaxWeight)
{
 iMaxWeight=MaxWeight;
}
//---------------------------------------------------------------------------
int Inventory::GetMaxWeight()
{
 return iMaxWeight;
}
//---------------------------------------------------------------------------
int Inventory::GetWeightUsed()
{
 return iWeightUsed;
}
//---------------------------------------------------------------------------
 }
}

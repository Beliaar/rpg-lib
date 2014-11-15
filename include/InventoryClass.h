#ifndef InventoryClassH
#define InventoryClassH
#include "RPGObject.h"
#include <vector>

namespace RPGCls
{
 namespace InventoryCls
 {

//---------------------------------------------------------------------------
   class InventoryObject : public RPGObjectCls::RPGObject
   {
         protected:
                  int iSpaceUsed;
                  int iWeight;
                  unsigned uInventoryID;
                  unsigned uInventoryIndex;
                  
         public:
                  InventoryObject();
                  InventoryObject(int SpaceUsed);
                  InventoryObject(int SpaceUsed,int Weight);
                  void SetSpaceUsed(int Value);
                  int GetSpaceUsed();
                  void SetWeight(int Value);
                  int GetWeight();
                  void SetInventoryID(unsigned InventoryID);
                  unsigned GetInventoryID();
                  void SetInventoryIndex(unsigned InventoryIndex);
                  unsigned GetInventoryIndex();
                  
   };

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
   class Inventory : public InventoryObject
   {
         private:
                  std::vector<InventoryObject *>  ObjectsStored;
                  //Storage capacity of inventory
                  //if set to -1 then the capacity is unlimited
                  int iMaxStorage; 
                  int iStorageUsed;
                  //Maximal carrieable weight of inventory
                  //No restriction if set to -1
                  int iMaxWeight;
                  int iWeightUsed;
         public:
                  Inventory();
                  Inventory(int MaxStorage);
                  bool PutIntoInventory(InventoryObject *Object, std::vector<InventoryObject *>::iterator *iterInv);
                  bool TakeFromInventory(InventoryObject Object);
                  void SetMaxStorage(int Value);
                  int GetMaxStorage();
                  int GetStorageUsed();
                  void RecalculateStorageUsed();
                  void SetMaxWeight(int MaxWeight);
                  int GetMaxWeight();
                  int GetWeightUsed();
                 
   };
//---------------------------------------------------------------------------
 }
}

#endif

//---------------------------------------------------------------------------

#ifndef CharacterClassH
#define CharacterClassH
#include "AttributesClass.h"
#include "RPGObject.h"
#include "InventoryClass.h"
#include <string>
namespace RPGCls
{
namespace CharacterCls
{
//---------------------------------------------------------------------------
class Character : public RPGObjectCls::RPGObject
{
 private:
         unsigned uLeftHandWeaponID;
         unsigned uRightHandWeaponID;
         unsigned uLeftHandObjectID;
         unsigned uRightHandObjectID;
         unsigned uHeadArmorID;
         unsigned uShoulderArmorID;
         unsigned uChestArmorID;
         unsigned uArmArmorID;
         unsigned uHandArmorID;
         unsigned uLegArmorID;
         unsigned uFootArmorID;
         unsigned uInventoryID;
         //std::vector<unsigned> Powers;
         RPGCls::AttributesCls::Attributes attrChar_Attributes;
 public:
         Character(unsigned vID);
         Character(unsigned vID,std::string vName);

         void SetLeftHandWeaponID(unsigned Value);
         unsigned GetLeftHandWeaponID();
         void SetRightHandWeaponID(unsigned Value);
         unsigned GetRightHandWeaponID();

         void SetLeftHandObjectID(unsigned Value);
         unsigned GetLeftHandObjectID();
         void SetRightHandObjectID(unsigned Value);
         unsigned GetRightHandObjectID();

         void SetHeadArmorID(unsigned Value);
         unsigned GetHeadArmorID();
         void SetShoulderArmorID(unsigned Value);
         unsigned GetShoulderArmorID();
         void SetChestArmorID(unsigned Value);
         unsigned GetChestArmorID();
         void SetArmArmorID(unsigned Value);
         unsigned GetArmArmorID();
         void SetHandArmorID(unsigned Value);
         unsigned GetHandArmorID();
         void SetLegArmorID(unsigned Value);
         unsigned GetLegArmorID();
         void SetFootArmorID(unsigned Value);
         unsigned GetFootArmorID();
         
         void SetInventoryID(unsigned Value);
         unsigned GetInventoryID();
         
         void SetAttributes(RPGCls::AttributesCls::Attributes Value);
         RPGCls::AttributesCls::Attributes *GetAttributes();
         
};
//---------------------------------------------------------------------------
}//CharacterCls
}//RPGCls
#endif

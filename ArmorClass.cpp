//---------------------------------------------------------------------------

#include <string>
#include "ArmorClass.h"
using namespace std;
//---------------------------------------------------------------------------
namespace RPGCls
{
namespace ArmorCls
{
//---------------------------------------------------------------------------
Armor::Armor(int vID)
{
    uID=vID;
    sName="";
    sDescription="";
    iArmorValue=0;
    atType=All;
}            
//---------------------------------------------------------------------------
Armor::Armor(int vID,std::string vName)
{
    uID=vID;
    sName=vName;
    sDescription="";
    iArmorValue=0;
    atType=All;
}            
//---------------------------------------------------------------------------
Armor::Armor(int vID,std::string vName,std::string vDescription)
{
    uID=vID;
    sName=vName;
    sDescription=vDescription;
    iArmorValue=0;
    atType=All;
}
//---------------------------------------------------------------------------
Armor::Armor(int vID,std::string vName,std::string vDescription,ArmorType vArmorType)
{
    uID=vID;
    sName=vName;
    sDescription=vDescription;
    atType=vArmorType;
    iArmorValue=0;

}
void Armor::SetArmorValue(int Value)
{
    iArmorValue=Value;
}            
//---------------------------------------------------------------------------
int Armor::GetArmorValue()
{
    return iArmorValue;
}
//---------------------------------------------------------------------------
void Armor::SetArmorType(ArmorType Value)
{
 atType=Value;
}
//---------------------------------------------------------------------------
ArmorType Armor::GetArmorType()
{
 return atType;
}
//---------------------------------------------------------------------------
void Armor::AddWeakness(int DamageTypeID)
{
 vWeaknesses.push_back(DamageTypeID);
}            
//---------------------------------------------------------------------------
void Armor::DeleteWeakness(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vWeaknesses.begin(); iIter != vWeaknesses.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
  {
     vWeaknesses.erase(iIter);
     return;     
  }
 }
}
//---------------------------------------------------------------------------
void Armor::DeleteWeaknessAll(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vWeaknesses.begin(); iIter != vWeaknesses.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
  {
     vWeaknesses.erase(iIter);
  }
 }
}
//---------------------------------------------------------------------------
void Armor::AddStrength(int DamageTypeID)
{
     vStrengths.push_back(DamageTypeID);
}            
//---------------------------------------------------------------------------
void Armor::DeleteStrength(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vStrengths.begin(); iIter != vStrengths.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
  {
     vStrengths.erase(iIter);
     return;     
  }
 }
}
//---------------------------------------------------------------------------
void Armor::DeleteStrengthAll(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vStrengths.begin(); iIter != vStrengths.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
  {
     vStrengths.erase(iIter);
  }
 }
}
//---------------------------------------------------------------------------
bool Armor::ContainsWeakness(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vWeaknesses.begin(); iIter != vWeaknesses.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
     return true;      
 }
 return false;
}            
//---------------------------------------------------------------------------
bool Armor::ContainsStrength(int DamageTypeID)
{
 for(vector<int>::iterator iIter=vStrengths.begin(); iIter != vStrengths.end(); iIter++)
 {
  if (DamageTypeID==*iIter)
     return true;      
 }
 return false;
}            
//---------------------------------------------------------------------------

}
}


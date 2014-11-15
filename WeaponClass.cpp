#include "WeaponClass.h"
namespace RPGCls
{
namespace WeaponCls
{

//---------------------------------------------------------------------------
AmmoType::AmmoType(unsigned vID)
{
  uID=vID;
}
//---------------------------------------------------------------------------
AmmoType::AmmoType(unsigned vID,std::string vName)
{
  uID=vID;
  sName=vName;
}
//---------------------------------------------------------------------------
AmmoType::AmmoType(unsigned vID,std::string vName,std::string vDescription)
{
  uID=vID;
  sName=vName;
  sDescription=vDescription;
}
//---------------------------------------------------------------------------
AmmoType::AmmoType(unsigned vID,std::string vName,std::string vDescription,unsigned vDamageTypeID)        
{
  uID=vID;
  sName=vName;
  sDescription=vDescription;
  uDamageTypeID=vDamageTypeID;
}
//---------------------------------------------------------------------------
void AmmoType::SetDamageTypeID(unsigned Value)
{
 uDamageTypeID= Value;
}
//---------------------------------------------------------------------------
unsigned AmmoType::GetDamageTypeID()
{
 return uDamageTypeID;
}
//---------------------------------------------------------------------------
WeaponType::WeaponType(unsigned vID)
{
  uID=vID;
}
//---------------------------------------------------------------------------
WeaponType::WeaponType(unsigned vID,std::string vName)
{
 uID=vID;
 sName=vName;
}
//---------------------------------------------------------------------------
WeaponType::WeaponType(unsigned vID,std::string vName,std::string vDescription)
{
 uID=vID;
 sName=vName;
 sDescription=vDescription;
}
//---------------------------------------------------------------------------
WeaponType::WeaponType(unsigned vID,std::string vName,std::string vDescription,unsigned vAmmoTypeID)
{
 uID=vID;
 sName=vName;
 sDescription=vDescription;
 uAmmoTypeID=vAmmoTypeID;
}
//---------------------------------------------------------------------------
void WeaponType::SetAmmoTypeID(unsigned Value)
{
 uAmmoTypeID= Value;
}
//---------------------------------------------------------------------------
unsigned WeaponType::GetAmmoTypeID()
{
 return uAmmoTypeID;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID)
{
 uID=vID;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID,std::string vName)
{
 uID=vID;
 sName=vName;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID,std::string vName,unsigned vTypeID)
{
 uID=vID;
 sName=vName;
 uTypeID=vTypeID;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID)
{
 uID=vID;
 sName=vName;
 uTypeID=vTypeID;
 uDamageTypeID=vDamageTypeID;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID,int vDamagePerHit )
{
 uID=vID;
 sName=vName;
 uTypeID=vTypeID;
 uDamageTypeID=vDamageTypeID;
 iDamagePerHit=vDamagePerHit;
}
//---------------------------------------------------------------------------
Weapon::Weapon(unsigned vID,std::string vName,unsigned vTypeID,unsigned vDamageTypeID,int vDamagePerHit, int vWeight )
{
 uID=vID;
 sName=vName;
 uTypeID=vTypeID;
 uDamageTypeID=vDamageTypeID;
 iDamagePerHit=vDamagePerHit;
 iWeight=vWeight;
}
//---------------------------------------------------------------------------
void Weapon::SetTypeID(unsigned Value)
{
 uTypeID=Value;
}
//---------------------------------------------------------------------------
unsigned Weapon::GetTypeID()
{
 return uTypeID;
}
//---------------------------------------------------------------------------
void Weapon::SetDamageTypeID(unsigned Value)
{
 uDamageTypeID=Value;
}
//---------------------------------------------------------------------------
unsigned Weapon::GetDamageTypeID()
{
 return uDamageTypeID;
}
//---------------------------------------------------------------------------
void Weapon::SetDamagePerHit(int Value)
{
 iDamagePerHit=Value;
}
//---------------------------------------------------------------------------
int Weapon::GetDamagePerHit()
{
 return iDamagePerHit;
}
//---------------------------------------------------------------------------


}
}

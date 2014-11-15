#include "RPGObject.h"
namespace RPGCls
{
namespace RPGObjectCls
{
//---------------------------------------------------------------------------
unsigned RPGObject::GetID()
{
 return uID;
}
//---------------------------------------------------------------------------
void RPGObject::SetName(std::string Value)
{
 sName=Value;
}
//---------------------------------------------------------------------------
std::string RPGObject::GetName()
{
 return sName;
}
//---------------------------------------------------------------------------
void RPGObject::SetDescription(std::string Value)
{
 sDescription=Value;
}
//---------------------------------------------------------------------------
std::string RPGObject::GetDescription()
{
 return sDescription;
}
//---------------------------------------------------------------------------
}
}


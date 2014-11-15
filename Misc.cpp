//---------------------------------------------------------------------------
#include "Misc.h"
using namespace std;
namespace RPGCls
{
namespace RPG_Misc
{
//---------------------------------------------------------------------------
DamageType::DamageType(unsigned vuID)
{
 uID=vuID;
}
//---------------------------------------------------------------------------
DamageType::DamageType(unsigned vuID,std::string vsName)
{
 uID=vuID;
 sName=vsName;
}
//---------------------------------------------------------------------------
DamageType::DamageType(unsigned vuID,std::string vsName,std::string vsDescription)
{
 uID=vuID;
 sName=vsName;
 sDescription=vsDescription;
}
//---------------------------------------------------------------------------

void trim(string& str)
{
  string::size_type pos = str.find_last_not_of(' ');
  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}

}//RPG_Misc
}//RPGCls

#ifndef MISC_H
#define MISC_H
#include <string>
#include <vector>
#include "RPGObject.h"
namespace RPGCls
{
namespace RPG_Misc
{
class DamageType : public RPGObjectCls::RPGObject
{
 private:

 public:
         DamageType(unsigned vID);
         DamageType(unsigned vID,std::string vName);
         DamageType(unsigned vID,std::string vName,std::string vDescription);
       
};

void trim(std::string& str);

}//RPG_Misc
}//RPGCls
#endif

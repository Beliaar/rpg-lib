#ifndef RPGObjectH
#define RPGObjectH
#include <string>
//---------------------------------------------------------------------------
namespace RPGCls
{
 namespace RPGObjectCls
 {
    class RPGObject
    {
     protected:
             unsigned uID;
             std::string sName;
             std::string sDescription;
     public:
             unsigned GetID();
             void SetName(std::string Value);
             std::string GetName();  
             void SetDescription(std::string Value);
             std::string GetDescription();  
    };        
//---------------------------------------------------------------------------
 }
}
#endif

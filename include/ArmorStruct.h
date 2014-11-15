#ifndef ArmorStruct_H
#define ArmorStruct_H
#include "Misc.h"

namespace RPGCls
{
 namespace ArmorStrct
 {
           class Armor
           {
                  private:
                          unsigned ID;
                          std::string Name;
                          std::string Description;
                          int ArmorValue;
                          std::vector<int> Weaknesses;
                          std::vector<int> Strengths;
                  public:
                          Armor(int vID);            
                          Armor(int vID,std::string vName);            
           };
 }// ArmorStrct
}// RPGCls
#endif

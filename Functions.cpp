//---------------------------------------------------------------------------

#include "Functions.h"
#include <sstream>

//---------------------------------------------------------------------------
std::string IntToString(int i)
{
    std::ostringstream temp;
    temp << i;
    return temp.str();
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
 

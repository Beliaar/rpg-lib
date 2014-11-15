//---------------------------------------------------------------------------

#ifndef AttributesClassH
#define AttributesClassH
#include <string>

//---------------------------------------------------------------------------
namespace RPGCls
{
namespace AttributesCls
{
class Attributes
{
private:
        int fKon; //Kondition
        int fStr; //Stärke
        int fDex; //Dexchicklickkeit
        int fInt; //Intelligenz

        int fTP; //Trefferpunkte: Kon* (4/3)
        int fMP; //Magiepunkte: Int * (3/2)


public:
        int GetKon();
        void SetKon(int value);
        int GetStr();
        void SetStr(int value);
        int GetDex();
        void SetDex(int value);
        int GetInt();
        void SetInt(int value);
        int GetMaxTP();
        int GetTP();
        void SetTP(int value);
        int GetMaxMP();
        int GetMP();
        void SetMP(int value);
        Attributes();

};
}//Attributes
}//RPGCls
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
//These source file contains functions
//Some i made myself and others found throughout the web
//you can use these wherever you want.There is no 'special' license to these
//---------------------------------------------------------------------------
#include "Functions.h"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
string convertIntegerToString(int Integer)
{
    ostringstream temp;
    temp << Integer;
    return temp.str();
}
//---------------------------------------------------------------------------
string translateText(string ToTranslate,string Language)
{
 string Ret=ToTranslate,Read,Temp;
 try
 {
     ifstream Locale(string(Language + ".lng").c_str());
     if(Locale)
     {
         bool Found=false;
         while(!Found && !Locale.eof())
         {
          getline(Locale,Read);
          Temp=Read.substr(1,Read.find("\"",1) -1);
          
          if(Temp==ToTranslate)
          {
           Ret=Read.substr(Read.find("=") +1,Read.length());
           Ret.erase(1,1);
           Ret.erase(Ret.length() -1,1);
          
           Found=true;
          }
          
         }
         Locale.close();
     }
 }
 catch(...)
 {
  cout << "Error reading language File \"" << Language + ".lng\"" << std::endl;
 }    
 return Ret;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
 

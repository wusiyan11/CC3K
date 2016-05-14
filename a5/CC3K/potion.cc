#include "potion.h"
#include <iostream>
using namespace std;

Potion::Potion(string pname) : pname(pname) {}
    
string Potion::get_pname(){
   return pname;
}


string get_type(){
  return "Potion";
}





     

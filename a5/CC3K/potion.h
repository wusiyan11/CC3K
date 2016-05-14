#ifndef __POTION_H__
#define __POTION_H__
#include "item.h"
 #include <string>
using namespace std;


class playercharacter;

class Potion : public Item {
  protected:
     string pname;
  public:
     Potion(string pname);
     string get_pname();
     //string create_potion();
     string get_type();
     virtual void use_potion(playercharacter * player) = 0;
     //virtual ~Potion();
};

#endif
   










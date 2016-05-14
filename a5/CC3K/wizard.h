#ifndef __WIZARD_H__
#define __WIZARD_H__
#include "playercharacter.h"
#include "potion.h"
using namespace std;

class Wizard : public playercharacter {
  public: 
     Wizard();
     void use_potion(Potion *p);
};

#endif





#ifndef __SAMURAI_H__
#define __SAMURAI_H__
#include "playercharacter.h"
#include "potion.h"
using namespace std;

class Samurai : public playercharacter {
  public: 
     Samurai();
     void use_potion(Potion *p);
};

#endif




#ifndef __POTION_WA_H__
#define __POTION_WA_H__
#include "potion.h"
#include "item.h"
#include "playercharacter.h"
using namespace std;

class WA : public Potion {
  public:
     WA();
     void use_potion(playercharacter * player);
};

#endif


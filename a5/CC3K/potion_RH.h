#ifndef __POTION_RH_H__
#define __POTION_RH_H__
#include "potion.h"
#include "item.h"
#include "playercharacter.h"
using namespace std;

class RH : public Potion {
  public:
     RH();
     void use_potion(playercharacter * player);
};

#endif


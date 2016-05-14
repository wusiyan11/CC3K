#ifndef __POTION_PH_H__
#define __POTION_PH_H__
#include "potion.h"
#include "item.h"
#include "playercharacter.h"
using namespace std;

class PH : public Potion {
  public:
     PH();
     void use_potion(playercharacter * player);
};

#endif





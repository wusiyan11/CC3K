#ifndef __POTION_WD_H__
#define __POTION_WD_H__
#include "potion.h"
#include "item.h"
#include "playercharacter.h"
using namespace std;

class WD : public Potion {
  public:
     WD();
     void use_potion(playercharacter * player);
};

#endif





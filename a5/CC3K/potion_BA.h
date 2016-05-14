#ifndef __POTION_BA_H__
#define __POTION_BA_H__
#include "potion.h"
using namespace std;
#include "playercharacter.h"
class playercharacter;

class BA : public Potion {
  public:
     BA();
     void use_potion(playercharacter * player);
};

#endif




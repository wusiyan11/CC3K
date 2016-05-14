#ifndef __POTION_BD_H__
#define __POTION_BD_H__
#include "potion.h"
#include "item.h"
#include "playercharacter.h"
using namespace std;

class BD : public Potion {
  public:
     BD();
     void use_potion(playercharacter * player);
};

#endif





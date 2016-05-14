#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "playercharacter.h"
#include "potion.h"
using namespace std;


class Knight : public playercharacter {
  public: 
     Knight();
     void use_potion(Potion *p);
};

#endif



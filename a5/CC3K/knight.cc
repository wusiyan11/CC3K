#include <iostream>
#include "knight.h"

using namespace std;

Knight::Knight() : playercharacter(NULL,100, 50, 50, 0, 0,0,100, true, "Knight") {}

void Knight::use_potion(Potion * p){
   p->use_potion(this);
}




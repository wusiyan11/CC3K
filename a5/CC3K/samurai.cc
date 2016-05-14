
#include <iostream>
#include "samurai.h"
using namespace std;

Samurai::Samurai() : playercharacter(NULL,100, 50, 50, 0, 0, 0,100, true, "Samurai") {}

void Samurai::use_potion(Potion * p){
   p->use_potion(this);
}


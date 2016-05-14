
#include <iostream>
#include "wizard.h"
using namespace std;

Wizard::Wizard() : playercharacter(NULL, 100, 50, 50,0, 0, 0,100, true, "Wizard") {}

void Wizard::use_potion(Potion * p){
   p->use_potion(this);
}

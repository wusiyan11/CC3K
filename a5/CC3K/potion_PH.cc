#include <iostream>
#include "potion_PH.h"
#include "item.h"
#include "playercharacter.h"
#include "potion.h"
using namespace std;

PH::PH() : Potion("PH") {}

void PH::use_potion(playercharacter * player){
   int hp = player->get_HP();  
   player->set_HP(hp - 30);
}







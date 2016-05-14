#include <iostream>
#include "potion_RH.h"
#include "item.h"
#include "playercharacter.h"
#include "potion.h"
using namespace std;

RH::RH() : Potion("RH") {}

void RH::use_potion(playercharacter * player){
   int hp = player->get_HP();  
   player->set_HP(hp + 30);
}





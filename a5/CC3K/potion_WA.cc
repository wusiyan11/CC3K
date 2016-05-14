#include <iostream>
#include "potion_WA.h"
#include "item.h"
#include "playercharacter.h"
#include "potion.h"
using namespace std;

WA::WA() : Potion("WA") {}

void WA::use_potion(playercharacter * player){
   int current_atk = player->get_atk();
   int extra_attack = player->get_extra_atk();
   if (current_atk + extra_attack - 5 <= 0) {
      player->set_extra_atk(-current_atk);
   } 
   else {
      player->set_extra_atk(extra_attack - 5);
   }
}






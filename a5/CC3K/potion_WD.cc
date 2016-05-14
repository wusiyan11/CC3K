#include <iostream>
#include "potion_WD.h"
#include "item.h"
#include "playercharacter.h"
#include "potion.h"
using namespace std;

WD::WD() : Potion("WD") {}

void WD::use_potion(playercharacter * player){
   int current_def = player->get_def();
   int extra_defence = player->get_extra_def();
   if (current_def + extra_defence - 5 <= 0) {
      player->set_extra_def(-current_def);
   } 
   else {
      player->set_extra_def(extra_defence - 5);
   }
}



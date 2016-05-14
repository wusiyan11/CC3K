#include <iostream>
#include "potion_BD.h"
#include "playercharacter.h"
#include "potion.h"
using namespace std;

BD::BD() : Potion("BD") {}

void BD::use_potion(playercharacter * player){
   int total_defence = player->get_def() + player->get_extra_def() + 10;
   if (total_defence >= 100) {
      player->full_def();
   }
   else {
      player->add_def();
   }    
}







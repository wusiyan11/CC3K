#include "potion_BA.h"
#include <iostream>
using namespace std;

BA::BA() : Potion("BA") {}


void BA::use_potion(playercharacter* player){
   player->add_atk();
}




























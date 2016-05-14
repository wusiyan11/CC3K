#include "treasure.h"
#include <iostream>
using namespace std;

Treasure::Treasure(int value, string kind) : value(value), kind(kind) {}

int Treasure::get_value(){
   return value;
}

string Treasure::get_kind(){
   return kind;
}

string Treasure::get_type(){
   return "Treasure";
}

void Treasure::pick_treaure(playercharacter * player){
   int amount = get_value();
   player->add_gold(amount);
};



























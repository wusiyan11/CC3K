#include <iostream>
#include "enemy.h"
#include "playercharacter.h"
#include "../game.h"
#include <sstream>
using namespace std;

Enemy::Enemy(int HP, int atk, int def, int x, int y, bool alive, Game * grid,string monster) :
   HP(HP), atk(atk), def(def), x(x), y(y), alive(alive), grid(grid), monster(monster) {}

int Enemy::get_x(){
   return x;
}
int Enemy::get_y(){
   return y;
}

int Enemy::get_atk(){
   return atk;
}

int Enemy::get_def(){
   return def;
}

Game * Enemy::get_grid(){
   return grid;
} 
   
bool Enemy::check_alive(){
   return alive;
}

void Enemy::set_HP(int hp){
   HP = hp;
}

void Enemy::set_Coordinates(int x1, int y1){
   x = x1;
   y = y1;
}
 
void Enemy::set_Grid(Game * g) {
   this->grid = g; 
}

string Enemy::get_monster(){
   return monster;
}

string Enemy::attack_player(playercharacter * player){
   string print_message;
   string monster = get_monster();
   int total_defence = player->get_def() + player->get_extra_def(); 
   int damage = get_atk() * (100 - total_defence)/100;
   player->set_HP (player->get_HP() - damage);
   
   string dmg;
   ostringstream temp;
   temp << damage;
   dmg = temp.str();
   print_message = "The "+ get_monster() + "strikes you for " + dmg +" damage!";
   return print_message;
}

int Enemy::get_HP(){
   return HP;
}















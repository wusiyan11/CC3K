#include <string>
#include "playercharacter.h"
//#include "../textdisplay.h"
#include <sstream>
//#include "enemy.h"
#include "../game.h"
#include "gameobject.h"
using namespace std;

playercharacter::playercharacter(Game * grid, int HP, int atk, int def, int gold,int x,int y,int HPMAX, bool Alive, string hero_name):
  grid(grid), HP(HP), HPMAX(HPMAX), atk(atk), def(def), gold(gold), x(x), y(y), Alive(Alive), hero(hero_name) {}

void playercharacter::recover_health(){
    HP += 5;
}

bool playercharacter::move(string direction){
     int new_X;
     int new_Y;
     Factory factory;
     bool move = false;
     string check_type;

     //Directions
     if (direction == "no") {
        new_X = x - 1;
        new_Y = y;
     } else if (direction == "so") {
        new_X = x + 1;
        new_Y = y;
     } else if (direction == "we") {
        new_X = x;     
        new_Y = y - 1;
     } else if (direction == "ea") {
        new_X = x;
        new_Y = y + 1;
     } else if (direction == "ne") {
        new_X = x - 1;
        new_Y = y + 1;
     } else if (direction == "nw") {
        new_X = x - 1;
        new_Y = y - 1;
     } else if (direction == "se") {
        new_X = x + 1;
        new_y = y + 1;
     } else if (direction == "sw") {
        new_X = x + 1;
        new_y = y + 1 ;
     } else {
       //End of coordinates setting 
     };

     //Check what stuff is on the destination Blank
     if (grid->get_object([new_X],[new_Y])){
        check_type = grid->get_object([new_X],[new_Y])->get_type();   
        
        //Check what type the destination Blank is 
        if (check_type == "Blank"){
           move = true;
        } 
        else if (check_type == "Door"){
           move = true;
        } 
        else if (check_type == "Passage"){
           move = true;
        } 
        else if (check_type == "Staircase"){
           grid->floorlevel++;
           remove_extra_atk();
           remove_extra_def();
           previous_position = "Blank";
           return true;
        } 
        
        
        else {
           return false;
        }   
        vim 
        //Set previous_type and everything else to complete the move
        if (!move){
            return false;   //Return false, bad move
        }
        else{
           GameObject * player = grid->get_object(x,y);
           grid->get_object(x,y) = factory.createFloorElem(PC);  //Need more knowledge
           grid->get_object(x,y).notify(*( grid->display ));       // Need more knowledge
      
         //Delete the stuff and set the new Blank
         delete grid->get_object(new_X, new_Y);
         grid->get_object(new_X, new_Y) = player;  //(prev is Player)
         grid->get_object(new_X, new_Y).notify(*( grid->display ));       // Need more knowledge
         x = new_X;
         y = new_Y;
         return true;
       }  //Move done.   //else
}



int playercharacter::get_HP(){
   return HP;
}

int playercharacter::get_gold(){
   return gold;
}

int playercharacter::get_CoodX(){
   return x;
}

int playercharacter::get_CoodY(){
   return y;
}

int playercharacter::get_HPMAX(){
   return HPMAX;
}

int playercharacter::get_atk(){
   return atk;
}

int playercharacter::get_def(){
   return def;
}

void playercharacter::set_Grid(Game * grid){
   this->grid = grid;
}

void playercharacter::set_HP(int hp){
   if (hp < 0) {
      HP = 0;
   } 
   else if (hp > HPMAX) {
      HP = HPMAX;
   } 
   else {
      HP = hp;
   }
}

void playercharacter::add_gold(int amount){
   gold =+ amount;
}

void playercharacter::add_hoardGold(){
   gold =+ 50;
}

void playercharacter:: add_atk(){
   extra_atk =+ 10;
}

void playercharacter::add_def(){
   extra_def =+ 10;
}

void playercharacter::reduce_atk(){
   extra_atk =- 5;
}

void playercharacter::reduce_def(){
   extra_def =- 5;
}

void playercharacter::remove_extra_atk(){
   extra_atk = 0;
}

void playercharacter::remove_extra_def(){
   extra_def = 0;
}

void playercharacter::set_Coord(int x, int y){
   this->x = x;
   this->y = y;
}

void playercharacter::full_def(){
   int current_defence = this->get_def();
   int boost = 100 - current_defence;
   this->extra_def = boost;
}

void playercharacter::set_extra_atk(int value){
   extra_atk = value;
}

void playercharacter::set_extra_def(int value){
   extra_def = value;
}

int playercharacter::get_extra_atk(){
   return extra_atk;
}

int playercharacter::get_extra_def(){
   return extra_def;
}

Game * playercharacter::get_Grid(){
   return grid;
}
 
string playercharacter::get_hero(){
   return hero;
}


bool playercharacter::check_alive(){
   return Alive;
}

string playercharacter::attack(string direction){
     int new_X;
     int new_Y;
     bool move = false;
     string check_type;

     //Directions
     if (direction == "no") {
        new_X = x - 1;
        new_Y = y;
     } else if (direction == "so") {
        new_X = x + 1;
        new_Y = y;
     } else if (direction == "we") {
        new_X = x;     
        new_Y = y - 1;
     } else if (direction == "ea") {
        new_X = x;
        new_Y = y + 1;
     } else if (direction == "ne") {
        new_X = x - 1;
        new_Y = y + 1;
     } else if (direction == "nw") {
        new_X = x - 1;
        new_Y = y - 1;
     } else if (direction == "se") {
        new_X = x + 1;
        new_Y = y + 1;
     } else if (direction == "sw") {
        new_X = x + 1;
        new_Y = y + 1 ;
     } else {
       //End of coordinates setting 
     };


    if (1){
         check_type = grid->get_type(new_X, new_Y);
         if (check_type != "Enemy") {
             return "Invalid attack!";
         }
         else {
             GameObject * enemy= grid->get_object(new_X,new_Y);
             //attack
             int attack = enemy->get_atk();
             int defence = def;
             int hp = enemy->get_HP();
             
             int damage = attack * (100 - defence) / 100;
             hp = hp - damage;    
             string print_message;
             string dmg;
             ostringstream temp;
             temp << damage;
             dmg = temp.str();
             print_message = "You attack the Orc with your Sword of Segfault for " + dmg + " damage!";
             enemy->set_HP(hp);
             return print_message;

         }
      }
}

string playercharacter::get_type(){
    return "Playercharacter";
}

void playercharacter::set_gold(int amount){
  gold = amount;
}











  












#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__
#include "gameobject.h"
#include <string>
using namespace std;

class Textdisplay;
class Game;

class playercharacter : public GameObject {
   protected:
     Game * grid;  
     int gold;
     int x;
     int y;
     int HP;
     int HPMAX;
     int atk;
     int def;
     int extra_atk;
     int extra_def;
     string hero;  //The hero the player chooses.  
     bool Alive;
   
   public:
      string previous_type;     //The type of the previous cell
      //playercharacter(/*Grid * grid,*/ int HP, int atk, int def, int gold, int x, 
      playercharacter(Game* grid, int HP, int atk, int def, int gold,int x,int y,int HPMAX, bool Alive, string hero_name);
      bool move(string direction);    //Act move!
      bool check_alive();
      
      int get_HP();
      int get_gold();
      int get_CoodX();
      int get_CoodY();
      int get_HPMAX();
      int get_atk();
      int get_def();
      int get_extra_atk();
      int get_extra_def();
      string attack(string direction);
      void set_Grid(Game * g);
      void add_atk();
      void add_def();
      void reduce_atk();
      void reduce_def();
      void set_HP(int hp);
      void remove_extra_atk();
      void remove_extra_def();
      
      void recover_health();
      void set_Coord(int x, int y);
      void add_gold(int amount);
      void full_def();
      void set_extra_atk(int value);
      void set_extra_def(int value);
      void set_gold(int amount);

      Game * get_Grid();
      string get_hero();
      string get_type();
      //virtual void usePotion(Potion *po1) = 0;
      //virtual void use_bad_Potion(Potion *po2) = 0;
      virtual ~playercharacter(){};
      void add_hoardGold();
};



#endif
      

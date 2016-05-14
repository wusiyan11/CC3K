#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <string>
#include "gameobject.h"
using namespace std;

class GameObject;
class playercharacter;
class Game;

class Enemy : public GameObject {
  protected:
   int HP;
   int atk;
   int def;
   int x;
   int y;
   bool alive;
   Game * grid;
   string monster;
  public:
   Enemy(int HP, int atk, int def, int x, int y, bool alive, Game* grid,string monster);
   int get_HP();
   int get_x();
   int get_y();
   int get_atk();
   int get_def();
   Game * get_grid(); 
   
   bool check_alive();
   void set_HP(int hp);
   void set_Coordinates(int x1, int y1); 
   void set_Grid(Game * g);
   
   string get_monster();
   string attack_player(playercharacter * player);

   //virtual ~Enemy() {};
};
   
      








#endif





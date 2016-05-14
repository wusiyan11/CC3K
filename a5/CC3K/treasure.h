#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"
#include "playercharacter.h"
using namespace std;

class Treasure : public Item {
     int value;
  protected:
     string kind;
  public:
     Treasure(int value, string kind);
     int get_value();
     string get_kind();
     string get_type();

     void pick_treaure(playercharacter * player);
     //virtual ~Treasure() {};
};

#endif






























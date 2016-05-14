#ifndef __FLOORELEM_H__
#define __FLOORELEM_H__
#include <string>
#include "gameobject.h"
using namespace std;


class floorElem : public GameObject {
  protected:
    string floor_type;
  public: 
    floorElem(string type);
    string get_type();
    //string get_name;  //Do not know why we need this
    //~flootElem() {};
};

#endif

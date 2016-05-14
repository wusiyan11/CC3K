#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <string>


using namespace std;

class playercharacter;
class floorElem;
class Item;
class Enemy;
class Factory
{
public:
	floorElem* createFloorElem(string type);
	playercharacter* createPlayerCharacter(string type);
	Item* createItem(std::string type);
    Enemy* createEnemy(std::string type);
};
#endif






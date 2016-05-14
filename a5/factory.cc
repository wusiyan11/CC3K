#include "factory.h"

#include "./CC3K/gameobject.h"
#include "./CC3K/knight.h"
#include "./CC3K/orc.h"
#include "./CC3K/goblin.h"
#include "./CC3K/merchant.h"
#include "./CC3K/dragon.h"
#include "./CC3K/grid_bug.h"
#include "./CC3K/wizard.h"
#include "./CC3K/samurai.h"

#include "./CC3K/wall1.h"
#include "./CC3K/wall2.h"
#include "./CC3K/stairway.h"
#include "./CC3K/passage.h"
#include "./CC3K/door.h"
#include "./CC3K/blank.h"

#include "./CC3K/potion_BA.h"
#include "./CC3K/potion_BD.h"
#include "./CC3K/potion_PH.h"
#include "./CC3K/potion_RH.h"
#include "./CC3K/potion_WA.h"
#include "./CC3K/potion_WD.h"
#include "./CC3K/goldPile.h"
#include "./CC3K/item.h"
#include "./CC3K/dragonHoard.h"

using namespace std;

floorElem *Factory::createFloorElem(std::string type) {
    floorElem* f = NULL;
    if (type == "Vwall") {
        f = new Wall2;
    }
    else if (type == "Hwall") {
        f = new Wall1;
    }
    else if (type == "Door") {
        f = new Door;
    }
    else if (type == "Passage") {
        f = new Passage;
    }
    else if (type == "Stairway") {
        f = new Stairway;
    }
    else if (type == "Blank") {
        f = new Blank;
    }
    else {}
    return f;
}

playercharacter* Factory::createPlayerCharacter(std::string type) {
    playercharacter* c = NULL;
    if (type == "Knight") {
        c = new Knight;
    }
    else if (type == "Wizard") {
        c = new Wizard;
    }
    else if (type == "Samurai") {
        c = new Samurai;
    }
    else {}
    return c;
}

Item* Factory::createItem(std::string type) {
    Item* i = NULL;
    if (type == "RH") {
        i = new RH;
    }
    else if (type == "BA") {
        i = new BA;
    }
    else if (type == "BD") {
        i = new BD;
    }
    else if (type == "PH") {
        i = new PH;
    }
    else if (type == "WA") {
        i = new WA;
    }
    else if (type == "WD") {
        i = new WD;
    }
    else if (type == "goldPile") {
        i = new GoldPile;
    }
    else if (type == "Dragon_Hoard") {
        i = new Dragon_Hoard;
    }
    else {}
    return i;
}

Enemy* Factory::createEnemy(std::string type) {
    Enemy* e = NULL;
    if (type == "Orc") {
        e = new Orc;
    }
    else if (type == "Grid_Bug") {
        e = new Grid_Bug;
    }
    else if (type == "Goblin") {
        e = new Goblin;
    }
    else if (type == "Merchant") {
        e = new Merchant;
    }
    else if (type == "Dragon") {
        e = new Dragon;
    }
    else {}
    return e;
}

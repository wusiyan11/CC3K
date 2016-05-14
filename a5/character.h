#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"

class Character : public GameObject {
    int _health;

    ...

    public:
        Character(...);

        int health() const;
        int attack() const;
        int defence() const;

        virtual void tick();    // override from GameObject

        virtual void move();
        virtual void attack();

        ...
};

#endif

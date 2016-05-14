#ifndef __CELL_H__
#define __CELL_H__
#include <string>
using namespace std;

// forward declaration because mutual reference
class GameObject;
class Factory;
class TextDisplay;

static const int MAX_NEIGHBOURS = 8;

class Cell {
    static TextDisplay* Display;

    int _x, _y;
    char _display;
    string _type;

    GameObject* _contents;
    Cell* _neighbor[MAX_NEIGHBOURS];
    Factory* _factory;
    int _neighbor_number;

    public:
        Cell();
        ~Cell();

        void update_object();
        string get_type();
        GameObject* get_object();

        void set_info(int x,int y,char display, string value);
        int x() const;
        int y() const;
        char display() const;
        void setcell(char x);
        void setneighbor(Cell* neighbor);
        void notify(GameObject* content);
        void set_gameobject(GameObject * g);
        //void set_gameobject(GameObject * g);

};

#endif

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
using namespace std;

// forward declaration because mutual reference
class Cell;

// add public/private/protected members as necessary
class GameObject {
    Cell * cell_pointer;
    int CX;
    int CY; 
    
    public:
        GameObject();
        //GameObject(int x,int y,Cell* p);

        int get_x() const;  // getters
        int get_y() const;  //getters

        void set_x(int value);  // setters
        void set_y(int value);  //setters
        void set_cell_pointer(Cell * p);

        virtual int get_HP() {return -1;};
        virtual int get_atk() {return -1;};
        virtual void set_HP(int hp) {};
 
        //virtual void tick() = 0;   // Called after every turn
        virtual ~GameObject() {};
};






#endif
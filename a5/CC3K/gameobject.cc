#include "gameobject.h"
#include "../cell.h"
using namespace std;
GameObject::GameObject() : CX(0),CY(0),cell_pointer(NULL){}

//GameObject::GameObject(int x, int y, Cell * p): CX(x), CY(y), cell_pointer(p) {}

int GameObject::get_x() const{
   return CX;
}

int GameObject::get_y() const{
   return CY;
}
   
void GameObject::set_x(int value){
   CX = value;
}

void GameObject::set_y(int value){
   CY = value;
}

void GameObject::set_cell_pointer(Cell * p){
   cell_pointer = p;
} 






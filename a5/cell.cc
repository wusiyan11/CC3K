#include <string>
#include "./CC3K/gameobject.h"
// #include "factory.h"
#include "./CC3K/item.h"
#include "./CC3K/playercharacter.h"
#include "./CC3K/floorelem.h"
#include "./CC3K/enemy.h"
#include "textdisplay.h"
#include "cell.h"


using namespace std;

Cell::Cell() : _neighbor(), _contents(NULL) {
	_x,_y=_neighbor_number=0;
}

Cell::~Cell() {
	if (_contents != NULL) {
		delete _contents;
	}
}

GameObject* Cell::get_object() {
	return _contents;
}

string Cell::get_type() {
	return _type;
}

void Cell::update_object() {
	/*if (_contents != NULL) {
		delete _contents;
		_contents = NULL;
	}
	if (_display == '!' || _display == '$') {
		//floorElem *gr;
		//_contents = gr;
		this->_contents = _factory->createItem(_type);
	} 
	else if (_display == '-' || _display == '|' || _display == '+' || 
		_display == '#' || _display == '.' || _display == '>') {
		this->_contents = _factory->createFloorElem(_type);
	}
	else if (_display == 'O' || _display == 'X' || _display == 'g' || 
		_display == 'M' || _display == 'D') {
		this->_contents = _factory->createEnemy(_type);
	} 
	else if (_display == '@') {

		this->_contents =_factory->createPlayerCharacter(_type);
	} else {}*/
}


void Cell::set_gameobject(GameObject * g){
	this->_contents = g;
}




void Cell::set_info(int x,int y,char display,string value) {
	_x=x;
	_y=y;
	_display=display;
	_type=value;
	//_contents= new GameObject;
}

void Cell::setneighbor(Cell* neighbor) {
	_neighbor[_neighbor_number] = neighbor;
}

int Cell::x() const {
	return _x;
}

int Cell::y() const {
	return _y;
}

char Cell::display() const {
	return _display;
}



void Cell::notify(GameObject* content) {
	_contents = content;
}

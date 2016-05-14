#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <string>
using namespace std;

class Cell;

class Chamber {
	Cell **** rooms;
	int _x;
	int _y;
public:
	void insert_elem(int lvl,int room_number,char ele,string what);
	Chamber();
	~Chamber();
	void setrooms(Cell* here);

};
#endif
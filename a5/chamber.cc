#include "chamber.h"
#include "PRNG.h"
#include "game.h"
#include "cell.h"

using namespace std;

extern uint32_t seed;

Chamber::Chamber() {
	_x=_y=0;
	rooms = new Cell*** [5];
	for (int lvl=0;lvl<5;lvl++) {
		rooms[lvl] = new Cell** [5];
		for (int x=0;x<5;x++) {
			if (x == 0) {
				rooms[lvl][x] = new Cell* [104];
			} else if (x == 1) {
				rooms[lvl][x] = new Cell* [201];
			} else if (x == 2) {
				rooms[lvl][x] = new Cell* [36];
			} else if (x == 3) {
				rooms[lvl][x] = new Cell* [147];
			} else {
				rooms[lvl][x] = new Cell* [150];
			}
		}
	}
}

void Chamber::setrooms(Cell* here) {
	for (int lvl =0;lvl<5;lvl++) {
		for (int x=0;x<5;x++) {
			if (_x == 0 && _y == 104) {
				for (int i=0; i<104;i++) {
					rooms[lvl][0][i] = here;
				}
				_x += 1;
			}

			if (_x == 1 && _y == 201) {
				for (int i=0; i<201;i++) {
					rooms[lvl][0][i] = here;
				}
				_x += 1;
			}
			if (_x == 2 && _y == 36) {
				for (int i=0; i<36;i++) {
					rooms[lvl][0][i] = here;
				}
				_x += 1;
			}
			if (_x == 3 && _y == 147) {
				for (int i=0; i<147;i++) {
					rooms[lvl][0][i] = here;
				}
				_x ++;
			}
			if (_x == 4 && _y == 150) {
				for (int i=0; i<150;i++) {
					rooms[lvl][0][i] = here;
				}
				_x ++;
			}
		}
	}
}

void Chamber::insert_elem(int lvl,int room_number,char ele,string what) {
	int ranum;
	PRNG prng(seed);
	if (room_number == 0) {
		ranum = prng(103);
	}
	if (room_number == 1) {
		ranum = prng(201);
	}
	if (room_number == 2) {
		ranum = prng(36);
	}
	if (room_number == 3) {
		ranum = prng(147);
	}
	if (room_number == 4) {
		ranum = prng(150);
	}
	while (rooms[lvl][room_number][ranum]->display() != '.') {
		if (room_number == 0) {
			ranum = prng(103);
		}
		if (room_number == 1) {
			ranum = prng(201);
		}
		if (room_number == 2) {
			ranum = prng(36);
		}
		if (room_number == 3) {
			ranum = prng(147);
		}
		if (room_number == 4) {
			ranum = prng(150);
		}
	}
	int x = rooms[lvl][room_number][ranum]->x();
	int y = rooms[lvl][room_number][ranum]->y();
	rooms[lvl][room_number][ranum]->set_info(x,y,ele,what);
}

Chamber::~Chamber() {

	for (int lvl=0;lvl<5;lvl++) {
		for (int i=0;i<5;i++) {
			delete [] rooms[lvl][i];
		}
		delete [] rooms[lvl];
	}
	delete [] rooms;
}
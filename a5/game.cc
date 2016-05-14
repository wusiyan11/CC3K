#include "game.h"
#include "textdisplay.h"
#include <string>
#include <fstream>
#include <limits>
#include "cell.h"
// #include "chamber.h"
#include "factory.h"
#include "PRNG.h"
#include "./CC3K/dragonHoard.h"
#include "./CC3K/goldPile.h"

using namespace std;

extern uint32_t seed;

int player_spawned_room;

string player_type;

PRNG prng(seed);

Game::Game(string filename, char chosen_player) : floorlevel(0), grid(NULL), /*rooms(NULL),*/stair_count(),potion_count(),gold_count(),enemy_count() {
	initialized_player = chosen_player;
	player_count =0;
	// set display
	display = new TextDisplay;
	// set grid
	grid = new Cell** [5];
	// set rooms
	// rooms = new Chamber; //needs modify
	// locate dynamically
	for (int i=0; i<5; i++) {
		grid[i] = new Cell* [25];
		for (int high=0; high<25; high++) {
			grid[i][high] = new Cell[79];
		}
	}

	/*for (int i=0;i < 5;i ++) {
		for (int high=0;high < 25; high ++) {
			for (int wide=0;wide < 79; wide++) {
				infile >> noskipws >> temp;
				if (temp == 'X' || temp == 'g' || temp == 'M' || temp == 'O' || temp == 'D') {
					enemy_count += 1;
				}
				if (temp=='0' || temp=='1' || temp=='2' || temp=='3' || temp=='4' || temp=='5') {
					potion_count[i] ++;
					temp = '!';
				}
				if (temp=='6' || temp=='7') {
					gold_count[i] ++;
					temp = '$';
				}
				theDisplay[i][high][wide] = temp;
				if (wide == 78) {
					infile.ignore( numeric_limits<int>::max(),'\n');
				}
			}
		}
	}*/


	const char *cfilename = filename.c_str();
	ifstream infile(cfilename);

	// insert info for grid
	for (int i=0; i<5; i++) {
		char temp;
		for (int high=0; high< 25 ; high++) {
			for (int wide=0; wide<79 ; wide++) {
				infile >> noskipws >> temp;
				if (temp == '0') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"RH");
					potion_count[i] ++;
				} if (temp == '1') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"BA");
					potion_count[i] ++;
				} if (temp == '2') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"BD");
					potion_count[i] ++;
				} if (temp == '3') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"PH");
					potion_count[i] ++;
				} if (temp == '4') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"WA");
					potion_count[i] ++;
				} if (temp == '5') {
					temp = '!';
					grid[i][high][wide].set_info(high,wide,temp,"WD");
					potion_count[i] ++;
				} if (temp == '6') {
					temp = '$';
					grid[i][high][wide].set_info(high,wide,temp,"goldPile");
					gold_count[i] ++;
				} if (temp == '7') {
					temp = '$';
					grid[i][high][wide].set_info(high,wide,temp,"Dragon_Hoard");
					gold_count[i] ++;
				} if (temp == '-') {
					grid[i][high][wide].set_info(high,wide,temp,"Hwall");
				} if (temp == '|') {
					grid[i][high][wide].set_info(high,wide,temp,"Vwall");
				} if (temp == '+') {
					grid[i][high][wide].set_info(high,wide,temp,"Door");
				} if (temp == '#') {
					grid[i][high][wide].set_info(high,wide,temp,"Passage");
				} if (temp == '.') {
					grid[i][high][wide].set_info(high,wide,temp,"Blank");
				} if (temp == '>') {
					grid[i][high][wide].set_info(high,wide,temp,"Stairway");
					stair_count[i] = 1;
				} if (temp == 'O') {
					grid[i][high][wide].set_info(high,wide,temp,"Orc");
				} if (temp == 'X') {
					grid[i][high][wide].set_info(high,wide,temp,"Grid_Bug");
					enemy_count[i] ++;
				} if (temp == 'g') {
					grid[i][high][wide].set_info(high,wide,temp,"Goblin");
					enemy_count[i] ++;
				} if (temp == 'M') {
					grid[i][high][wide].set_info(high,wide,temp,"Merchant");
					enemy_count[i] ++;
				} if (temp == 'D') {
					grid[i][high][wide].set_info(high,wide,temp,"Dragon");
					enemy_count[i] ++;
				} if (temp == ' ') {
					grid[i][high][wide].set_info(high,wide,temp, " ");
				} if (temp == '@') {
					string value;
					if (initialized_player == 'k') {
						value = "Knight";
					}
					if (initialized_player == 'w') {
						value = "Wizard";
					}
					if (initialized_player == 's') {
						value = "Samurai";
					}
					player_x=high;
					player_y=wide;
					player_count +=1;
					grid[i][high][wide].set_info(high,wide,temp, value);
				} if (wide==78) {
					infile.ignore(numeric_limits<int>::max(),'\n');
				}
				grid[i][high][wide].update_object();
/*
				//set room 1
				for (int i=3;i<6;i++) {
					for (int j=3;j<29;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}

				// set room 2
				for (int i=3;i<7;i++) {
					for (int j=39;j<62;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}
				for (int i=7;i<13;i++) {
					for (int j=61;j<76;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}
				for (int i=5;i<=6;i++) {
					for (int j=62;j<=69;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}
				for (int i=70;i<=72;i++) {
					rooms->setrooms(& grid[i][high][wide]);
				}

				// set room 3
				for (int i=10;i<=12;i++) {
					for (int j=38;j<=49;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}

				// set room 4
				for(int i=15;i<=21;i++) {
					for (int j=4;j<=24;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}

				// set room 5
				for (int i=16;i<=21;i++) {
					for(int j=65;j<=75;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}
				for (int i=19;i<=21;i++) {
					for (int j=37;j<=64;j++) {
						rooms->setrooms(& grid[i][high][wide]);
					}
				}*/
			}
		}
	}
	if (player_count == 0) {
		this->spawnPlayer();
	}
	if (stair_count == 0) {
		this->spawnStair();
	}

	this->spawnObjects();

	for (int lv=0; lv<5; lv++) {
		for (int high=0; high<25; high++) {
			for (int wide=0; wide<79; wide++) {
				display->setdisplay(lv,high,wide,grid[lv][high][wide].display());
			}
		}
	}
}



GameObject* Game::get_object(int x,int y) {
	return grid[floorlevel][x][y].get_object();
}

string Game::get_type(int x, int y) {
	return grid[floorlevel][x][y].get_type();
}

void Game::spawnPlayer() {
	for (int lvl=0;lvl<5;lvl++) {
		int ranum = prng(4);
		// rooms->insert_elem(lvl,ranum,'@',player_type);
		player_spawned_room = ranum;
	}
}

void Game::spawnStair() {
	for (int lvl=0;lvl<5;lvl++) {
		int ranum = prng(4);
		for (; ranum == player_spawned_room; ranum = prng(4)) {
		}
		// rooms->insert_elem(lvl,ranum,'>',"Stairway");
		stair_count[lvl] = 1;
	}
}

void Game::spawnObjects() {
	for (int lvl=0;lvl<5;lvl++) {
		int count=10-potion_count[lvl];
		for (int times=0;times<2;times++) {
			for (int room_number=0;room_number<5;room_number++) {
				int ranum = prng(5);
				string type;
				if (ranum==0) {
					type="RH";
				} else if (ranum==1) {
					type="BA";
				} else if (ranum==2) {
					type="BD";
				} else if (ranum==3) {
					type="PH";
				} else if (ranum==1) {
					type="WA";
				} else if (ranum==1) {
					type="WD";
				} else {}
				// rooms->insert_elem(lvl,room_number,'!',type);
				count--;
			}
		}
		count=10-gold_count[lvl];
		for (int times=0;times<2;times++) {
			for (int room_number=0;room_number<5;room_number++) {
				int ranum = prng(7);
				string type;
				if (ranum==7) {
					type = "Dragon_Hoard";
				} else {
					type = "goldPile";
				}
				// rooms->insert_elem(lvl,room_number,'$',type);
				count --;
			}
		}
		count=20-enemy_count[lvl];
		for (int times=0;times<4;times++) {
			for(int room_number=0;room_number<5;room_number++) {
				int ranum = prng(5);
				string type;
				char kind;
				if (ranum==5) {
					type="Orc";
					kind='O';
				} else if (ranum==4) {
					type="Merchant";
					kind='M';
				} else if (ranum==3 || ranum==2) {
					type="Goblin";
					kind='g';
				} else {
					type="Grid_Bug";
					kind='X';
				}
				// rooms->insert_elem(lvl,room_number,kind,type);
			}
		}
	}
}


void Game::levelup() {
	floorlevel += 1;
	display->levelup();
}

void Game::updatedisplay() {
	for (int high=0; high<25; high ++) {
		for (int wide=0;wide<79; wide ++) {
			char show = grid[floorlevel][high][wide].display();
			display->notify(high,wide,show);
		}
	}
}

void Game::print() {
	display->print_current_level();
}

Game::~Game() {
	delete display;
	// delete rooms;
	for (int i=0; i<5; i++) {
		for (int high=0; high<25;high++) {
			delete [] grid[i][high];
		}
		delete [] grid[i];
	}
	delete grid;
}
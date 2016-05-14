#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <string>

class Cell;

class TextDisplay;

class Chamber;

class GameObject;

using namespace std;

class Game {

	int player_count;
	int stair_count[5],potion_count[5],gold_count[5],enemy_count[5];
	Cell*** grid;
	int floorlevel;
	TextDisplay* display;
	// Chamber* rooms;
	char initialized_player;
public:
	int player_x,player_y;
	Game(string filename, char chosen_player);
	~Game();

	void levelup();

	GameObject* get_object(int x, int y);
	string get_type(int x, int y);

	void spawnPlayer();
	void spawnStair();
	void spawnObjects();

	void setItem();
	void change();

	void updatedisplay();
	void print();
};

#endif

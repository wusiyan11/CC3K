#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <string>

using namespace std;

class TextDisplay {
	char ***theDisplay;
	int floorlevel;
public:
	TextDisplay();
	~TextDisplay();

	void setdisplay(int lv, int x, int y, char ch);
	int getlevel();
	void levelup();
	void notify(int x, int y, char ch);
	void print_current_level();
	char getchar(int x , int y );
};

#endif
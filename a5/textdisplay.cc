#include "textdisplay.h"
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;

TextDisplay::TextDisplay() : floorlevel(0) {
	theDisplay = new char** [5];

	for (int lvl=0;lvl<5;lvl++) {
		theDisplay[lvl] = new char* [25];
	}
	for (int i=0;i<5;i++) {
		for (int high=0;high<25;high++) {
			theDisplay[i][high] = new char[79];
		}
	}

	/*const char *cfilename = filename.c_str();
	ifstream infile(cfilename);
	char temp;
	for (int i=0;i < 5;i ++) {
		for (int high=0;high < 25; high ++) {
			for (int wide=0;wide < 79; wide++) {
				infile >> noskipws >> temp;
				theDisplay[i][high][wide] = temp;
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
}

TextDisplay::~TextDisplay() {
	for (int i=0;i < 5;i++) {
		for (int x=0;x < 25;x ++) {
			delete [] theDisplay[i][x];
		}
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
	theDisplay = NULL;
}

int TextDisplay::getlevel() {
	return floorlevel;
}

void TextDisplay::levelup(){
	floorlevel +=1;
}

void TextDisplay::setdisplay(int lv,int x, int y, char ch) {
	theDisplay[lv][x][y] = ch;
}

void TextDisplay::notify(int x, int y, char ch) {
	theDisplay[floorlevel][x][y] = ch;
}

char TextDisplay::getchar(int x , int y) {
	return theDisplay[floorlevel][x][y];
}

void TextDisplay::print_current_level() {
	/*for (int i=0;i<9;i++) {
		for(int x=0;x<10;x++) {
			cout << x;
		}
	}*/
	for (int high=0;high<25;high++) {
		for (int wide=0;wide < 79; wide++) {
			cout << theDisplay[floorlevel][high][wide];
		}
		cout << endl;
	}
}
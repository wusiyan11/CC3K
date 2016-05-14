#include <iostream>
#include <fstream>
using namespace std;

int main () {
	ifstream infile("sample-cc3k-map.txt");
	char cube[5][25][79];
	for (int i=0;i < 5;i ++) {
		for (int high=0;high < 25; high ++) {
			for (int wide=0;wide < 79; wide++) {
				infile >> noskipws >> cube [i][high][wide];
				if (wide == 78) {
					infile.ignore( numeric_limits<int>::max(),'\n');
				}
			}
		}
	}
	for (int i=0;i<5;i++) {
		int x = 0;
		for (int high=0;high<25;high++) {
			for (int wide=0;wide < 79; wide++) {
				if (cube [i][high][wide] == '.') {
					x += 1;
				}
				cout << cube[i][high][wide];
			}
			cout << endl;
		}
		cout << "number of . = " << x << endl;
	}
}
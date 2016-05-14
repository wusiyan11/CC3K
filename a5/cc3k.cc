/*
#if _WIN32
// This is Windows-Only
inline int getpid() {
        return 42;
}
#else
*/
#include "textdisplay.h"
#include "game.h"
#include <sstream>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include "PRNG.h"


using namespace std;

uint32_t seed = getpid();

void consideration(char * Option,uint32_t &Seed,string &Filename) {
	int num;
	string filename;

	stringstream ss(Option);
	ss >> num;
	if (!ss.fail()) {
		Seed = num;
	}
	ss.str (Option);
	Filename = ss.str();
}

int main(int argc, char * argv[]) {
	string filename = "sample-cc3k-map.txt";
	switch (argc) {
		case 3: {
			consideration(argv[2],seed,filename);
		}
		case 2: {
			consideration(argv[1],seed,filename);
		}
		default: {
			break;
		}
	}

	Game g(filename,'k');
	g.print();

	return 0;
}
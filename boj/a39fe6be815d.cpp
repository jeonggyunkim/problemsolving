#include "solution.h"
#include <random>
#include <time.h>
using namespace std;

void init() {
	srand(time(0));
};

bool p;

bool pick(int value) {
	if (p) return p = 0;
	if (value < 0) return 0;
	else if (value == 100) {
		if (random() % 2 == 0) return p = 1;
		else return 0;
	}
	else if (value == 200) {
		if (random() % 5 != 0) return p = 1;
		else return 0;
	}
	else if (value == 300) {
		if (random() % 10 != 0) return p = 1;
		else return 0;
	}
	else return p = 1;
}
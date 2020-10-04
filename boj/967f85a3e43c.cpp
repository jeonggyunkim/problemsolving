#include <iostream>
using namespace std;

int main() {

	for (int j = 0; j < 3; ++j) {
		int s = 0;
		int t;

		for (int i = 0; i < 4; ++i) {
			cin >> t;
			s += t;
		}

		if (s == 0) printf("D\n");
		else if (s == 1) printf("C\n");
		else if (s == 2) printf("B\n");
		else if (s == 3) printf("A\n");
		else printf("E\n");
	}

	return 0;
}
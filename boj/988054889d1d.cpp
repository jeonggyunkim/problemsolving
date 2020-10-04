#include <iostream>
using namespace std;

int main() {
	int chess[64] = {};
	char t;
	for (int i = 0; i < 64; ++i) {
		cin >> t;
		if (t == 'F') chess[i] = 1;
	}

	int sum = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) % 2 == 0) sum += chess[8 * i + j];
		}
	}

	cout << sum << endl;

	return 0;
}
#include <iostream>
using namespace std;

char a[6600][6600];

void star(int x, int y, int d) {
	int dd = d / 3;
	for (int i = 0; i < dd; ++i) {
		for (int j = 0; j < dd; ++j) {
			a[x + dd + i][y + dd + j] = ' ';
		}
	}
	if (d == 3) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			star(x + i * dd, y + j * dd, dd);
		}
	}
}

int main() {
	int d;
	cin >> d;

	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < d; ++j) {
			a[i][j] = '*';
		}
		a[i][d] = '\0';
	}
	star(0, 0, d);

	for (int i = 0; i < d; ++i) {
		cout << a[i] << '\n';
	}
}
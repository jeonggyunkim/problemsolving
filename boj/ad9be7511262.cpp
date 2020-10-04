#include <iostream>
using namespace std;

int four[4][4];

int main() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> four[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i < 100; ++i) {
		for (int j = 1; j < 100; ++j) {
			int in = 0;
			for (int k = 0; k < 4; ++k) {
				if (four[k][0] <= i && i < four[k][2] && four[k][1] <= j && j < four[k][3]) in = 1;
			}
			ans += in;
		}
	}
	cout << ans;
}
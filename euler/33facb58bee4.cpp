#include <iostream>
using namespace std;

int main() {
	freopen("in", "rt", stdin);

	int grid[20][20];
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			cin >> grid[i][j];
		}
	}

	long long ans = -1;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			long long prod = 1;
			for (int k = 0; k < 4; ++k) prod *= grid[i][j + k];
			ans = max(ans, prod);
		}
	}

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			long long prod = 1;
			for (int k = 0; k < 4; ++k) prod *= grid[j + k][i];
			ans = max(ans, prod);
		}
	}

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			long long prod = 1;
			for (int k = 0; k < 4; ++k) prod *= grid[i + k][j + k];
			ans = max(ans, prod);
		}
	}

	for (int i = 0; i < 16; ++i) {
		for (int j = 4; j < 20; ++j) {
			long long prod = 1;
			for (int k = 0; k < 4; ++k) prod *= grid[i + k][j - k];
			ans = max(ans, prod);
		}
	}
	cout << ans << endl;
}
#include <iostream>
using namespace std;

int num[9][9];

bool check() {
	for (int i = 0; i < 9; ++i) {
		int mask[2] = {};
		for (int j = 0; j < 9; ++j) {
			mask[0] |= (1 << num[i][j]);
			mask[1] |= (1 << num[j][i]);
		}
		if ((mask[0] & mask[1]) != ((1 << 9) - 1)) return 0;
	}

	for (int i = 0; i < 9; i += 3) for (int j = 0; j < 9; j += 3) {
		int mask = 0;
		for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) mask |= (1 << num[i + p][j + q]);
		if (mask != ((1 << 9) - 1)) return 0;
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		cout << "Case " << test << ": ";

		for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
			cin >> num[i][j];
			num[i][j]--;
		}

		if (check()) cout << "CORRECT\n";
		else cout << "INCORRECT\n";
	}
}
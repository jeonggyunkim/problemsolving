#include <iostream>
#include <string>
#define FULL ((1 << 9) - 1)
using namespace std;

int mask[9][9];
int t[9][9];

void add_elem(int i, int j, int n) {
	if ((mask[i][j] & (1 << n)) == 0) {
		cout << "ERROR";
		exit(0);
	}
	t[i][j] = n + 1;

	mask[i][j] = 0;
	for (int p = 0; p < 9; ++p) {
		mask[i][p] &= ~(1 << n);
		mask[p][j] &= ~(1 << n);
	}
	int x = i / 3 * 3, y = j / 3 * 3;
	for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) mask[x + p][y + q] &= ~(1 << n);
}

void single() {
	int change = 1;
	while (1) {
		for (int i = 0; i < 9; ++i) {
			int check = 0, in = 0;
			for (int j = 0; j < 9; ++j) {
				if (t[i][j]) in |= (1 << (t[i][j] - 1));
				else check |= mask[i][j];
			}
			if ((check ^ in) != FULL) {
				cout << "ERROR";
				exit(0);
			}
		}

		for (int i = 0; i < 9; ++i) {
			int check = 0, in = 0;
			for (int j = 0; j < 9; ++j) {
				if (t[j][i]) in |= (1 << (t[j][i] - 1));
				else check |= mask[j][i];
			}
			if ((check ^ in) != FULL) {
				cout << "ERROR";
				exit(0);
			}
		}

		for (int p = 0; p < 9; p += 3) for (int q = 0; q < 9; q += 3) {
			int check = 0, in = 0;
			for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
				if (t[i][j]) in |= (1 << (t[i][j] - 1));
				else check |= mask[i][j];
			}
			if ((check ^ in) != FULL) {
				cout << "ERROR";
				exit(0);
			}
		}

		if (!change) return;
		change = 0;
		for (int p = 0; p < 9; p += 3) for (int q = 0; q < 9; q += 3) {
			int check = FULL, x = 0;
			for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
				check &= ~(x & mask[p + i][q + j]);
				x |= mask[p + i][q + j];
			}
			while (check) {
				int k = __builtin_ctz(check);
				for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
					if (mask[p + i][q + j] & (1 << k)) {
						add_elem(p + i, q + j, k);
						change = 1;
						goto l1;
					}
				}
				l1:;
				check &= check - 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) mask[i][j] = FULL;

	string s;
	for (int i = 0; i < 9; ++i) {
		cin >> s;
		for (int j = 0; j < 9; ++j) {
			if (s[j] != '.') add_elem(i, j, s[j] - '1');
		}
	}

	single();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (t[i][j]) cout << t[i][j];
			else cout << '.';
		}
		cout << '\n';
	}
}
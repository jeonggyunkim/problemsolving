#include <iostream>
using namespace std;

int mask[9][9];
int t[9][9];

void copy(int a[9][9], int b[9][9]) {
	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) a[i][j] = b[i][j];
}

bool add_elem(int i, int j, int n) {
	t[i][j] = n + 1;
	if ((mask[i][j] & (1 << n)) == 0) return 0;

	mask[i][j] = 0;
	for (int p = 0; p < 9; ++p) {
		mask[i][p] &= ~(1 << n);
		mask[p][j] &= ~(1 << n);
	}
	int x = i / 3 * 3, y = j / 3 * 3;
	for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) mask[x + p][y + q] &= ~(1 << n);
	return 1;
}

void single() {
	int com = 0, last = 0;
	while (1) {
		if (com - last == 4) break;
		for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
			if (mask[i][j] && !(mask[i][j] & (mask[i][j] - 1))) {
				add_elem(i, j, __builtin_ctz(mask[i][j]));
				last = com + 1;
			}
		}
		com++;

		if (com - last == 4) break;
		for (int i = 0; i < 9; ++i) {
			int check[10] = {0};
			for (int j = 0; j < 9; ++j) for (int k = 0; k < 9; ++k) {
				check[k] += !!(mask[i][j] & (1 << k));
			}
			for (int k = 0; k < 9; ++k) if (check[k] == 1) {
				for (int j = 0; j < 9; ++j) if (mask[i][j] & (1 << k)) {
					add_elem(i, j, k);
					last = com + 1;
				}
			}
		}
		com++;

		if (com - last == 4) break;
		for (int j = 0; j < 9; ++j) {
			int check[10] = {0};
			for (int i = 0; i < 9; ++i) for (int k = 0; k < 9; ++k) {
				check[k] += !!(mask[i][j] & (1 << k));
			}
			for (int k = 0; k < 9; ++k) if (check[k] == 1) {
				for (int i = 0; i < 9; ++i) if (mask[i][j] & (1 << k)) {
					add_elem(i, j, k);
					last = com + 1;
				}
			}
		}
		com++;

		if (com - last == 4) break;
		for (int p = 0; p < 9; p += 3) for (int q = 0; q < 9; q += 3) {
			int check[10] = {0};
			for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 9; ++k) check[k] += !!(mask[p + i][q + j] & (1 << k));
			}
			for (int k = 0; k < 9; ++k) if (check[k] == 1) {
				for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
					if (mask[p + i][q + j] & (1 << k)) {
						add_elem(p + i, q + j, k);
						last = com + 1;
					}
				}
			}
		}
		com++;
	}
}

int check_status() {
	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
		if (mask[i][j] == 0 && t[i][j] == 0) return 0;
	}
	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
		if (t[i][j] == 0) return 1;
	}
	return 2;
}

int solve() {
	int mi = -1, mj;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) if (mask[i][j] != 0) {
			mi = i; mj = j;
			break;
		}
		if (mi != -1) break;
	}

	int tt[9][9];
	int mt[9][9];

	copy(tt, t);
	copy(mt, mask);

	int p = mask[mi][mj];
	while (1) {
		if (p == 0) break;
		int next = __builtin_ctz(p);
		p &= (p - 1);
		add_elem(mi, mj, next);
		single();
		int c = check_status();
		if (c == 0) {
			copy(t, tt);
			copy(mask, mt);
			continue;
		}
		else if (c == 1) {
			if (solve()) return 2;
			else {
				copy(t, tt);
				copy(mask, mt);
				continue;
			}
		}
		else return 2;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char in[9][10];
	for (int i = 0; i < 9; ++i) cin >> in[i];

	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) mask[i][j] = (1 << 9) - 1;
	for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
		if (in[i][j] != '0') add_elem(i, j, in[i][j] - '1');
	}
	single();

	int c = check_status();
	if (c == 2 || (c == 1 && solve())) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) cout << t[i][j];
			cout << '\n';
		}
	}
}
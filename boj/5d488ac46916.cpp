#include <iostream>
#include <memory.h>
using namespace std;

typedef unsigned long long ull;

int r, cc;

ull map[501][9];
ull ocean[501][9];
ull temp[501][9];
ull merge[501][9];

void cover() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			temp[i][j] &= ocean[i][j];
		}
	}
}

void west() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			temp[i][j] = map[i][j] << 1;
			temp[i][j] |= (map[i][j + 1] & (1LL << 63)) >> 63;
		}
	}
	cover();
}

void east() {
	for (int i = 0; i < r; ++i) {
		for (int j = cc - 1; j >= 0; --j) {
			temp[i][j] = map[i][j] >> 1;
			if (j) temp[i][j] |= (map[i][j - 1] & 1) << 63;
		}
	}
	cover();
}

void north() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			temp[i][j] = map[i + 1][j];
		}
	}
	cover();
}

void south() {
	for (int i = r - 1; i >= 0; --i) {
		for (int j = 0; j < cc; ++j) {
			if (i) temp[i][j] = map[i - 1][j];
			else temp[i][j] = 0;
		}
	}
	cover();
}

void all() {
	memset(merge, 0, sizeof(merge));
	west();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			merge[i][j] |= temp[i][j];
		}
	}
	east();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			merge[i][j] |= temp[i][j];
		}
	}
	north();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			merge[i][j] |= temp[i][j];
		}
	}
	south();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			merge[i][j] |= temp[i][j];
		}
	}
	memcpy(map, merge, sizeof(map));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, m;
	cin >> r >> c >> m;
	cc = (c + 63) / 64;

	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j) {
			if (s[j] == '.') {
				ocean[i][j / 64] |= (1LL << (63 - j % 64));
				map[i][j / 64] |= (1LL << (63 - j % 64));
			}
		}
	}

	string op;
	cin >> op;
	for (int i = 0; i < m; ++i) {
		if (op[i] == '?') {
			all();
		}
		else {
			if (op[i] == 'W') west();
			else if (op[i] == 'S') south();
			else if (op[i] == 'N') north();
			else if (op[i] == 'E') east();
			memcpy(map, temp, sizeof(map));
		}
	}

	int ans = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < cc; ++j) {
			ans += __builtin_popcountll(map[i][j]);
		}
	}
	cout << ans;
}
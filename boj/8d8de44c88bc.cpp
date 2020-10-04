#include <iostream>
#include <memory.h>
using namespace std;

int n, ans = -1;
int bv[5][5];
char bc[5][5];
int value[10][4][4][4];
char color[10][4][4][4];
int sp[4][2] = { { 0, 0 },{ 1, 0 },{ 0, 1 },{ 1, 1 } };

void rotate() {
	for (int k = 0; k < n; ++k)
	for (int rot = 1; rot < 4; ++rot)
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j) {
		color[k][rot][i][j] = color[k][rot - 1][3 - j][i];
		value[k][rot][i][j] = value[k][rot - 1][3 - j][i];
	}
}

void put(int num, int loc, int rot) {
	for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j) {
		int& p = bv[sp[loc][0] + i][sp[loc][1] + j];
		p += value[num][rot][i][j];
		if (p < 0) p = 0;
		if (p > 9) p = 9;

		if (color[num][rot][i][j] != 'W') {
			bc[sp[loc][0] + i][sp[loc][1] + j] = color[num][rot][i][j];
		}
	}
}

void score() {
	int r = 0, b = 0, g = 0, y = 0;
	for (int i = 0; i < 5; ++i)
	for (int j = 0; j < 5; ++j) {
		if (bc[i][j] == 'R') r += bv[i][j];
		else if (bc[i][j] == 'B') b += bv[i][j];
		else if (bc[i][j] == 'G') g += bv[i][j];
		else if (bc[i][j] == 'Y') y += bv[i][j];
	}
	ans = max(ans, 7 * r + 5 * b + 3 * g + 2 * y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) cin >> value[i][0][j][k];
		for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) cin >> color[i][0][j][k];
	}

	rotate();

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			if (a == b) continue;
			for (int c = 0; c < n; ++c) {
				if (a == c || b == c) continue;
				for (int loc1 = 0; loc1 < 4; ++loc1)
				for (int loc2 = 0; loc2 < 4; ++loc2)
				for (int loc3 = 0; loc3 < 4; ++loc3)
				for (int rot1 = 0; rot1 < 4; ++rot1)
				for (int rot2 = 0; rot2 < 4; ++rot2)
				for (int rot3 = 0; rot3 < 4; ++rot3) {
					memset(bv, 0, sizeof(bv));
					memset(bc, 0, sizeof(bc));
					put(a, loc1, rot1);
					put(b, loc2, rot2);
					put(c, loc3, rot3);
					score();
				}
			}
		}
	}

	cout << ans;
}
#include <iostream>
using namespace std;

int main() {
	for (int rep = 0; rep < (1 << 25); ++rep) {
		bool bingo[5][5] = {};
		bool line[5][5] = {};
		bool hor[5] = {};
		bool ver[5] = {};
		bool cross1 = 1, cross2 = 1;
		int cnt = 0;
		int cnt_line = 0;
		int cnt_numline = 0;
		int cnt_ver = 0;
		int cnt_c = 0;

		for (int i = 0; i < 25; ++i) {
			if (rep & (1 << i)) {
				bingo[i / 5][i % 5] = 1;
				cnt++;
			}
		}

		for (int i = 0; i < 5; ++i) {
			bool b = 1;
			for (int j = 0; j < 5; ++j) {
				if (!bingo[i][j]) {
					b = 0;
					break;
				}
			}
			if (b) {
				for (int j = 0; j < 5; ++j) line[i][j] = 1;
				hor[i] = 1;
				cnt_numline++;
			}
		}

		for (int i = 0; i < 5; ++i) {
			bool b = 1;
			for (int j = 0; j < 5; ++j) {
				if (!bingo[j][i]) {
					b = 0;
					break;
				}
			}
			if (b) {
				for (int j = 0; j < 5; ++j) line[j][i] = 1;
				ver[i] = 1;
				cnt_ver++;
				cnt_numline++;
			}
		}

		for (int i = 0; i < 5; ++i) {
			if (!bingo[i][i]) cross1 = 0;
			if (!bingo[i][4 - i]) cross2 = 0;
		}
		if (cross1) {
			for (int i = 0; i < 5; ++i) line[i][i] = 1;
			cnt_numline++;
		}
		if (cross2) {
			for (int i = 0; i < 5; ++i) line[i][4 - i] = 1;
			cnt_numline++;
		}

		for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) if (line[i][j]) cnt_line++;
		for (int i = 0; i < 5; ++i) if (bingo[i][2]) cnt_c++;

		if (bingo[0][0] != (!cross2)) continue;
		if (bingo[0][1] != (!line[0][1])) continue;
		if (bingo[0][2] != (cross1)) continue;
		if (bingo[0][3] != (bingo[3][3])) continue;
		if (bingo[0][4] != (line[0][4])) continue;

		if (bingo[1][0] != (!bingo[3][0])) continue;

		bool cond = 1;
		bool b = 0;
		for (int i = 0; i < 5; ++i) if (hor[i]) b = 1;
		cond &= b;
		b = 0;
		for (int i = 0; i < 5; ++i) if (ver[i]) b = 1;
		cond &= b;
		cond &= (cross1 | cross2);
		if (bingo[1][1] != (cond)) continue;

		if (bingo[1][2] != (bingo[1][2])) continue;
		if (bingo[1][3] != (cnt <= 17)) continue;
		if (bingo[1][4] != (cnt_line % 2 == 0)) continue;

		if (bingo[2][0] != (line[2][0])) continue;
		if (bingo[2][1] != (cnt - cnt_line >= 5)) continue;
		if (bingo[2][2] != (!bingo[2][2] || line[2][2])) continue;
		if (bingo[2][3] != (cnt_ver >= 2)) continue;
		if (bingo[2][4] != (25 - cnt_line >= 10)) continue;

		if (bingo[3][0] != (!bingo[1][0])) continue;
		if (bingo[3][1] != (hor[1] || ver[3])) continue;
		if (bingo[3][2] != (cnt_c <= 3)) continue;
		if (bingo[3][3] != (bingo[0][3])) continue;
		if (bingo[3][4] != (cross1 || cross2)) continue;

		if (bingo[4][0] != (bingo[4][4])) continue;
		//if (bingo[4][1] != ()) continue;
		if (bingo[4][2] != (bingo[4][2])) continue;
		if (bingo[4][3] != (cnt_numline >= 3)) continue;
		if (bingo[4][4] != (bingo[4][0])) continue;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (bingo[i][j]) cout << '#';
				else cout << '.';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

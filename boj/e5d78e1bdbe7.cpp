#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

bool emp[8][8], attack[8][8];

void rook(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (!emp[i][y]) break;
		attack[i][y] = 1;
	}
	for (int i = x + 1; i < 8; i++) {
		if (!emp[i][y]) break;
		attack[i][y] = 1;
	}
	for (int j = y - 1; j >= 0; j--) {
		if (!emp[x][j]) break;
		attack[x][j] = 1;
	}
	for (int j = y + 1; j < 8; j++) {
		if (!emp[x][j]) break;
		attack[x][j] = 1;
	}
}

void bishop(int x, int y) {
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
		if (!emp[i][j]) break;
		attack[i][j] = 1;
	}
	for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++) {
		if (!emp[i][j]) break;
		attack[i][j] = 1;
	}
	for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--) {
		if (!emp[i][j]) break;
		attack[i][j] = 1;
	}
	for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++) {
		if (!emp[i][j]) break;
		attack[i][j] = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (cin >> s) {
		memset(emp, 0, sizeof(emp));
		memset(attack, 0, sizeof(attack));
		int x = 0, y = 0;
		for (int k = 0; k < s.size(); ++k) {
			if (s[k] >= '1' && s[k] <= '8') {
				for (int j = 0; j < 1 + s[k] - '1'; ++j) {
					emp[x][y++] = 1;
				}
			}
			else if (s[k] == '/') {
				x++;
				y = 0;
			}
			else y++;
		}

		x = 0; y = 0;
		for (int k = 0; k < s.size(); ++k) {
			if (s[k] >= '1' && s[k] <= '8') {
				for (int j = 0; j < 1 + s[k] - '1'; ++j) y++;
			}
			else if (s[k] == '/') {
				x++;
				y = 0;
			}
			else {
				if (s[k] == 'B' || s[k] == 'b') {
					bishop(x, y);
				}
				else if (s[k] == 'R' || s[k] == 'r') {
					rook(x, y);
				}
				else if (s[k] == 'Q' || s[k] == 'q') {
					bishop(x, y);
					rook(x, y);
				}
				else {
					for (int i = 0; i < 8; ++i) {
						for (int j = 0; j < 8; ++j) {
							if (s[k] == 'P') {
								if (i == x - 1 && abs(j - y) == 1) attack[i][j] = 1;
							}
							else if (s[k] == 'p') {
								if (i == x + 1 && abs(j - y) == 1) attack[i][j] = 1;
							}
							else if (s[k] == 'N' || s[k] == 'n') {
								if (abs(i - x) + abs(j - y) == 3 && max(abs(i - x), abs(j - y)) == 2) attack[i][j] = 1;
							}
							else if (s[k] == 'K' || s[k] == 'k') {
								if (abs(i - x) <= 1 && abs(j - y) <= 1) attack[i][j] = 1;
							}
						}
					}
				}
				y++;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (emp[i][j] && !attack[i][j]) cnt++;
			}
		}
		cout << cnt << '\n';
	}
}
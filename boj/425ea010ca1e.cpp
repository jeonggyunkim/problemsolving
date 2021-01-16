#include <iostream>
#include <unordered_set>
using namespace std;

char board[11][6][7] = 
{
	{"1", "1111", "1"},
	{"01", "1111", "1"},
	{"001", "1111", "1"},
	{"0001", "1111", "1"},
	{"01", "1111", "01"},
	{"001", "1111", "01"},
	{"00111", "111"},
	{"0011", "011", "11"},
	{"0011", "111", "1"},
	{"11", "0111", "01"},
	{"01", "111", "0011"},
};

void rotate(int k) {
	char now[6][6] = {};
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			now[j][5 - i] = board[k][i][j];
		}
	}
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			board[k][i][j] = now[i][j];
		}
	}
}

void flip(int k) {
	char now[6][6] = {};
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			now[i][5 - j] = board[k][i][j];
		}
	}
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			board[k][i][j] = now[i][j];
		}
	}
}

int main() {
	unordered_set<string> st;
	for (int k = 0; k < 11; ++k) {
		for (int r = 0; r < 8; ++r) {
			for (int x = -6; x <= 6; ++x) {
				for (int y = -6; y <= 6; ++y) {
					char now[6][6] = {};
					int pos = 1;
					for (int i = 0; i < 6; ++i) {
						for (int j = 0; j < 6; ++j) {
							if (board[k][i][j] == '1') {
								int xx = i + x;
								int yy = j + y;
								if (xx < 0 || xx >= 6 || yy < 0 || yy >= 6) {
									pos = 0;
									break;
								}
								now[xx][yy] = '1';
							}
						}
						if (!pos) break;
					}
					if (pos) {
						string s;
						for (int i = 0; i < 6; ++i) {
							for (int j = 0; j < 6; ++j) {
								if (now[i][j] == '1') s += '1';
								else s += '0';
							}
						}
						st.insert(s);
					}
				}
			}
			rotate(k);
			if (r == 3) flip(k);
		}
	}

	for (int k = 0; k < 3; ++k) {
		string s;
		int t;
		for (int i = 0; i < 36; ++i) {
			cin >> t;
			if (t == 1) s += '1';
			else s += '0';
		}
		if (st.count(s)) cout << "yes\n";
		else cout << "no\n";
	}
}
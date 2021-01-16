#include <iostream>
#include <unordered_map>
using namespace std;

char board[11][6][7] = 
{
	{"1", "2378", "6"},
	{"01", "2378", "6"},
	{"001", "2378", "6"},
	{"0001", "2378", "6"},
	{"01", "2378", "06"},
	{"001", "2378", "06"},
	{"00126", "378"},
	{"0012", "073", "86"},
	{"0037", "126", "8"},
	{"12", "0368", "07"},
	{"01", "237", "0068"},
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
	unordered_map<string, string> st;
	for (int k = 0; k < 11; ++k) {
		for (int r = 0; r < 8; ++r) {
			for (int x = -6; x <= 6; ++x) {
				for (int y = -6; y <= 6; ++y) {
					char now[6][6] = {};
					int pos = 1;
					for (int i = 0; i < 6; ++i) {
						for (int j = 0; j < 6; ++j) {
							if (board[k][i][j] >= '1') {
								int xx = i + x;
								int yy = j + y;
								if (xx < 0 || xx >= 6 || yy < 0 || yy >= 6) {
									pos = 0;
									break;
								}
								now[xx][yy] = board[k][i][j];
							}
						}
						if (!pos) break;
					}
					if (pos) {
						string key, value;
						for (int i = 0; i < 6; ++i) {
							for (int j = 0; j < 6; ++j) {
								if (now[i][j] >= '1') {
									key += '1';
									value += now[i][j];
								}
								else {
									key += '0';
									value += '0';
								}
							}
						}
						st[key] = value;
					}
				}
			}
			rotate(k);
			if (r == 3) flip(k);
		}
	}

	string s, ss;
	int t;
	for (int i = 0; i < 36; ++i) {
		cin >> t;
		if (t >= 1) s += '1';
		else s += '0';
		ss += '0' + t;
	}
	if (st.count(s)) {
		int goal;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (ss[i * 6 + j] == '1') {
					goal = (st[s][i * 6 + j] - '0' + 5) % 10 + '0';
				}
			}
		}
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (st[s][i * 6 + j] == goal) {
					cout << ss[i * 6 + j];
				}
			}
		}
	}
	else cout << 0;
}
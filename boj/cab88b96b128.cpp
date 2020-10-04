#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[6];
string board[3];
int used[6];

void rec(int d) {
	if (d == 3) {
		int cnt = 0;
		for (int i = 0; i < 3; ++i) {
			string v;
			for (int j = 0; j < 3; ++j) v += board[j][i];
			for (int j = 0; j < 6; ++j) {
				if (!used[j] && s[j] == v) {
					used[j] += 2;
					cnt++;
					break;
				}
			}
		}
		if (cnt == 3) {
			for (int i = 0; i < 3; ++i) {
				cout << board[i] << '\n';
			}
			exit(0);
		}
		else {
			for (int i = 0; i < 6; ++i) {
				if (used[i] == 2) used[i] -= 2;
			}
		}
		return;
	}
	for (int i = 0; i < 6; ++i) {
		if (!used[i]) {
			board[d] = s[i];
			used[i] = 1;
			rec(d + 1);
			used[i] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 6; ++i) cin >> s[i];
	sort(s, s + 6);

	rec(0);
	cout << '0';
}
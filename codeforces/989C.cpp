#include <bits/stdc++.h>
using namespace std;

char board[50][50];

void paint(int i, int j, int r, int color) {
	if (color >= 'C') r--;
	for (int t = 0; t < r; ++t) {
		board[i][j] = color;
		if (j >= 48) {
			i += 2;
			j = 1;
		}
		else j += 2;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	for (int i = 0; i < 25; ++i) for (int j = 0; j < 50; ++j) board[i][j] = 'C';
	for (int i = 25; i < 50; ++i) for (int j = 0; j < 50; ++j) board[i][j] = 'D';

	paint(0, 1, d, 'D');
	paint(8, 1, a, 'A');
	paint(16, 1, b, 'B');
	paint(40, 1, c, 'C');

	cout << 50 << ' ' << 50 << '\n';
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) cout << board[i][j];
		cout << '\n';
	}
}
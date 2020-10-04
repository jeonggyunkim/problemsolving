#include <iostream>
using namespace std;

int white, blue;
int paper[128][128];

void quad(int x, int y, int n) {
	bool same = 1;
	for (int i = x; i < x + n; ++i) {
		for (int j = y; j < y + n; ++j) {
			if (paper[i][j] != paper[x][y]) same = 0;
		}
	}

	if (same) {
		if (paper[x][y]) blue++;
		else white++;
	}
	else {
		quad(x, y, n / 2);
		quad(x, y + n / 2, n / 2);
		quad(x + n / 2, y, n / 2);
		quad(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> paper[i][j];

	quad(0, 0, n);
	cout << white << '\n';
	cout << blue << '\n';
}
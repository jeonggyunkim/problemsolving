#include <iostream>
using namespace std;

char str[3 * (1 << 11)][3 * (1 << 10)];

void draw_star(int n, int x, int y) {
	if (n == 3) {
		for (int i = 0; i < 5; ++i) str[x + i][y] = '*';
		str[x + 1][y + 1] = '*';
		str[x + 3][y + 1] = '*';
		str[x + 2][y + 2] = '*';
		return;
	}
	draw_star(n / 2, x, y);
	draw_star(n / 2, x + n, y);
	draw_star(n / 2, x + n / 2, y + n / 2);
}

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 2 * n - 1; ++j) str[j][i] = ' ';
	}
	draw_star(n, 0, 0);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 2 * n - 1; ++j) {
			cout << str[j][i];
		}
		cout << '\n';
	}
}
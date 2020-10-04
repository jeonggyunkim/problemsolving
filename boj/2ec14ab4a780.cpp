#include <iostream>
using namespace std;

int cnt[3];
int arr[2187][2187];

void rec(int n, int x, int y) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[x + i][y + j] != arr[x][y]) {
				goto brk;
			}
		}
	}
	cnt[arr[x][y] + 1]++;
	return;

	brk:
	n /= 3;
	rec(n, x, y);
	rec(n, x, y + n);
	rec(n, x, y + 2 * n);
	rec(n, x + n, y);
	rec(n, x + n, y + n);
	rec(n, x + n, y + 2 * n);
	rec(n, x + 2 * n, y);
	rec(n, x + 2 * n, y + n);
	rec(n, x + 2 * n, y + 2 * n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> arr[i][j];
	}
	rec(n, 0, 0);

	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
	cout << cnt[2] << '\n';
}
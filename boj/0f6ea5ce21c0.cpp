#include <iostream>
using namespace std;

int arr[7], n, m;

void rec(int x, int y) {
	if (x == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = y; i <= n; ++i) {
		arr[x] = i;
		rec(x + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	rec(0, 1);
}
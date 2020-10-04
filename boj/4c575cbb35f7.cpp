#include <iostream>
using namespace std;

int arr[7], n, m;

void rec(int x) {
	if (x == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) {
		arr[x] = i;
		rec(x + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	rec(0);
}
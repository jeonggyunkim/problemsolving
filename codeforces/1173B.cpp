#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << n / 2 + 1 << '\n';

	int x = 1, y = 1;
	for (int i = 0; i < n; ++i) {
		cout << x << ' ' << y << '\n';
		if (i & 1) y++;
		else x++;
	}
}
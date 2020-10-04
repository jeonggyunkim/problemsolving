#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int ans = 0;
	ans += (n - (x2 - x1 + 1)) * (m % 2);
	ans += (x2 - x1 + 1) * ((y1 - 1) % 2 + (m - y2) % 2);
	cout << (ans + 1) / 2;
}
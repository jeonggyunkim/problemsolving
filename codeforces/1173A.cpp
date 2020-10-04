#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, z;
	cin >> x >> y >> z;

	int l = x - y - z;
	int u = x - y + z;

	if (l == 0 && u == 0) cout << '0';
	else if (l < 0 && u < 0) cout << '-';
	else if (l > 0 && u > 0) cout << '+';
	else cout << '?';
}
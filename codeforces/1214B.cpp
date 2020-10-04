#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int b, g, n;
	cin >> b >> g >> n;

	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (b >= i && g >= n - i) ans++;
	}
	cout << ans;
}
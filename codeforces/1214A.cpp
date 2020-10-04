#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, e;
	cin >> n >> d >> e;

	e *= 5;

	int ans = n % d;

	for (int i = n - e; i >= 0; i -= e) {
		ans = min(ans, i % d);
	}
	cout << ans;
}
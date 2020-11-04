#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int ans = 0, t, n;
		cin >> n;
		while (n--) {
			cin >> t;
			ans ^= t;
		}
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
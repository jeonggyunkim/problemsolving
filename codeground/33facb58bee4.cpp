#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int n, k;
		bool imp = false;
		cin >> n;
		
		vector<int> arr(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> arr[i];
		cin >> k;
		
		int ans = 0, now = arr[n];
		while (now) {
			int t = *lower_bound(arr.begin(), arr.end(), now - k);
			if (now == t) {
				imp = true;
				break;
			}
			now = t;
			ans++;
		}
		
		cout << "Case #" << test << '\n';
		if (imp) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());
		
		long long ans = 0;
		for (int i = 0; i < n; i += 2) ans += arr[i];
		for (int i = 1; i < n; i += 2) ans -= arr[i];
		
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
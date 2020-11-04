#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int n, k, ans = 0;
		cin >> n >> k;
		
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end(), greater<int>());
		
		for (int i = 0; i < k; ++i) ans += arr[i];
		
	    cout << "Case #" << test << '\n';
	    cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int n, ans = 0;
		cin >> n;
		
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());
		
		int win = -1;
		for (int i = 0; i < n; ++i) win = max(win, arr[i] + n - i);
		for (int i = 0; i < n; ++i) if (arr[i] + n >= win) ans++;
		
	    cout << "Case #" << test << '\n';
	    cout << ans << '\n';
	}
}
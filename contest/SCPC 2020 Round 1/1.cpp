#include <bits/stdc++.h>
using namespace std;

int a[200000];
int b[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int n, k;
		cin >> n >> k;
		
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		
		sort(a, a + n);
		sort(b, b + n);
		
		int ans = 0;
		for (int i = 0; i < k ; ++i) {
			ans = max(ans, a[i] + b[k - 1 - i]);
		}
		
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}

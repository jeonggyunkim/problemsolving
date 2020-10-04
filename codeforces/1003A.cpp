#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	vector<int> cnt(101, 0);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t]++;
	}

	int ans = -1;
	for (int i = 0; i < 101; ++i) ans = max(ans, cnt[i]);
	cout << ans;
}
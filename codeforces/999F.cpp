#include <bits/stdc++.h>
using namespace std;

int dp[501][5001];
int value[11];
int k;

int maximum(int n, int card) {
	if (dp[n][card] > 0) return dp[n][card];
	int m = min(k, card);
	if (n == 1) return dp[n][card] = value[m];
	int ret = 0;
	for (int i = 1; i <= m; ++i) {
		int t = value[i] + maximum(n - 1, card - i);
		ret = max(ret, t);
	}
	return dp[n][card] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long ans = 0;
	int n, t;
	cin >> n >> k;
	map<int, int> card;
	map<int, int> pref;

	n *= k;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		card[t]++;
	}
	n /= k;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		pref[t]++;
	}

	for (int i = 1; i <= k; ++i) {
		cin >> t;
		value[i] = t;
	}

	for (auto it = pref.begin(); it != pref.end(); ++it) {
		int t = card[it->first];
		if (t > 0) ans += maximum(it->second, t);
	}
	cout << ans;
}
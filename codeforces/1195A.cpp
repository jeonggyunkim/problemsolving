#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int t;
	vector<int> cnt(k, 0);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		t--;
		cnt[t]++;
	}

	int odd = 0;
	for (int i = 0; i < k; ++i) {
		if (cnt[i] & 1) odd++;
	}
	cout << n - odd / 2;
}
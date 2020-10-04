#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<long long, int> m;
	long long t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		m[t]++;
		cin >> t;
		m[t + 1]--;
	}
	int k = 0;

	vector<long long> cnt(n + 1);
	for (auto it = m.begin(); it != m.end(); ++it) {
		k += it->second;
		if (k) {
			auto jt = it;
			jt++;
			cnt[k] += jt->first - it->first;
		}
	}

	for (int i = 1; i <= n; ++i) cout << cnt[i] << ' ';
}
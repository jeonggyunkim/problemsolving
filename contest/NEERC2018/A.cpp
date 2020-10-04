#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d, t;
	cin >> n >> m >> d;

	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		mp[t] = i;
	}

	vector<int> ans(n);
	int day = 1;
	while (!mp.empty()) {
		int start = 1;
		while (1) {
			auto it = mp.lower_bound(start);
			if (it != mp.end()) {
				ans[it->second] = day;
				start = it->first + d + 1;
				mp.erase(it);
			}
			else break;
		}
		day++;
	}

	cout << day - 1 << '\n';
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}
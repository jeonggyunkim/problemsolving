#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long ans = 0;
	int n, m;
	cin >> n >> m;

	int goal = n / m;
	vector<int> arr(n);
	vector<int> rem(m, 0);
	vector<vector<int>> add(m);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int t = arr[i] % m;
		rem[t]++;
		if (rem[t] > goal) add[t].push_back(i);
	}

	set<int> low, high;
	for (int i = 0; i < m; ++i) {
		if (rem[i] > goal) high.insert(i);
		else if (rem[i] < goal) low.insert(i);
	}

	for (auto it = high.begin(); it != high.end(); ++it) {
		while (rem[*it] > goal) {
			auto jt = low.lower_bound(*it);
			if (jt == low.end()) jt = low.begin();

			int cnt = min(rem[*it] - goal, goal - rem[*jt]);
			rem[*it] -= cnt; rem[*jt] += cnt;
			int move = (*jt - *it + m) % m;
			ans += cnt * move;
			for (int j = 0; j < cnt; ++j) {
				arr[add[*it].back()] += move;
				add[*it].pop_back();
			}
			if (rem[*jt] == goal) low.erase(*jt);
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
}
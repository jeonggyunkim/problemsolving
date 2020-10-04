#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> quan, to_del;

void split(int n) {
	for (auto it = to_del.rbegin(); it != to_del.rend(); ++it) {
		int t = n / it->first;
		if (t == 0) continue;

		if (quan.count(it->first)) quan[it->first] += t;
		else quan[it->first] = t;
		n %= it->first;
		if (n == 0) return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		to_del[t]++;
	}

	for (int i = 0; i < n; ++i) {
		split(arr[i]);
	}

	int ans = 0;
	for (auto it = to_del.begin(); it != to_del.end(); ++it) {
		while (it->second) {
			auto jt = quan.lower_bound(it->first);
			if (jt != quan.end()) {
				ans++;
				int t = jt->first - it->first;
				it->second--;
				jt->second--;
				if (jt->second == 0) quan.erase(jt->first);
				if (t) split(t);
			}
			else break;
		}
	}
	cout << ans;
}

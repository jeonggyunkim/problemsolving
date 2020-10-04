#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	map<int, int> m;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = m.upper_bound(arr[i]);
		if (it == m.end()) continue;
		else {
			ans++;
			(it->second)--;
			if (it->second == 0) {
				m.erase(it->first);
			}
		}
	}
	cout << ans;
}
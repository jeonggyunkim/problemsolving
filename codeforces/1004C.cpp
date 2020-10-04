#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> m;
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	set<int> used;
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		m[arr[i]]--;
		if (m[arr[i]] == 0) m.erase(arr[i]);

		if (used.find(arr[i]) == used.end()) {
			ans += m.size();
			used.insert(arr[i]);
		}
	}
	cout << ans;
}
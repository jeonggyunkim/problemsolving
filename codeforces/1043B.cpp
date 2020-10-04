#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = n - 1; i > 0; --i) arr[i] -= arr[i - 1];

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		bool b = 1;
		for (int j = 0; j < n; ++j) {
			if (j + i < n && arr[j] != arr[j + i]) b = 0;
		}
		if (b) ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int u: ans) cout << u << ' ';
}
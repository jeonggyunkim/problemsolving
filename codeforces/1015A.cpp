#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		bool in = 0;
		for (int j = 0; j < n; ++j) {
			if (arr[j].first <= i && i <= arr[j].second) in = 1;
		}
		if (!in) ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int u: ans) cout << u << ' ';
}
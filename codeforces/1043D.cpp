#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	vector<bool> sep(n - 1, 0);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 1; i < m; ++i) {
		vector<int> temp1(n);
		vector<ii> temp2(n);
		for (int i = 0; i < n; ++i) {
			cin >> temp1[i];
			temp2[i].first = temp1[i];
			temp2[i].second = i;
		}
		sort(temp2.begin(), temp2.end());

		for (int i = 0; i < n - 1; ++i) {
			int index = temp2[arr[i] - 1].second + 1;
			if (index >= n || temp1[index] != arr[i + 1]) sep[i] = 1;
		}
	}

	long long suc = 1, ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (!sep[i]) suc++;
		else {
			ans += suc * (suc + 1) / 2;
			suc = 1;
		}
	}
	ans += suc * (suc + 1) / 2;

	cout << ans;
}
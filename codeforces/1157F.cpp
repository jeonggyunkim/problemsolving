#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	vector<int> cnt(200010, 0);
	for (int i = 0; i < n; ++i) {
		cin >> t;
		cnt[t]++;
	}

	vector<ii> arr;
	for (int i = 0; i < 200010; ++i) if (cnt[i]) arr.push_back(ii(i, cnt[i]));

	int i = 0, j = 0;
	t = arr[0].second;
	int ans = -1, as, ae;
	while (i < arr.size()) {
		while (1) {
			if (j == arr.size() - 1 || arr[j + 1].first - arr[j].first > 1 || (arr[j].second == 1 && i != j)) break;
			j++;
			t += arr[j].second;
		}
		if (t > ans) {
			ans = t;
			as = i;
			ae = j;
		}

		if (i == j) {
			j++;
			t += arr[j].second;
		}
		t -= arr[i].second;
		i++;
	}

	cout << ans << '\n';
	vector<int> start, end;
	for (int i = as; i <= ae; ++i) {
		for (int j = 0; j < arr[i].second; ++j) {
			if (j == 0) start.push_back(arr[i].first);
			else end.push_back(arr[i].first);
		}
	}

	for (int i = 0; i < start.size(); ++i) cout << start[i] << ' ';
	for (int i = end.size() - 1; i >= 0; --i) cout << end[i] << ' ';
}

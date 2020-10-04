#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr.rbegin(), arr.rend());

	vector<int> tree(2 * n, 0);
	vector<ii> ans;
	for (int i = 0; i < n; ++i) {
		tree[i] = arr[i].second * 2 - 1;
		if (i != 0) ans.push_back({tree[i - 1], tree[i]});
	}
	for (int i = 0; i < n; ++i) {
		int ind = arr[i].second * 2;
		int d = arr[i].first;
		if (tree[i + d]) {
			ans.push_back({tree[i + d - 1], ind});
		}
		else {
			tree[i + d] = ind;
			ans.push_back({ind, tree[i + d - 1]});
		}
	}

	for (ii u: ans) {
		cout << u.first << ' ' << u.second << '\n';
	}
}
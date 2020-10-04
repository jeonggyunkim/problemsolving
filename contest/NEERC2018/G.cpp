#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n - 1);
	map<int, int> cnt;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		if (b != n) {
			cout << "NO";
			return 0;
		}
		cnt[a]++;
		arr[i] = {a, i};
	}

	sort(arr.begin(), arr.end());

	vector<int> num(n, -1);
	vector<int> edge(n - 1);
	num[0] = n;

	int empty = 0, index = 0, j = n - 2;
	for (int i = n - 1; i >= 1; --i) {
		if (cnt.count(i)) {
			for (int k = 0; k < cnt[i]; ++k) {
				edge[index + k] = arr[j - k].second;
			}
			index += cnt[i];
			j -= cnt[i];
			num[index] = i;
		}
		else {
			while (num[empty] != -1) empty++;
			num[empty++] = i;
		}

		if (empty > index) {
			cout << "NO";
			return 0;
		}
	}

	vector<ii> ans(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		ans[edge[i]] = {num[i], num[i + 1]};
	}

	cout << "YES\n";
	for (int i = 0; i < n - 1; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
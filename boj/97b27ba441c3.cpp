#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> ii;

int p[55];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ii> arr;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == 'Y') {
				arr.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < n; ++i) p[i] = i;

	if (arr.size() < m)	 {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	bool used[2510] = {};
	for (int i = 0; i < arr.size(); ++i) {
		int a = find(arr[i].first);
		int b = find(arr[i].second);

		if (a != b) {
			p[a] = b;
			used[i] = 1;
			cnt++;
		}
	}

	if (cnt != n - 1) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < arr.size(); ++i) {
		if (!used[i]) {
			used[i] = 1;
			cnt++;
		}
		if (cnt == m) break;
	}

	int ans[51] = {};
	for (int i = 0; i < arr.size(); ++i) {
		if (used[i]) {
			ans[arr[i].first]++;
			ans[arr[i].second]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
}
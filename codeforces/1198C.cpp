#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		vector<bool> matched(3 * n, 0);
		vector<int> ans;

		int a, b;
		for (int i = 1; i <= m; ++i) {
			cin >> a >> b;
			a--; b--;
			if (!matched[a] && !matched[b]) {
				matched[a] = 1;
				matched[b] = 1;
				ans.push_back(i);
			}
		}

		if (ans.size() >= n) {
			cout << "Matching\n";
			for (int i = 0; i < n; ++i) {
				cout << ans[i] << ' ';
			}
		}
		else {
			cout << "IndSet\n";
			int cnt = n;
			for (int i = 0; i < 3 * n; ++i) {
				if (!matched[i]) {
					cout << i + 1 << ' ';
					cnt--;
				}
				if (cnt == 0) break;
			}
		}
		cout << '\n';
	}
}
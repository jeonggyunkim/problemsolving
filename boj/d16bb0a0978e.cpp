#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int num[1010];
	for (int i = 0; i < m; ++i) cin >> num[i];

	vector<int> sug[1010];
	vector<int> ans[1010];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			int t;
			while (cin >> t, t != -1) {
				t--;
				sug[t].push_back(j);
			}
		}
		for (int j = 0; j < m; ++j) {
			if (sug[j].size() <= num[j]) {
				for (int u: sug[j]) {
					ans[u].push_back(j);
				}
				num[j] -= sug[j].size();
				sug[j].clear();
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (ans[i].size() == 0) {
			cout << "망했어요\n";
		}
		else {
			sort(ans[i].begin(), ans[i].end());
			for (int u: ans[i]) cout << u + 1 << ' ';
			cout << '\n';
		}
	}
}
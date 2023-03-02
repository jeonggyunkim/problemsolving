#include <iostream>
#include <vector>
using namespace std;

int cnt[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> n >> m;

	while (m--) {
		cin >> k;
		while (k--) {
			cin >> t;
			cnt[t]++;
		}
	}

	int mx = -1;
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt[i] == mx) {
			ans.push_back(i);
		}
	}

	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << ' ';
}
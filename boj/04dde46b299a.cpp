#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, l, k;
		cin >> n >> l >> k;

		vector<int> loc(n), id(n);
		vector<ii> drop(n);

		for (int i = 0; i < n; ++i) {
			cin >> loc[i] >> id[i];
			if (id[i] > 0) drop[i] = ii(l - loc[i], id[i]);
			else drop[i] = ii(loc[i], id[i]);
		}
		sort(drop.begin(), drop.end());

		int left = 0, right = 0;
		bool last;
		for (int i = 0; i < k; ++i) {
			if (drop[i].second > 0) {
				right++;
				last = 1;
			}
			else {
				left++;
				last = 0;
			}
		}

		int ans[2];
		if (last) ans[0] = id[n - right];
		else ans[0] = id[left - 1];

		if (k != 1 && drop[k - 2].first == drop[k - 1].first) {
			if (!last) left--;
			ans[1] = id[left - 1];
			cout << max(ans[0], ans[1]) << '\n';
		}
		else if (k != n && drop[k - 1].first == drop[k].first) {
			if (drop[k].second > 0) {
				right++;
				last = 1;
			}
			else {
				left++;
				last = 0;
			}
			if (last) ans[1] = id[n - right];
			else ans[1] = id[left - 1];
			cout << min(ans[0], ans[1]) << '\n';
		}
		else {
			cout << ans[0] << '\n';
		}
	}
}
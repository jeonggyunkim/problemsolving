#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int arr[100];
int ans[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int p, n;
		cin >> p >> n;

		int ideal = p / n, sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		if (sum < p) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		int left = p;
		for (int i = 0; i < n; ++i) {
			ans[i] = min(arr[i], ideal);
			left -= ans[i];
		}

		while (left) {
			vector<pair<int, int>> put;
			int to_put = INF;
			for (int i = 0; i < n; ++i) {
				if (arr[i] > ans[i]) {
					put.push_back({ans[i] - arr[i], i});
					to_put = min(to_put, arr[i] - ans[i]);
				}
			}
			sort(put.begin(), put.end());
			to_put = min(to_put, left / (int)put.size());
			if (to_put == 0) to_put = 1;

			for (int i = 0; i < put.size() && left; ++i) {
				int now = min(to_put, left);
				ans[put[i].second] += now;
				left -= now;
			}
		}

		for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}

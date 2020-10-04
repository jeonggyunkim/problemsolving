#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int max[101][101] = {};
		int cnt[101][101] = {};
		cin >> max[1][1];
		cnt[1][1] = 1;

		int t;
		for (int i = 2; i <= n; ++i) for (int j = 1; j <= i; ++j) {
			cin >> t;
			if (max[i - 1][j - 1] > max[i - 1][j]) {
				max[i][j] = max[i - 1][j - 1] + t;
				cnt[i][j] = cnt[i - 1][j - 1];
			}
			else if (max[i - 1][j - 1] < max[i - 1][j]) {
				max[i][j] = max[i - 1][j] + t;
				cnt[i][j] = cnt[i - 1][j];
			}
			else {
				max[i][j] = max[i - 1][j - 1] + t;
				cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j];;
			}
		}

		int l = -1, ans = 0;
		for (int i = 1; i <= n; ++i) if (max[n][i] > l) l = max[n][i];
		for (int i = 1; i <= n; ++i) if (max[n][i] == l) ans += cnt[n][i];

		cout << ans << '\n';
	}
}

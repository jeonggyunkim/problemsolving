#include <iostream>
#include <algorithm>
using namespace std;

int board[21][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int ans = 987654321;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			for (int d1 = 1; 1 <= y - d1; ++d1) {
				for (int d2 = 1; y + d2 <= n && x + d1 + d2 <= n; ++d2) {
					int who[21][21] = {};
					for (int i = 1; i <= n; ++i) {
						for (int j = 1; j <= n; ++j) {
							if (1 <= i && i < x + d1 && 1 <= j && j <= y) who[i][j] = 1;
							if (1 <= i && i <= x + d2 && y < j && j <= n) who[i][j] = 2;
							if (x + d1 <= i && i <= n && 1 <= j && j < y - d1 + d2) who[i][j] = 3;
							if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n) who[i][j] = 4;
						}
					}

					int start = 0, end = 0;
					for (int i = 0; i <= d1 + d2; ++i) {
						for (int j = start; j <= end; ++j) {
							who[x + i][y + j] = 5;
						}
						if (i < d1) start--;
						else start++;
						if (i < d2) end++;
						else end--;
					}

					int cnt[5] = {};

					for (int i = 1; i <= n; ++i) {
						for (int j = 1; j <= n; ++j) {
							cnt[who[i][j] - 1] += board[i][j];
						}
					}
					int imp = 0;
					for (int i = 0; i < 5; ++i) if (cnt[i] == 0) imp = 1;

					if (!imp) {
						int now = max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]}) - min({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]});
						ans = min(now, ans);
					}
				}
			}
		}
	}
	cout << ans;
}
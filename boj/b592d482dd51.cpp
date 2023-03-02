#include <iostream>
#include <memory.h>
using namespace std;

int dp[5001][5001];
int p[5001][5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int n, a, l;
	cin >> n >> a >> l;

	dp[0][l] = a;
	int x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y;
		for (int j = 0; j <= 5000; ++j) {
			if (dp[i - 1][j] != -1) {
				if (x == -1) {
					if (j - y > 0) {
						dp[i][j - y] = dp[i - 1][j];
						p[i][j - y] = j + 10000;
					}
				}
				else if (y == -1) {
					dp[i][j] = max(dp[i - 1][j] - x, 0);
					p[i][j] = j;
				}
				else {
					if (dp[i - 1][j] >= x) {
						int now = max(dp[i - 1][j] - x, 0);
						if (now > dp[i][j]) {
							dp[i][j] = now;
							p[i][j] = j;
						}
					}
					if (j - y > 0) {
						int now = max(dp[i][j - y], dp[i - 1][j]);
						if (now > dp[i][j - y]) {
							dp[i][j - y] = now;
							p[i][j - y] = j + 10000;
						}
					}
				}
			}
		}
	}
	string s;
	for (int i = 1; i <= 5000; ++i) {
		if (dp[n][i] != -1) {
			int now = i;
			for (int j = n; j >= 1; --j) {
				if (p[j][now] >= 10000) {
					s += 'L';
					now = p[j][now] - 10000;
				}
				else {
					s += 'A';
					now = p[j][now];
				}
			}
			break;
		}
	}
	if (s.size()) {
		cout << "YES\n";
		for (int i = n - 1; i >= 0; --i) cout << s[i];
	}
	else cout << "NO";
}
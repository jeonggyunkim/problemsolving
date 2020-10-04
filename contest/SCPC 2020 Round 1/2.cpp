#include <bits/stdc++.h>
using namespace std;

int a[3000], b[3000];
int acnt[3000], bcnt[3000];

int dp[3001][3001];

void set(int i, int j, int v) {
	int& ref = dp[i][j] = 0;
	if (i) ref += dp[i - 1][j];
	if (j) ref += dp[i][j - 1];
	if (i && j) ref -= dp[i - 1][j - 1];
	dp[i][j] += v;
}

int get(int i, int j, int x, int y) {
	int ret = dp[x][y];
	if (i) ret -= dp[i - 1][y];
	if (j) ret -= dp[x][j - 1];
	if (i && j) ret += dp[i - 1][j - 1];
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int n, k;
		cin >> n >> k;
		
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			int sum = 0, cnt = 0;
			for (int j = i; j >= 0; --j) {
				sum += a[j];
				if (sum <= k) cnt++;
				else break;
			}
			acnt[i] = cnt;
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			int sum = 0, cnt = 0;
			for (int j = i; j >= 0; --j) {
				sum += b[j];
				if (sum <= k) cnt++;
				else break;
			}
			bcnt[i] = cnt;
		}

		set(0, 0, 1);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 && j == 0) continue;
				int win = 0;
				if (i) {
					if (get(i - acnt[i - 1], j, i - 1, j) != acnt[i - 1]) win = 1;
				}
				if (j && !win) {
					if (get(i, j - bcnt[j - 1], i, j - 1) != bcnt[j - 1]) win = 1;
				}
				set(i, j, win);
			}
		}

		cout << "Case #" << test << '\n';
		cout << dp[n][n] << ' ' << (n + 1) * (n + 1) - dp[n][n] << '\n';
	}
}
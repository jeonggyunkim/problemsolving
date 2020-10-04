#include <iostream>
#include <vector>
#define INF ~(1 << 31)
using namespace std;

typedef pair<int, int> ii;

int n;
int dp[1000][1000][2];
ii pos[1001];
int left_sum[1001];
int right_sum[1001];

int cal(int l, int r, bool left) {
	if (dp[l][r][left] > 0) return dp[l][r][left];
	if (l == 0 && r == 0) return 0;

	int r1 = INF, r2 = INF;
	if (left) {
		if (l > 0) {
			r1 = (left_sum[l] + right_sum[r]) * (pos[l + 1].first - pos[l].first);
			r1 += cal(l - 1, r, 1);
		}
		if (r > 0) {
			r2 = (left_sum[l] + right_sum[r]) * (pos[n - r + 1].first - pos[l + 1].first);
			r2 += cal(l, r - 1, 0);
		}
	}
	else {
		if (l > 0) {
			r1 = (left_sum[l] + right_sum[r]) * (pos[n - r].first - pos[l].first);
			r1 += cal(l - 1, r, 1);
		}
		if (r > 0) {
			r2 = (left_sum[l] + right_sum[r]) * (pos[n - r + 1].first - pos[n - r].first);
			r2 += cal(l, r - 1, 0);
		}
	}

	return dp[l][r][left] = min(r1, r2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) cin >> pos[i].first >> pos[i].second;
	for (int i = 1; i <= m - 1; ++i) left_sum[i] = left_sum[i - 1] + pos[i].second;
	for (int i = n; i >= m + 1; --i) right_sum[n - i + 1] = right_sum[n - i] + pos[i].second;

	cout << cal(m - 1, n - m, 1);
}
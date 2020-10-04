#include <iostream>
#include <memory.h>
#define INF 10000
using namespace std;

int n, k, m, l;
int pre[12];
int sem[10];
int dp[10][1 << 12];

int minsem(int now, int mask) {
	if (__builtin_popcount(mask) >= k) return 0;
	if (now >= m) return INF;

	int& ret = dp[now][mask];
	if (ret != -1) return ret;

	int can = sem[now] & ~mask;
	for (int i = 0; i < n; ++i) {
		if ((can & (1 << i)) && (pre[i] & mask) != pre[i]) can &= ~(1 << i);
	}

	ret = minsem(now + 1, mask);
	for (int i = can; i; i = (i - 1) & can) {
		if (__builtin_popcount(i) > l) continue;
		ret = min(ret, minsem(now + 1, mask | i) + 1);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n >> k >> m >> l;

		int a, b;
		for (int i = 0; i < n; ++i) {
			pre[i] = 0;
			cin >> a;
			while (a--) {
				cin >> b;
				pre[i] |= (1 << b);
			}
		}

		for (int i = 0; i < m; ++i) {
			sem[i] = 0;
			cin >> a;
			while (a--) {
				cin >> b;
				sem[i] |= (1 << b);
			}
		}

		minsem(0, 0);
		if (dp[0][0] == INF) cout << "IMPOSSIBLE\n";
		else cout << dp[0][0] << '\n';
	}
}

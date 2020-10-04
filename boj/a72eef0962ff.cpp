#include <iostream>
#include <memory.h>
#define INF ((1 << 29) - 1)
using namespace std;

int n;
int price[16][16];
int dp[16][1 << 16];

int turn(int todo, int status) {
	if (todo <= 0) return 0;
	if (dp[todo][status] != -1) return dp[todo][status];
	int ret = INF;
	for (int i = 0; i < n; ++i) {
		if (status & (1 << i)) continue;
		int lm = INF;
		for (int j = 0; j < n; ++j) {
			if (status & (1 << j)) {
				lm = min(lm, price[j][i]);
			}
		}
		lm += turn(todo - 1, status | (1 << i));
		ret = min(ret, lm);
	}
	return dp[todo][status] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> price[i][j];

	memset(dp, -1, sizeof(dp));

	char s[17];
	int mask = 0, t;
	cin >> s >> t;
	int on = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'Y') {
			mask |= (1 << i);
			on++;
		}
	}

	if (on == 0) {
		if (t == 0) cout << 0;
		else cout << -1;
	}
	else cout << turn(t - on, mask);
}
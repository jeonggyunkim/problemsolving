#include <iostream>
#define MOD 1000000007
using namespace std;

int p[5050];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		p[a] = b;
		return 1;
	}
	return 0;
}

long long dp[5010][5010];
long long sum[5010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = 1;
		sum[i] = 1;
		p[i] = i;
		for (int j = 2; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;
			(sum[i] += dp[i][j]) %= MOD;
		}
	}

	int a, b;
	int cnt = n;
	while (m--) {
		cin >> a >> b;
		if (merge(a, b)) cnt--;
		cout << sum[cnt] << '\n';
	}
}
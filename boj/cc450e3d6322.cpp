#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

long long dp[10010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ii> stuff;

	int v, c, k;
	while (n--) {
		cin >> v >> c >> k;
		for (int i = 1; k; i *= 2) {
			int now = min(i, k);
			stuff.push_back({now * v, now * c});
			k -= now;
		}
	}

	sort(stuff.begin(), stuff.end());

	int sum = 0;
	for (ii& u: stuff) {
		for (int i = min(sum, m - u.first); i >= 0; --i) {
			dp[i + u.first] = max(dp[i + u.first], dp[i] + u.second);
		}
		sum = min(m, sum + u.first);
	}
	
	long long ans = 0;
	for (int i = 0; i <= m; ++i) ans = max(ans, dp[i]);
	cout << ans;
}
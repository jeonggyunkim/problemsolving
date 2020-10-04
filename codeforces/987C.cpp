#include <bits/stdc++.h>
using namespace std;

int n;
int size[3001];
int cost[3001];
int dp[3001] = {};

int second(int y) {
	if (dp[y] > 0) return dp[y];
	int min = (1 << 30);
	for (int z = y + 1; z < n; ++z) {
		if (size[y] < size[z]) {
			int t = cost[y] + cost[z];
			if (t < min) min = t;
		}
	}
	return dp[y] = min;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> size[i];
	for (int i = 0; i < n; ++i) cin >> cost[i];

	int min = (1 << 30);
	for (int x = 0; x < n - 2; ++x) {
		for (int y = x + 1; y < n - 1; ++y) {
			if (size[x] < size[y]) {
				int t = cost[x] + second(y);
				if (t < min) min = t;
			}
		}
	}
	if (min == (1 << 30)) cout << -1;
	else cout << min;
}
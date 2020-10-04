#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

ii x[200010];
int sum[200010];

inline int SUM(int i, int j) {
	return sum[j] - sum[i - 1];
}

int binary(int start, int h, int i, int j) {
	if (x[i].first - start >= h) return h;
	if (x[j].second - start - SUM(i, j) < h) return SUM(i, j) + h;
	int low = i, high = j;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		if (x[mid].first - start - SUM(i, mid - 1) >= h) high = mid;
		else low = mid;
	}
	return SUM(i, low) + h;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n; ++i) {
		cin >> x[i].first >> x[i].second;
	}

	sum[0] = x[0].second - x[0].first;
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + x[i].second - x[i].first;
	}

	int ans = 0, now;
	for (int i = 0; i < n; ++i) {
		now = x[i].second - x[i].first + binary(x[i].second, h, i + 1, n - 1);
		ans = max(now, ans);
	}
	cout << ans;
}
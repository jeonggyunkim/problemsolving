#include <bits/stdc++.h>
using namespace std;

long long arr[1010][1010];

int SQRT(long long n) {
	long long low = 0, high = 1e9 + 10;
	while (high - low != 1) {
		long long mid = (low + high) / 2;
		if (mid * mid <= n) low = mid;
		else high = mid;
	}
	return low;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	int ans;
	ans = SQRT((arr[0][1] * arr[0][2]) / arr[1][2]);
	cout << ans << ' ';

	for (int i = 1; i < n; ++i) {
		cout << arr[0][i] / ans << ' ';
	}
}
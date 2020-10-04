#include <iostream>
using namespace std;

long long c[51][51];

long long comb(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (c[n][k] > 0) return c[n][k];
	return c[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, sum = 0;
	int num[51];
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> num[i];
		sum += num[i];
	}

	int k;
	cin >> k;
	long long same = 0;
	for (int i = 0; i < m; ++i) {
		if (k <= num[i]) same += comb(num[i], k);
	}

	double ans = same;
	for (int i = 0; i < k; ++i) {
		ans /= (sum - i);
		ans *= (1 + i);
	}

	cout.precision(20);
	cout << ans;
}
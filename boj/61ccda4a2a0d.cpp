#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long c[50][50] = {};
	for (int i = 0; i < 50; ++i) for (int j = 0; j <= i; ++j) {
		if (i == j || j == 0) c[i][j] = 1;
		else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	int n, k;
	while (cin >> n >> k, n || k) {
		k = min(n - k, k);
		if (k <= 12) {
			long long t = 1;
			for (int i = 0; i < k; ++i) t *= (n - i);
			for (int i = 1; i <= k; ++i) t /= i;
			cout << t << '\n';
		}
		else cout << c[n][k] << endl;
	}
}
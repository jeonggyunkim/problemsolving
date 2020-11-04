#include <iostream>
using namespace std;

double x[2500], y[2500];
double prob[2501];

double tri(int i, int j, int k) {
	return abs(x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j])) / 2;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

	prob[n - 2] = k * (k - 1);
	prob[n - 2] /= n * (n - 1);
	for (int i = n - 3; i >= k - 2; --i) {
		prob[i] = prob[i + 1] / (i + 1);
		prob[i] *= (i + 3 - k);
	}

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		double area = 0;
		for (int j = (i + 2) % n; j != i; j = (j + 1) % n) {
			area += tri(i, j, (j + n - 1) % n);
			int cnt = j - i - 1;
			if (cnt < 0) cnt += n;
			cnt = n - 2 - cnt;
			if (cnt >= k - 2) ans -= area * prob[cnt];
		}
		if (!i) ans += area;
	}
	cout.precision(20);
	cout << fixed;
	cout << ans;
}
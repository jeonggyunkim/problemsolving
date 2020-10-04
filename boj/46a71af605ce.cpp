#include <iostream>
using namespace std;

int arr[12] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};

int c[20][20];

int comb(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (c[n][k] > 0) return c[n][k];
	return c[n][k] = comb(n - 1, k) + comb(n - 1, k - 1);
}

double power(double p, int q) {
	double ret = 1;
	for (int i = 0; i < q; ++i) ret *= p;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double p, q;
	cin >> p >> q;
	p /= 100; q /= 100;

	double a = 0, b = 0;
	for (int i = 0; i < 12; ++i) {
		a += power(p, arr[i]) * power(1 - p, 18 - arr[i]) * comb(18, arr[i]);
		b += power(q, arr[i]) * power(1 - q, 18 - arr[i]) * comb(18, arr[i]);
	}

	cout.precision(20);
	cout << 1 - a * b;
}
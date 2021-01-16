#include <iostream>
#include <cmath>
#define eps 1e-10
using namespace std;

int n;
int x[1000], y[1000];
double ex[8], ey[8];

bool intersect(double x_dot, double y_dot, double x1, double x2, double y1, double y2) {
	if (y1 < y_dot && y2 < y_dot) return 0;
	if (y1 > y_dot && y2 > y_dot) return 0;
	if (y1 > y2) {
		swap(y1, y2);
		swap(x1, x2);
	}
	double x_meet = x1 + (y_dot - y1) / (y2 - y1) * (x2 - x1);
	if (x_meet >= x_dot) return 1;
	else return 0;
}

bool inside(int i, int k) {
	int cnt = 0;
	for (int j = 0; j < k; ++j) {
		if (intersect(x[i] + eps, y[i] + eps, ex[j], ex[(j + 1) % k], ey[j], ey[(j + 1) % k])) cnt++;
	}
	if (cnt % 2) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	double large = -1;
	int ans;
	for (int k = 3; k <= 8; ++k) {
		double in = 0, out = 0;
		double low = 0, high = 1e8;
		for (int epoch = 0; epoch < 100; ++epoch) {
			double theta = 0, mid = (low + high) / 2;
			for (int i = 0; i < k; ++i) {
				ex[i] = cos(theta) * mid;
				ey[i] = sin(theta) * mid;
				theta += M_PI * 2 / k;
			}
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (!inside(i, k)) cnt++;
			}
			if (cnt == n) low = mid;
			else high = mid;
		}
		for (int i = 0; i < k; ++i) {
			in += ex[i] * ey[(i + 1) % k];
			in -= ex[(i + 1) % k] * ey[i];
		}
		in = abs(in) / 2;

		low = 0, high = 1e8;
		for (int epoch = 0; epoch < 100; ++epoch) {
			double theta = 0, mid = (low + high) / 2;
			for (int i = 0; i < k; ++i) {
				ex[i] = cos(theta) * mid;
				ey[i] = sin(theta) * mid;
				theta += M_PI * 2 / k;
			}
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (inside(i, k)) cnt++;
			}
			if (cnt == n) high = mid;
			else low = mid;
		}
		for (int i = 0; i < k; ++i) {
			out += ex[i] * ey[(i + 1) % k];
			out -= ex[(i + 1) % k] * ey[i];
		}
		out = abs(out) / 2;

		if (in / out > large) {
			large = in / out;
			ans = k;
		}
	}
	cout.precision(15);
	cout << ans << ' ' << large;
}
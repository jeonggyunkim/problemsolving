#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, y;

bool possible(double r) {
	double left = 1e15;
	double right = -1e15;
	for (int i = 0; i < n; ++i) {
		if (y[i] > 2 * r) {
			return 0;
		}
		double x_left = x[i] + sqrt(r * r - (r - y[i]) * (r - y[i]));
		double x_right = x[i] - sqrt(r * r - (r - y[i]) * (r - y[i]));
		left = min(left, x_left);
		right = max(right, x_right);
	}
	if (right > left) return 0;
	else return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	x.resize(n);
	y.resize(n);
	bool neg = 0, pos = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		if (y[i] < 0) neg = 1;
		else pos = 1;
	}
	if (neg && pos) {
		cout << -1;
		return 0;
	}
	if (neg) {
		for (int i = 0; i < n; ++i) y[i] = -y[i];
	}


	double low = 0, high = 1e15;
	for (int i = 0; i < 100; ++i) {
		double mid = (low  + high) / 2;
		if (possible(mid)) high = mid;
		else low = mid;
	}
	cout.precision(30);
	cout << high << '\n';
}
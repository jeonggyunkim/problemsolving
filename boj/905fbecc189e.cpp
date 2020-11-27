#include <iostream>
#include <set>
#include <cmath>
#define eps 1e-7
using namespace std;

int x[50], y[50], d[50];
double angle[50];

bool same(double a, double b) {
	while (a > b) a -= M_PI * 2;
	if (abs(a - b) < eps || abs(abs(a - b) - 2 * M_PI) < eps) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		if (x[i] == 0 && y[i] == 0) {
			n--;
			i--;
			if (n == 0) {
				cout << -1;
				return 0;
			}
			continue;
		}
		d[i] = x[i] * x[i] + y[i] * y[i];
		if (x[i] == 0) {
			if (y[i] > 0) angle[i] = M_PI_2;
			else angle[i] = -M_PI_2;
		}
		else {
			angle[i] = atan((double)y[i] / x[i]);
			if (x[i] < 0) angle[i] += M_PI;
		}
	}

	set<double> line;
	for (int i = 0; i < n; ++i) {
		if (d[0] != d[i]) continue;
		double l = (angle[0] + angle[i]) / 2;
		if (l > M_PI_2) l -= M_PI;
		bool in = 0;
		for (double t: line) {
			if (same(t, l)) in = 1;
		}
		if (in) continue;

		bool pos = 1;
		for (int j = 0; j < n; ++j) {
			double ref = 2 * l - angle[j];
			bool exist = 0;
			for (int k = 0; k < n; ++k) {
				if (same(ref, angle[k]) && d[k] == d[j]) exist = 1;
			}
			if (!exist) pos = 0;
		}
		if (pos) {
			line.insert(l);
		}
	}
	cout << line.size();
}
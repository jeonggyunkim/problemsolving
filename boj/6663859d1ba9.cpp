#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	int ans = (1 << 30);
	int ansx, ansy;
	for (int i = 0; i < n; ++i) {
		int maxd = -1;
		for (int j = 0; j < n; ++j) {
			maxd = max(maxd, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
		if (maxd < ans) {
			ans = maxd;
			ansx = x[i];
			ansy = y[i];
		}
	}

	cout << ansx << ' ' << ansy;
}
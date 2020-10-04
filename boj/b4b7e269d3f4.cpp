#include <iostream>
using namespace std;

double arr[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	double ans = arr[0], now = arr[0];
	for (int i = 1; i < n; ++i) {
		if (now >= 1) now *= arr[i];
		else now = arr[i];
		ans = max(ans, now);
	}
	cout.precision(3);
	cout << fixed;
	cout << ans;
}
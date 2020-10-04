#include <iostream>
using namespace std;

long long x[100000], y[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += x[i] * y[(i + 1) % n];
		ans -= x[i] * y[(i + n - 1) % n];
	}

	ans = abs(ans);
	cout << ans / 2;
	if (ans & 1) cout << ".5";
	else cout << ".0";
}
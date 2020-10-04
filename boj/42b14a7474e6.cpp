#include <iostream>
using namespace std;

int d[(1 << 21) + 100];

long long ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 2; i < (1 << (k + 1)); ++i) {
		cin >> d[i];
		ans += d[i];
	}

	for (int i = (1 << k) - 1; i >= 1; --i) {
		ans += abs(d[2 * i] - d[2 * i + 1]);
		d[i] += max(d[2 * i], d[2 * i + 1]);
	}

	cout << ans;
}
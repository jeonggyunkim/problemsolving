#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	double t;
	bool notzero = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (!notzero) ans += (int)(t + 0.6);
		else ans += (int)t;

		if (t) notzero = 1;
	}

	cout << ans;
}
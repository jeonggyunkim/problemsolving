#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> put(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		for (int i = 0; i < n; ++i) cin >> put[i];

		if (n == 1) {
			if (v[0] > put[0]) cout << v[0] - put[0] << '\n';
			else cout << 0 << '\n';
		}
		else {
			int t = gcd(v[0], v[1]);
			for (int i = 2; i < n; ++i) t = gcd(t, v[i]);

			int m = 0;
			for (int i = 0; i < n; ++i) {
				if (put[i] > v[i]) {
					int j = v[i] / t;
					m = max(m, (put[i] - v[i] + j - 1) / j);
				}
			}
			for (int i = 0; i < n; ++i) {
				v[i] += m * v[i] / t;
				cout << v[i] - put[i] << ' ';
			}
			cout << '\n';
		}
	}
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		vector<double> v(n + 2);
		v[0] = 1;

		for (int i = 0; i < m; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				v[j + 1] += v[j] * 0.25;
				v[j + 2] += v[j] * 0.75;
				v[j] = 0;
			}
		}

		cout.precision(12);
		cout << v[n] + v[n + 1] << '\n';
	}
}

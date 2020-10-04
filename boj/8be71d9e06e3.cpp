#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		bool reach[102] = {};
		int x[102], y[102];

		for (int i = 0; i < n + 2; ++i) cin >> x[i] >> y[i];

		reach[0] = 1;

		while (1) {
			bool cng = 0;
			for (int i = 0; i < n + 2; ++i) {
				if (reach[i]) continue;
				for (int j = 0; j < n + 2; ++j) {
					if (reach[j] && abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1000) {
						reach[i] = 1;
						cng = 1;
						break;
					}
				}
			}
			if (!cng) break;
		}

		if (reach[n + 1]) cout << "happy\n";
		else cout << "sad\n";
	}
}
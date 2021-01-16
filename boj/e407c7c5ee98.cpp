#include <iostream>
#include <vector>
using namespace std;

int cube[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> s(k);
	for (int i = 0; i < n; ++i) cin >> cube[i];
	for (int i = 0; i < k; ++i) {
		int sz, t;
		cin >> sz;
		while (sz--) {
			cin >> t;
			t--;
			s[i].push_back(t);
		}
	}

	int inc[k + 1] = {}, ans = 9999;
	while (1) {
		int now[10], sum = 0;
		for (int i = 0; i < n; ++i) now[i] = cube[i];

		for (int i = 0; i < k; ++i) {
			for (int u: s[i]) now[u] += (i + 1) * inc[i];
			sum += inc[i];
		}

		int pos = 1;
		for (int i = 1; i < n; ++i) {
			if (now[i] % 5 != now[0] % 5) pos = 0;
		}
		if (pos) ans = min(ans, sum);

		inc[0]++;
		for (int i = 0; i < k; ++i) {
			if (inc[i] == 5) {
				inc[i] = 0;
				inc[i + 1]++;
			}
		}
		if (inc[k]) break;
	}

	if (ans == 9999) cout << -1;
	else cout << ans;
}
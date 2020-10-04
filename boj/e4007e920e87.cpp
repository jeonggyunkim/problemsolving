#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s >> m;

	int v[1001];
	for (int i = 0; i < n; ++i) cin >> v[i];

	bool bit[1001] = {};
	bit[s] = 1;

	for (int i = 0; i < n; ++i) {
		bool temp[1001] = {};
		for (int j = 0; j <= m; ++j) if (bit[j]) {
			int t = j + v[i];
			if (0 <= t && t <= m) temp[t] = 1;
			t = j - v[i];
			if (0 <= t && t <= m) temp[t] = 1;
		}
		for (int j = 0; j <= m; ++j) bit[j] = temp[j];
	}

	int i = m;
	while (i >= 0) {
		if (bit[i]) {
			cout << i;
			return 0;
		}
		i--;
	}
	cout << -1;
}
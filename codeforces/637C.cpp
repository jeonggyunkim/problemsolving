#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int ans = 7;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cnt = 0;
			for (int k = 0; k < 6; ++k) {
				if (v[i][k] != v[j][k]) cnt++;
			}
			ans = min(ans, (cnt - 1) / 2);
		}
	}
	cout << ans;
}
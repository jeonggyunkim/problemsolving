#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int m, n;
		cin >> m >> n;

		vector<string> s(m + 2);
		for (int i = 0; i < m; ++i) {
			cin >> s[i];
			s[i].push_back('0');
			s[i].push_back('0');
		}
		for (int i = m; i < m + 2; ++i) {
			for (int j = 0; j < n + 2; ++j) s[i].push_back('0');
		}

		vector<ii> ans;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (s[i][j] == '1') {
					int mx = -1, mk;
					for (int k = -2; k <= 0; ++k) {
						if (j + k < 0) continue;
						int cnt = 0;
						for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) {
							if (s[i + p][j + k + q] == '1') cnt++;
						}
						if (mx < cnt) {
							mx = cnt;
							mk = k;
						}
					}
					ans.push_back(ii(i, j + mk));
					for (int p = 0; p < 3; ++p) for (int q = 0; q < 3; ++q) {
						s[i + p][j + mk + q] = '0';
					}
				}
			}
		}

		cout << "Case #" << test << '\n';
		cout << ans.size() << '\n';
		for (ii u: ans) {
			if (u.first >= m - 2) u.first = m - 3;
			if (u.second >= n - 2) u.second = n - 3;
			cout << u.first + 1 << ' ' << u.second + 1 << '\n';
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> row(n);
	vector<int> col(m);

	int ck1 = 0, ck2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> row[i];
		ck1 ^= row[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> col[i];
		ck2 ^= col[i];
	}

	if (ck1 != ck2) {
		cout << "NO";
		return 0;
	}

	vector<vector<int>> ans(n, vector<int>(m));

	for (int i = 0; i < 31; ++i) {
		vector<int> r, c;
		for (int j = 0; j < n; ++j) {
			if (row[j] & (1 << i)) r.push_back(j);
		}
		for (int j = 0; j < m; ++j) {
			if (col[j] & (1 << i)) c.push_back(j);
		}
		int a = 0, b = 0;
		while (a < r.size() && b < c.size()) {
			ans[r[a]][c[b]] |= (1 << i);
			a++; b++;
		}
		while (a < r.size()) {
			ans[r[a]][0] |= (1 << i);
			ans[r[a + 1]][0] |= (1 << i);
			a += 2;
		}
		while (b < c.size()) {
			ans[0][c[b]] |= (1 << i);
			ans[0][c[b + 1]] |= (1 << i);
			b += 2;
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}
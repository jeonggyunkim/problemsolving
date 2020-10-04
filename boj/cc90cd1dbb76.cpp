#include <iostream>
#include <set>
using namespace std;

set<int> s1, s2;

int now[12][12];
int board[12][12];

void f(int d, int n, int type) {
	if (type == 0) for (int i = 0; i < n; ++i) s1.insert(now[d][i]);
	else for (int i = 0; i < n; ++i) s2.insert(now[d][i]);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) now[d + 1][j] = 0;
		for (int j = i; j < n; ++j) {
			now[d + 1][j - i] |= now[d][j];
		}
		for (int j = i - 1; j >= 0; --j) {
			now[d + 1][i - 1 - j] |= now[d][j];
		}
		f(d + 1, max(i, n - i), type);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = -10000;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) now[0][i] = (1 << i);
	f(0, n, 0);
	for (int i = 0; i < m; ++i) now[0][i] = (1 << i);
	f(0, m, 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int a: s1) {
		int num[12] = {};
		for (int i = 0; i < n; ++i) {
			if (a & (1 << i)) {
				for (int j = 0; j < m; ++j) {
					num[j] += board[i][j];
				}
			}
		}
		for (int b: s2) {
			int loc = 0;
			for (int i = 0; i < m; ++i) {
				if (b & (1 << i)) loc += num[i];
			}
			ans = max(ans, loc);
		}
	}

	cout << ans;
}
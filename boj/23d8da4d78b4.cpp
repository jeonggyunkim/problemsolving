#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		int cnt = 0;
		for (int i = n - 1; i >= 1; --i) {
			if (m >= i) {
				cnt++;
				m -= i;
			}
			else break;
		}
		for (int i = 0; i < m; ++i) cout << cnt + 2 + i << ' ';
		cout << cnt + 1 << ' ';
		for (int i = m + 1; i < n - cnt; ++i) cout << cnt + 1 + i << ' ';
		for (int i = 0; i < cnt; ++i) cout << cnt - i << ' ';
		cout << '\n';
	}
}
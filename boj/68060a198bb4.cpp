#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int arr[10][10];

	while (1) {
		if (!(cin >> n)) return 0;
		cin >> m;

		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}

		int least = 10;
		int ans;
		int ansi, ansj;

		for (int i = 0; i <= n - m; ++i) for (int j = 0; j <= n - m; ++j) {
			int cnt = 0;
			for (int x = 0; x < m; ++x) for (int y = 0; y < m; ++y) {
				cnt |= (1 << arr[i + x][j + y]);
			}

			int num = 0;
			for (int x = 0; x < 10; ++x) if (cnt & (1 << x)) num++;

			if (num < least) {
				least = num;
				ans = cnt;
				ansi = i;
				ansj = j;
			}
			else if (num == least) {
				if (cnt > ans) {
					ans = cnt;
					ansi = i;
					ansj = j;
				}
			}
		}

		cout << ansi + 1 << ' ' << ansj + 1 << '\n';
	}
}

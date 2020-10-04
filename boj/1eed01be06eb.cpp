#include <iostream>
using namespace std;

int loc[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
char arr[752][752];
int d[1505][755];
int d2[1505][755];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, ans = 0;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) cin >> arr[i];

	for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) {
		if (arr[i - 1][j - 1] == '1') {
			d[i + j][i] = 1;
			d2[i - j + 750][i] = 1;
		}
	}

	for (int i = 0; i < 1505; ++i) for (int j = 1; j < 755; ++j) {
		d[i][j] += d[i][j - 1];
		d2[i][j] += d2[i][j - 1];
	}

	for (int size = 1; size <= r && size <= c; size += 2) {
		int sz = (size + 1) / 2;
		int t = sz - 1;
		for (int i = 1; i + size - 1 <= r; ++i) {
			for (int j = 1; j + size - 1 <= c; ++j) {
				int n = i + j + t;
				if (d[n][i + t] - d[n][i - 1] != sz) goto fail;
				n = i + j + 3 * t;
				if (d[n][i + 2 * t] - d[n][i + t - 1] != sz) goto fail;
				n = i - j - t + 750;
				if (d2[n][i + t] - d2[n][i - 1] != sz) goto fail;
				n = i - j + t + 750;
				if (d2[n][i + 2 * t] - d2[n][i + t - 1] != sz) goto fail;
				ans = sz;
				fail:;
			}
		}
	}
	cout << ans;
}
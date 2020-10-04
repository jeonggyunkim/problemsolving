#include <iostream>
#define SZ 50
#define DG 20
using namespace std;

int prod(int* a, int* b, int n) {
	for (int i = 0; i < SZ; ++i) b[i] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i + j] += a[i] * a[j];
		}
	}
	int ret = 0;
	for (int i = 0; i < SZ; ++i) {
		if (b[i] >= 10) {
			b[i + 1] += b[i] / 10;
			b[i] %= 10;
		}
		if (b[i]) ret = i;
	}
	return ret + 1;
}

void findSqrt(int n, int* a) {
	int i = 0;
	while (1) {
		if (i * i == n) {
			int j = 0;
			while (i) {
				a[DG + j++] = i % 10;
				i /= 10;
			}
			return;
		}
		else if (i * i > n) {
			i = i - 1;
			break;
		}
		i++;
	}

	int b[SZ];
	int len = 0, now;
	while (i) {
		a[len++] = i % 10;
		i /= 10;
	}

	for (int dec = 1; dec <= DG; ++dec) {
		for (int j = len + 2 * dec; j > 0; --j) a[j] = a[j - 1];
		for (int j = 0; j < 10; ++j) {
			a[0] = j;
			int sz = prod(a, b, len + dec);
			now = 0;
			for (int i = sz - 1; i >= 2 * dec; --i) {
				now *= 10;
				now += b[i];
			}
			if (now >= n) {
				a[0] = j - 1;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int x;
		cin >> x;

		int pos[5][3] = {};
		int arr[4][SZ] = {};
		for (int i = 1; i <= 4; ++i) {
			int sq = 0;
			for (int j = 0; j < 3; ++j) {
				cin >> pos[i][j];
				sq += (pos[i][j] - pos[i - 1][j]) * (pos[i][j] - pos[i - 1][j]);
			}
			findSqrt(sq, arr[i - 1]);
		}

		int ans[SZ] = {}, comp[SZ] = {};
		for (int i = 0; i < DG + 7; ++i) {
			for (int j = 0; j < 4; ++j) {
				ans[i] += arr[j][i];
			}
			if (ans[i] >= 10) {
				ans[i + 1] += ans[i] / 10;
				ans[i] %= 10;
			}
		}
		int j = DG;
		while (x) {
			comp[j++] = x % 10;
			x /= 10;
		}
		for (int i = DG + 7; i >= 0; --i) {
			if (comp[i] != ans[i]) {
				if (comp[i] > ans[i]) cout << "YES\n";
				else cout << "NO\n";
				goto end;
			}
		}
		cout << "YES\n";
		end:;
	}
}
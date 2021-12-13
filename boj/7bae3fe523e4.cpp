#include <iostream>
#include <memory.h>
using namespace std;

int n;
char board[301][301];
char trans[310][310];
int sum[311][311];
long long ans;

void diag() {
	for (int i = 0; i < n; ++i) {
		sum[i][0] = 0;
		for (int j = 0; j < n; ++j) {
			sum[i][j + 1] = sum[i][j] + trans[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (trans[i][j] == 0) continue;
			for (int k = j + 1; k < n; ++k) {
				if (trans[i][k] == 0) continue;
				int len = k - j;
				if (i + len < n) ans += sum[i + len][k + 1] - sum[i + len][j];
				if (i - len >= 0) ans += sum[i - len][k + 1] - sum[i - len][j];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		sum[0][i] = 0;
		for (int j = 0; j < n; ++j) {
			sum[j + 1][i] = sum[j][i] + trans[j][i];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (trans[j][i] == 0) continue;
			for (int k = j + 1; k < n; ++k) {
				if (trans[k][i] == 0) continue;
				int len = k - j;
				if (i + len < n) {
					ans += sum[k + 1][i + len] - sum[j][i + len];
					if (trans[j][i + len]) ans--;
					if (trans[k][i + len]) ans--;
				}
				if (i - len >= 0) {
					ans += sum[k + 1][i - len] - sum[j][i - len];
					if (trans[j][i - len]) ans--;
					if (trans[k][i - len]) ans--;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> board[i];

	memset(trans, 0, sizeof(trans));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] == '*') {
					trans[(i - j + n) / 2][(i + j) / 2] = 1;
				}
			}
		}
	}
	diag();

	memset(trans, 0, sizeof(trans));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2 == 1) {
				if (board[i][j] == '*') {
					trans[(i - j + n) / 2][(i + j) / 2] = 1;
				}
			}
		}
	}
	diag();

	cout << ans;
}
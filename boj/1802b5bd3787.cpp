#include <iostream>
#include <vector>
#include <memory.h>
#define MOD 1000000007
using namespace std;

long long a[128][128];
long long b[128][128];
long long mat[128][128];

void matmul(int n, int p) {
	for (int i = 0; n; ++i) {
		if (n & (1 << i)) {
			for (int x = 0; x < p; ++x) {
				for (int y = 0; y < p; ++y) {
					b[x][y] = 0;
					for (int z = 0; z < p; ++z) {
						(b[x][y] += mat[x][z] * a[z][y]) %= MOD;
					}
				}
			}
			memcpy(mat, b, sizeof(b));
			n ^= (1 << i);
		}
		for (int x = 0; x < p; ++x) {
			for (int y = 0; y < p; ++y) {
				b[x][y] = 0;
				for (int z = 0; z < p; ++z) {
					(b[x][y] += a[x][z] * a[z][y]) %= MOD;
				}
			}
		}
		memcpy(a, b, sizeof(b));
	}
}

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	if (x == 1) {
		vector<vector<int>> white(m, vector<int>(y, 0));
		vector<vector<int>> black(m, vector<int>(y, 0));
		white[0][1] = 1;
		black[0][1] = 1;

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < y; ++j) {
				if (j < y - 1) (white[i][j + 1] += white[i - 1][j]) %= MOD;
				(white[i][1] += black[i - 1][j]) %= MOD;
				if (j < y - 1) (black[i][j + 1] += black[i - 1][j]) %= MOD;
				(black[i][1] += white[i - 1][j]) %= MOD;
			}
		}

		int line = 0;
		for (int i = 1; i < y; ++i) {
			(line += white[m - 1][i]) %= MOD;
			(line += black[m - 1][i]) %= MOD;
		}
		long long ans = 1;
		for (int i = 0; i < n; ++i) {
			(ans *= line) %= MOD;
		}
		cout << ans;
	}
	else if (x == 2) {
		for (int i = 0; i < (1 << m); ++i) {
			mat[i][i] = 1;
		}

		for (int i = 0; i < (1 << m); ++i) {
			for (int j = 0; j < (1 << m); ++j) {
				bool pos = 1;
				for (int k = 0; k < m - y + 1; ++k) {
					bool color = (i & (1 << k));
					bool same = 1;
					for (int l = 0; l < y; ++l) {
						if ((bool)(i & (1 << (k + l))) != color) same = 0;
						if ((bool)(j & (1 << (k + l))) != color) same = 0;
					}
					if (same) pos = 0;
				}
				if (pos) a[i][j] = 1;
			}
		}

		matmul(n - 1, 1 << m);
		long long ans = 0;
		for (int i = 0; i < (1 << m); ++i) {
			for (int j = 0; j < (1 << m); ++j) {
				(ans += mat[i][j]) %= MOD;
			}
		}
		cout << ans;
	}
	else {
		vector<vector<int>> dp(n - 1, vector<int>(1 << (m * 2), 0));
		for (int i = 0; i < (1 << (m * 2)); ++i) dp[0][i] = 1;
		for (int rep = 0; rep < n - 2; ++rep) {
			for (int i = 0; i < (1 << (m * 2)); ++i) {
				for (int j = 0; j < (1 << m); ++j) {
					bool pos = 1;
					for (int k = 0; k < m - y + 1; ++k) {
						bool color = (i & (1 << k));
						bool same = 1;
						for (int l = 0; l < y; ++l) {
							if ((bool)(i & (1 << (k + l))) != color) same = 0;
							if ((bool)(i & (1 << (m + k + l))) != color) same = 0;
							if ((bool)(j & (1 << (k + l))) != color) same = 0;
						}
						if (same) pos = 0;
					}
					if (pos) (dp[rep + 1][((i << m) | j) & ((1 << (2 * m)) - 1)] += dp[rep][i]) %= MOD;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << (m * 2)); ++i) {
			(ans += dp[n - 2][i]) %= MOD;
		}
		cout << ans;
	}
}
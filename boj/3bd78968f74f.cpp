#include <iostream>
using namespace std;

int cnt[257][257][257];
int r[100010], g[100010], b[100010];
int N, K;
int ans = 987654321;
int ansx, ansy, ansz;

int boxCnt(int x1, int y1, int z1, int x2, int y2, int z2) {
	int ret = cnt[x2][y2][z2];
	ret -= cnt[x1 - 1][y2][z2] + cnt[x2][y1 - 1][z2] + cnt[x2][y2][z1 - 1];
	ret += cnt[x2][y1 - 1][z1 - 1] + cnt[x1 - 1][y2][z1 - 1] + cnt[x1 - 1][y1 - 1][z2];
	ret -= cnt[x1 - 1][y1 - 1][z1 - 1];
	return ret;
}

int center(int i, int j, int k) {
	int low = 0, high = 256;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int x = i + mid > 256 ? 256 : i + mid;
		int y = j + mid > 256 ? 256 : j + mid;
		int z = k + mid > 256 ? 256 : k + mid;
		if (boxCnt(i, j, k, x, y, z) >= K) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> r[i] >> g[i] >> b[i];
		r[i]++; g[i]++; b[i]++;
		cnt[r[i]][g[i]][b[i]]++;
	}

	for (int i = 1; i <= 256; ++i)
	for (int j = 1; j <= 256; ++j)
	for (int k = 1; k <= 256; ++k) {
		if (cnt[i][j][k] >= K) {
			cout << 0 << '\n';
			while (K--) {
				cout << i - 1 << ' ' << j - 1 << ' ' << k - 1 << '\n';
			}
			return 0;
		}
		int now = cnt[i - 1][j][k] + cnt[i][j - 1][k] + cnt[i][j][k - 1];
		now -= cnt[i - 1][j - 1][k] + cnt[i][j - 1][k - 1] + cnt[i - 1][j][k - 1];
		now += cnt[i - 1][j - 1][k - 1];
		cnt[i][j][k] += now;
	}

	for (int i = 1; i <= 256; ++i)
	for (int j = 1; j <= 256; ++j)
	for (int k = 1; k <= 256; ++k) {
		int d = center(i, j, k);
		if (d < ans) {
			ans = d;
			ansx = i, ansy = j, ansz = k;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < N; ++i) {
		if (r[i] < ansx || r[i] > ansx + ans) continue;
		if (g[i] < ansy || g[i] > ansy + ans) continue;
		if (b[i] < ansz || b[i] > ansz + ans) continue;
		cout << r[i] - 1 << ' ' << g[i] - 1 << ' ' << b[i] - 1 << '\n';
		if (--K == 0) break;
	}
}
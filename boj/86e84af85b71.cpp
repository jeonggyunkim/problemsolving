#include <iostream>
#include <memory.h>
using namespace std;

int STR[1010][1010], INT[1010][1010], PNT[1010][1010], cnt[1010][1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int S, I, P;
	int oneone = 0;
	for (int i = 0; i < n; ++i) {
		cin >> S >> I >> P;
		cnt[I][S]++;
		PNT[I][S] += P;
		if (S == 1 || I == 1) oneone += P;
	}

	for (int i = 1000; i >= 1; --i) {
		for (int j = 1000; j >= 1; --j) {
			STR[i][j] = STR[i + 1][j] + PNT[i][j];
			INT[i][j] = INT[i][j + 1] + PNT[i][j];
			cnt[i][j] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1] + cnt[i][j];
		}
	}

	memset(PNT, -1, sizeof(PNT));
	PNT[1][1] = oneone;

	int ans = 0;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (PNT[i][j - 1] > 0) PNT[i][j] = max(PNT[i][j], PNT[i][j - 1] - 1 + STR[i + 1][j]);
			if (PNT[i - 1][j] > 0) PNT[i][j] = max(PNT[i][j], PNT[i - 1][j] - 1 + INT[i][j + 1]);
			if (PNT[i][j] != -1) ans = max(ans, n - cnt[i + 1][j + 1]);
		}
	}

	cout << ans;
}
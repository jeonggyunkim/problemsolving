#include <iostream>
using namespace std;

int sum[1002][1002];
int diff[1002][1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;

	int a, b, c, d;
	while (n--) {
		cin >> a >> b >> c >> d;
		a++; b++; c++; d++;
		diff[a][b]++;
		diff[a][d]--;
		diff[c][b]--;
		diff[c][d]++;
	}

	for (int i = 1; i < 1002; ++i) {
		int p = 0;
		for (int j = 0; j < 1002; ++j) {
			p += diff[i][j];
			sum[i][j] = sum[i - 1][j] + p;
		}
	}

	for (int i = 0; i < 1002; ++i) {
		for (int j = 0; j < 1002; ++j) {
			if (sum[i][j] == k) ans++;
		}
	}
	cout << ans;
}
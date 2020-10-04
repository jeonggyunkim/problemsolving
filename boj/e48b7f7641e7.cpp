#include <iostream>
#include <memory.h>
using namespace std;

int cnt;
int value[1000][2];
int dp[1000][16][16];

int get(int i, int b, int w) {
	if (b < 0 || w < 0 || b + w > cnt - i) return 0;
	if (dp[i][b][w] != -1) return dp[i][b][w];
	if (b == 0 && w == 0) return dp[i][b][w] = 0;
	int r1 = get(i + 1, b, w), r2, r3;
	if (b > 0) r2 = get(i + 1, b - 1, w) + value[i][0];
	else r2 = 0;
	if (w > 0) r3 = get(i + 1, b, w - 1) + value[i][1];
	else r3 = 0;
	return dp[i][b][w] = max(r1, max(r2, r3));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> value[cnt][0]) {
		cin >> value[cnt][1];
		cnt++;
	}

	memset(dp, -1, sizeof(dp));
	cout << get(0, 15, 15);
}
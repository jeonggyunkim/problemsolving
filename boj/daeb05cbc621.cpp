#include <iostream>
#define LOW (1 << 31)
using namespace std;

int n, m, arr[101];
int ms[101][101];
int dp[101][101];

int maxseg(int i, int j) {
	if (ms[i][j] != LOW) return ms[i][j];
	bool allneg = true;
	int maxnum = LOW, sum = 0, max = 0;
	for (int ind = i; ind < j; ++ind) {
		if (arr[ind] >= 0) allneg = false;
		if (maxnum < arr[ind]) maxnum = arr[ind];
		sum += arr[ind];
		max = max > sum ? max : sum;
		if (sum < 0) sum = 0;
	}
	if (allneg) return ms[i][j] = maxnum;
	else return ms[i][j] = max;
}

int maxsum(int i, int j) {
	if (dp[i][j] != LOW) return dp[i][j];
	if (j == 1) return dp[i][j] = maxseg(i, n);
	int max = LOW;
	for (int ind = i + 2; ind < n - 2 * j + 4; ++ind) {
		int t = maxseg(i, ind - 1) + maxsum(ind, j - 1);
		if (t > max) max = t;
	}
	return dp[i][j] = max;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < 101; ++i) for (int j = 0; j < 101; ++j) {
		ms[i][j] = LOW;
		dp[i][j] = LOW;
	}
	for (int i = 0; i < n; ++i) cin >> arr[i];

	cout << maxsum(0, m);
}
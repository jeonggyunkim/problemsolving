#include <iostream>
#include <memory.h>
using namespace std;

int dp[55][55][110];
int score[55];

int get(int n, int cnt, int sum) {
	if (cnt == 0 && sum == 0) return 0;
	if (n == 0) return -2;
	if (dp[n][cnt][sum] != -1) {
		return dp[n][cnt][sum];
	}
	int ret = -2;
	for (int i = 0; sum - n * i >= 0 && cnt - i >= 0; ++i) {
		int rec = get(n - 1, cnt - i, sum - n * i);
		if (rec != -2) ret = max(ret, rec + score[n] * i);
	}
	return dp[n][cnt][sum] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;
	
	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < n; ++i) cin >> score[i];
	cout << get(n - 1, n, 2 * n - 2);
}

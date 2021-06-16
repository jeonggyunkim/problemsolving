#include <iostream>
#include <memory.h>
#define N 100
using namespace std;

int n;
int arr[N][2];
int dp[N][N];

int get(int a, int b) {
	if (b <= a) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i][0] == a && arr[i][1] == b) c++;
	}
	int ret = 0;
	if (c) {
		ret = 1;
		for (int i = a + 1; i < b; ++i) {
			ret = max(ret, get(a + 1, i - 1) + get(i, b - 1) + 1);
		}
	}
	else {
		for (int i = a; i < b; ++i) {
			ret = max(ret, get(a, i) + get(i + 1, b));
		}
	}
	return dp[a][b] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i][0] >> arr[i][1];
		arr[i][0]--; arr[i][1]--;
		if (arr[i][0] > arr[i][1]) swap(arr[i][0], arr[i][1]);
	}

	cout << get(0, N - 1);
}
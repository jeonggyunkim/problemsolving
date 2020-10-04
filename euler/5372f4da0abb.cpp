#include <iostream>
#include <memory.h>
using namespace std;

int value[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[8][201];

int make(int c, int n) {
	if (dp[c][n] != -1) return dp[c][n];
	if (c == 0) return dp[c][n] = 1;
	int ret = 0;
	while (n >= 0) {
		ret += make(c - 1, n);
		n -= value[c];
	}
	return dp[c][n] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << make(7, 200) << endl;
}
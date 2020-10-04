#include <iostream>
using namespace std;

char dp[101][101];

int turn(int a, int b) {
	if (dp[a][b]) return dp[a][b];

	if (a == 2 || b == 2) return dp[a][b] = 1;

	if (a > 1) {
		for (int i = 1; i < a; ++i) {
			if (turn(i, a - i) == -1) return dp[a][b] = 1;
		}
	}
	if (b > 1) {
		for (int i = 1; i < b; ++i) {
			if (turn(i, b - i) == -1) return dp[a][b] = 1;
		}
	}
	return dp[a][b] = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	if (turn(n, m) == 1) cout << 'A';
	else cout << 'B';
}
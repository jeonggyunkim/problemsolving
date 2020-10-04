#include <iostream>
#include <memory.h>
using namespace std;

char dp[1001][1001][2];

int game(int a, int b, int turn) {
	if (dp[a][b][turn] != -1) return dp[a][b][turn];
	int t;
	if (a > 0) {
		t = game(a - 1, b, 1 - turn);
		if (t == turn) return dp[a][b][turn] = turn;
	}
	if (b > 0) {
		t = game(a, b - 1, 1 - turn);
		if (t == turn) return dp[a][b][turn] = turn;
	}
	if (a > 2 && b > 0) {
		t = game(a - 3, b - 1, 1 - turn);
		if (t == turn) return dp[a][b][turn] = turn;
	}
	if (a > 0 && b > 2) {
		t = game(a - 1, b - 3, 1 - turn);
		if (t == turn) return dp[a][b][turn] = turn;
	}
	return dp[a][b][turn] = 1 - turn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 1;
	dp[0][0][1] = 0;
	int a, b;
	cin >> a >> b;

	if (game(a, b, 0) == 0) cout << "Alice";
	else cout << "Bob";
}
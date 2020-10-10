#include <iostream>
using namespace std;

int n, m;
int board[10][10];
bool choose[10][10];
int ans = -99999, sum;

void rec(int i, int j, int k) {
	if (k == 0) {
		ans = max(ans, sum);
		return;
	}
	if (i >= n) return;
	if ((!i || !choose[i - 1][j]) && (!j || !choose[i][j - 1])) {
		sum += board[i][j];
		choose[i][j] = 1;
		if (j == m - 1) rec(i + 1, 0, k - 1);
		else rec(i, j + 1, k - 1);
		choose[i][j] = 0;
		sum -= board[i][j];
	}
	if (j == m - 1) rec(i + 1, 0, k);
	else rec(i, j + 1, k);
}

int main() {
	int k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> board[i][j];
	}

	rec(0, 0, k);
	cout << ans;
}
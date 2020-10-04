#include <iostream>
using namespace std;

int ans, sum;
int n, m;

int num[510][510];
bool used[510][510];

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void rec(int i, int j, int left) {
	if (left == 0) {
		ans = max(ans, sum);
		return;
	}
	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];

		if (x <= 0 || x > n || y <= 0 || y > m) continue;
		if (!used[x][y]) {
			used[x][y] = 1;
			sum += num[x][y];
			rec(x, y, left - 1);
			sum -= num[x][y];
			used[x][y] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> num[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			rec(i, j, 4);
			int mini = 9876, sum = num[i][j];
			for (int k = 0; k < 4; ++k) {
				sum += num[i + loc[k][0]][j + loc[k][1]];
				mini = min(mini, num[i + loc[k][0]][j + loc[k][1]]);
			}
			ans = max(ans, sum - mini);
		}
	}

	cout << ans;
}
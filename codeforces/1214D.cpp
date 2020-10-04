#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> map(n);
	vector<vector<int>> board(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}

	queue<ii> q;
	q.push({0, 0});
	board[0][0] = 1;

	while (!q.empty()) {
		ii now = q.front();
		q.pop();

		int i = now.first, j = now.second;

		if (i != n - 1 && map[i + 1][j] == '.' && board[i + 1][j] == 0) {
			board[i + 1][j] = 1;
			q.push({i + 1, j});
		}
		if (j != m - 1 && map[i][j + 1] == '.' && board[i][j + 1] == 0) {
			board[i][j + 1] = 1;
			q.push({i, j + 1});
		}
	}
	
	q.push({n - 1, m - 1});
	board[n - 1][m - 1] += 2;

	while (!q.empty()) {
		ii now = q.front();
		q.pop();

		int i = now.first, j = now.second;
		if (i && map[i - 1][j] == '.' && board[i - 1][j] < 2) {
			board[i - 1][j] += 2;
			q.push({i - 1, j});
		}
		if (j && map[i][j - 1] == '.' && board[i][j - 1] < 2) {
			board[i][j - 1] += 2;
			q.push({i, j - 1});
		}
	}

	vector<int> cnt(n + m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 3) {
				cnt[i + j]++;
			}
		}
	}

	int ans = 2;
	for (int i = 1; i < n + m - 2; ++i) {
		ans = min(ans, cnt[i]);
	}

	cout << ans;
}

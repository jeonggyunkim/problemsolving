#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector< vector<int> > arr(n, vector<int>(n));
	vector<int> loc;
	int virus = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> arr[i][j];
		if (arr[i][j] == 2) {
			virus++;
			loc.push_back(i * 100 + j);
		}
	}

	int ans = 10000;
	vector<int> per(virus, 0);
	for (int i = 0; i < m; ++i) per[i] = 1;
	do {
		vector<vector<int> > temp = arr;
		queue<ii> q;
		for (int i = 0; i < virus; ++i) if (per[i]) {
			q.push(ii(loc[i], 0));
			temp[loc[i] / 100][loc[i] % 100] = 3;
		}

		int now = 0;
		while (!q.empty()) {
			ii u = q.front();
			q.pop();
			int d = u.second;
			for (int k = 0; k < 4; ++k) {
				int x = u.first / 100 + pos[k][0];
				int y = u.first % 100 + pos[k][1];
				if (x < 0 || y < 0 || x >= n || y >= n) continue;
				if (temp[x][y] == 0) {
					now = max(now, d + 1);
					temp[x][y] = 3;
					q.push(ii(x * 100 + y, d + 1));
				}
				else if (temp[x][y] == 2) {
					temp[x][y] = 3;
					q.push(ii(x * 100 + y, d + 1));
				}
			}
		}
		bool b = 1;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (temp[i][j] == 0) b = 0;
		}
		if (b) ans = min(ans, now);
	} while (prev_permutation(per.begin(), per.end()));
	if (ans == 10000) cout << -1;
	else cout << ans;
}
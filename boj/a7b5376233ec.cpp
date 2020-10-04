#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int arr[20][20];
int n, sz = 2, eat = 0;
int nowx, nowy;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs() {
	int dist[20][20];
	memset(dist, -1, sizeof(dist));

	queue<ii> q;
	q.push({nowx, nowy});
	dist[nowx][nowy] = 0;

	while (!q.empty()) {
		ii now = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int x = now.first + loc[k][0];
			int y = now.second + loc[k][1];

			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (dist[x][y] == -1 && arr[x][y] <= sz) {
				dist[x][y] = dist[now.first][now.second] + 1;
				q.push({x, y});
			}
		}
	}

	int mini = 98765;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (arr[i][j] != 0 && arr[i][j] < sz && dist[i][j] != -1) {
			if (dist[i][j] < mini) {
				nowx = i; nowy = j;
				mini = dist[i][j];
			}
		}
	}

	if (mini != 98765) {
		arr[nowx][nowy] = 0;
		eat += 1;
		if (eat == sz) {
			eat = 0;
			sz++;
		}
		return mini;
	}
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> arr[i][j];
		if (arr[i][j] == 9) {
			nowx = i; nowy = j;
			arr[i][j] = 0;
		}
	}

	int ans = 0;
	while (1) {
		int t = bfs();
		if (t == 0) break;
		ans += t;
	}
	cout << ans;
}
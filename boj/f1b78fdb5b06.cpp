#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char arr[50][50];
ii dist[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	priority_queue<i4, vector<i4>, greater<i4>> pq;
	int ansx, ansy;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (arr[i][j] == 'S') {
			pq.push({{0, 0}, {i, j}});
			dist[i][j] = {0, 0};
		}
		else {
			dist[i][j] = {INF, INF};
			if (arr[i][j] == 'F') {
				ansx = i;
				ansy = j;
			}
		}
	}

	while (!pq.empty()) {
		i4 now = pq.top(); pq.pop();
		ii nowd = now.first;
		int x = now.second.first, y = now.second.second;

		if (nowd > dist[x][y]) continue;
		
		for (int k = 0; k < 4; ++k) {
			int xx = x + loc[k][0];
			int yy = y + loc[k][1];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

			ii next = nowd;
			if (arr[xx][yy] == 'g') next.first++;
			else if (arr[xx][yy] == '.') {
				for (int l = 0; l < 4; ++l) {
					int xxx = xx + loc[l][0];
					int yyy = yy + loc[l][1];
					if (xxx < 0 || xxx >= n || yyy < 0 || yyy >= m) continue;
					if (arr[xxx][yyy] == 'g') {
						next.second++;
						break;
					}
				}
			}

			if (next < dist[xx][yy]) {
				pq.push({next, {xx, yy}});
				dist[xx][yy] = next;
			}
		}
	}
	cout << dist[ansx][ansy].first << ' ' << dist[ansx][ansy].second;
}
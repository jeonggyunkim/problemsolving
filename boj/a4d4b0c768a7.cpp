#include <iostream>
#include <vector>
#define INF 987654321
#define H(a) ((a) >= 'a' ? 26 + (a) - 'a' : (a) - 'A')
using namespace std;

char board[26][26];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	int n, m, t, d;
	cin >> n >> m >> t >> d;

	int N = n * m;
	vector<vector<int>> dist(N, vector<int>(N, INF));

	for (int i = 0; i < n; ++i) cin >> board[i];

	for (int i = 0; i < N; ++i) dist[i][i] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 4; ++k) {
				int x = i + loc[k][0];
				int y = j + loc[k][1];
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				int diff = abs(H(board[i][j]) - H(board[x][y]));
				if (diff > t) continue;
				if (H(board[i][j]) >= H(board[x][y])) {
					dist[i * m + j][x * m + y] = 1;
				}
				else {
					dist[i * m + j][x * m + y] = diff * diff;
				}
			}
		}
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < N; ++i) {
		if (dist[0][i] + dist[i][0] <= d) ans = max(ans, H(board[i / m][i % m]));
	}
	cout << ans;
}
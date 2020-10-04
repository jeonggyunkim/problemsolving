#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

char map[101][101];
int room[101][101] = {0};
int status[101][101] = {0};

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%s", map + i);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		room[i][j] = -1;
		status[i][j] = -1;
	}
	if (m == 1 && n == 1) {
		printf("0\n");
		return 0;
	}

	queue<ii> next;
	next.push(ii(0,0));
	int depth = 0;
	while (room[n - 1][m - 1] == -1) {
		queue<ii> q(next);
		while (!next.empty()) next.pop();
		while (!q.empty()) {
			ii t = q.front(); q.pop();
			int i = t.first, j = t.second;
			status[i][j] = depth;
			bool comp = true;
			if (i > 0 && status[i - 1][j] < depth) {
				if (map[i - 1][j] == '1') { next.push(ii(i - 1, j)); status[i - 1][j] = depth; room[i - 1][j] = depth + 1; }
				else { q.push(ii(i - 1, j)); status[i - 1][j] = depth; room[i - 1][j] = depth; }
				comp = false;
			}
			if (i < n - 1 && status[i + 1][j] < depth) {
				if (map[i + 1][j] == '1') { next.push(ii(i + 1, j)); status[i + 1][j] = depth; room[i + 1][j] = depth + 1; }
				else { q.push(ii(i + 1, j)); status[i + 1][j] = depth; room[i + 1][j] = depth; }
				comp = false;
			}
			if (j > 0 && status[i][j - 1] < depth) {
				if (map[i][j - 1] == '1') { next.push(ii(i, j - 1)); status[i][j - 1] = depth; room[i][j - 1] = depth + 1; }
				else { q.push(ii(i, j - 1)); status[i][j - 1] = depth; room[i][j - 1] = depth; }
				comp = false;
			}
			if (j < m - 1 && status[i][j + 1] < depth) {
				if (map[i][j + 1] == '1') { next.push(ii(i, j + 1)); status[i][j + 1] = depth; room[i][j + 1] = depth + 1; }
				else { q.push(ii(i, j + 1)); status[i][j + 1] = depth; room[i][j + 1] = depth; }
				comp = false;
			}
			if (comp) status[i][j] = 100000;
		}
		depth++;
	}
	printf("%d\n", room[n - 1][m - 1]);
}

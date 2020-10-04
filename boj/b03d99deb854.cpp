#include <iostream>
#include <queue>
using namespace std;

int main() {
	char maze[100][100];
	int depth[100][100];

	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) scanf("%s", maze[i]);

	int d = 1;
	maze[0][0] = '0';
	depth[0][0] = 1;
	queue<int> q;
	q.push(0);
	int i, j, u;
	while (q.empty() == false) {
		u = q.front();
		q.pop();
		i = u / 100;
		j = u % 100;
		if (i > 0 && maze[i - 1][j] == '1') {
			maze[i - 1][j] = '0';
			depth[i - 1][j] = depth[i][j] + 1;
			q.push((i - 1) * 100 + j);
		}
		if (i < 99 && maze[i + 1][j] == '1') {
			maze[i + 1][j] = '0';
			depth[i + 1][j] = depth[i][j] + 1;
			q.push((i + 1) * 100 + j);
		}
		if (j > 0 && maze[i][j - 1] == '1') {
			maze[i][j - 1] = '0';
			depth[i][j - 1] = depth[i][j] + 1;
			q.push(i * 100 + j - 1);
		}
		if (j < 99 && maze[i][j + 1] == '1') {
			maze[i][j + 1] = '0';
			depth[i][j + 1] = depth[i][j] + 1;
			q.push(i * 100 + j + 1);
		}
	}

	printf("%d\n", depth[N - 1][M - 1]);

	return 0;
}
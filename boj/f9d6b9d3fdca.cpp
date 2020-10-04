#include <iostream>
#include <queue>
using namespace std;

void turn(int* x, int* y, char d) {
	int dir;
	if (d == 'L') dir = 1;
	else dir = -1;

	if (*y == 0) {
		*y = -(*x) * dir;
		*x = 0;
	}
	else {
		*x = *y * dir;
		*y = 0;
	}
}

int main() {
	int N, K, L;
	int board[101][101] = {};

	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 2;
	}
	cin >> L;

	int dir_time[100];
	char dir[100];
	for (int i = 0; i < L; ++i) {
		cin >> dir_time[i] >> dir[i];
	}

	queue<int> q;
	int x = 1, y = 1;
	board[y][x] = 1;
	q.push(x * 101 + y);
	int dx = 1, dy = 0;
	int time = 0;
	int dir_ind = 0;

	while (true) {
		time++;
		x += dx;
		y += dy;
		if (x <= 0 || x > N || y <= 0 || y > N)
			break;
		if (board[y][x] == 0) {
			int t = q.front();
			q.pop();
			board[t % 101][t / 101] = 0;
		}
		if (board[y][x] == 1) break;
		q.push(x * 101 + y);
		board[y][x] = 1;
		if (time == dir_time[dir_ind]) {
			turn(&dx, &dy, dir[dir_ind]);
			dir_ind++;
		}
	}
	cout << time << endl;

	return 0;
}
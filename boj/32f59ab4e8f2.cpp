#include <iostream>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int robot[101][3];
int map[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int n, m;
	cin >> n >> m;

	int x, y;
	char d;
	for (int i = 1; i <= n; ++i) {
		cin >> x >> y >> d;
		map[x][y] = i;
		robot[i][0] = x;
		robot[i][1] = y;
		if (d == 'N') robot[i][2] = 0;
		if (d == 'E') robot[i][2] = 1;
		if (d == 'W') robot[i][2] = 3;
		if (d == 'S') robot[i][2] = 2;
	}

	while (m--) {
		cin >> x >> d >> y;
		if (d == 'L') {
			while (y--) robot[x][2] = (robot[x][2] + 3) % 4;
		}
		else if (d == 'R') {
			while (y--) robot[x][2] = (robot[x][2] + 1) % 4;
		}
		else {
			int nowx = robot[x][0];
			int nowy = robot[x][1];
			while (y--) {
				map[nowx][nowy] = 0;
				nowx += dir[robot[x][2]][0];
				nowy += dir[robot[x][2]][1];
				if (nowx <= 0 || nowx > a || nowy <= 0 || nowy > b) {
					cout << "Robot " << x << " crashes into the wall";
					return 0;
				}
				if (map[nowx][nowy]) {
					cout << "Robot " << x << " crashes into robot " << map[nowx][nowy];
					return 0;
				}
			}
			robot[x][0] = nowx;
			robot[x][1] = nowy;
			map[nowx][nowy] = x;
		}
	}
	cout << "OK";
}
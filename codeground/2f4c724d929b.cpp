#include <bits/stdc++.h>
using namespace std;

int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, -1, 0, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int x = 0, y = 0, dir = 0;
		int n, ans = 0;
		char board[1000][1000];
		bool used[1000][1000] = {};
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> board[i];
		
		while (true) {
			if (x < 0 || x >= n || y < 0 || y >= n) break;
			if (board[y][x] != '0') {
				if (!used[y][x]) {
					ans++;
					used[y][x] = 1;
				}
				if (board[y][x] == '1') {
					if (dir < 2) dir = 1 - dir;
					else dir = 5 - dir;
				}
				else dir = 3 - dir;
			}
			x += dir_x[dir];
			y += dir_y[dir];
		}
		
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
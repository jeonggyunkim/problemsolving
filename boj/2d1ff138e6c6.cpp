#include <iostream>
using namespace std;

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string s;
		cin >> s;

		int min_x, max_x, min_y, max_y, x, y, d;
		min_x = max_x = min_y = max_y = 0;
		x = y = d = 0;
		for (char u: s) {
			if (u == 'F') {
				x += dir[d][0];
				y += dir[d][1];
			}
			else if (u == 'B') {
				x -= dir[d][0];
				y -= dir[d][1];
			}
			else if (u == 'L') d = (d + 1) % 4;
			else d = (d + 3) % 4;
			min_x = min(min_x, x);
			max_x = max(max_x, x);
			min_y = min(min_y, y);
			max_y = max(max_y, y);
		}
		cout << (max_x - min_x) * (max_y - min_y) << '\n';
	}
}
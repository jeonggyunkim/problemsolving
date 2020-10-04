#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, sx, sy;
	string pos;

	cin >> pos;
	x = pos[0] - 'A';
	y = pos[1] - '1';

	cin >> pos;
	sx = pos[0] - 'A';
	sy = pos[1] - '1';

	int n;
	cin >> n;

	while (n--) {
		cin >> pos;
		int dx = 0, dy = 0;
		if (pos.back() == 'T') dy = 1;
		else if (pos.back() == 'B') dy = -1;

		if (pos[0] == 'R') dx = 1;
		else if (pos[0] == 'L') dx = -1;

		x += dx; y += dy;
		if (x < 0 || y < 0 || x >= 8 || y >= 8) {
			x -= dx; y -= dy;
			continue;
		}
		else if (x == sx && y == sy) {
			sx += dx; sy += dy;
			if (sx < 0 || sy < 0 || sx >= 8 || sy >= 8) {
				sx -= dx; sy -= dy;
				x -= dx; y -= dy;
				continue;
			}
		}
	}

	cout << (char)(x + 'A') << (char)(y + '1') << '\n';
	cout << (char)(sx + 'A') << (char)(sy + '1') << '\n';
}
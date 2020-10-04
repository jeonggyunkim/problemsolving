#include <iostream>
#include <memory.h>
using namespace std;

bool arr[1020][2020];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(arr, 0, sizeof(arr));
		int c;
		cin >> c;
		int x = 1010, y = 510;

		char d; int n;
		int miny = y, maxy = y;
		while (c--) {
			cin >> d >> n;
			bool neg = 0;
			if (n < 0) {
				neg = 1;
				n = -n;
			}
			if (d == 'x') {
				if (neg) x -= 2 * n;
				else x += 2 * n;
			}
			else if (d == 'y') {
				x++;
				if (neg) {
					while (n--) {
						y--;
						arr[y][x] = 1;
					}
				}
				else {
					while (n--) {
						arr[y][x] = 1;
						y++;
					}
				}
				x--;
			}
			else {
				if (neg) {
					while (n--) {
						y--;
						x += 2;
						arr[y][x] = 1;
					}
				}
				else {
					while (n--) {
						arr[y][x] = 1;
						x -= 2;
						y++;
					}
				}
			}
			miny = min(miny, y);
			maxy = max(maxy, y);
		}
		int area = 0;
		for (int i = miny; i <= maxy; ++i) {
			bool in = 0;
			for (int j = 1; j < 2020; ++j) {
				if (in) area++;
				if (arr[i][j]) in = !in;
			}
		}
		cout << area << '\n';
	}
}
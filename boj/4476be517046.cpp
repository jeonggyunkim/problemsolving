#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, W, H;
	cin >> w >> h >> W >> H;
	
	int x, y;
	cin >> x >> y;

	int vx, vy;
	cin >> vx >> vy;
	
	vector<bool> topL(W - w + 1, 0);
	vector<bool> topR(W - w + 1, 0);
	vector<bool> bottomL(W - w + 1, 0);
	vector<bool> bottomR(W - w + 1, 0);

	long long time = 0;
	while (1) {
		if (vy == 1) {
			int down = H - h - y;
			time += down;
			down %= (2 * (W - w));
			int move;
			while (down) {
				if (vx == 1) {
					move = min(down, W - w - x);
					down -= move;
					x += move;
					if (x == W - w) vx = -vx;
				}
				else {
					move = min(down, x);
					down -= move;
					x -= move;
					if (x == 0) vx = -vx;
				}
			}
			y = H - h;
			if (x == 0 || x == W - w) {
				cout << time;
				return 0;
			}
			if (vx == 1) {
				if (bottomR[x]) {
					cout << -1;
					return 0;
				}
				bottomR[x] = 1;
			}
			else {
				if (bottomL[x]) {
					cout << -1;
					return 0;
				}
				bottomL[x] = 1;
			}
		}
		else {
			int up = y;
			time += up;
			up %= (2 * (W - w));
			int move;
			while (up) {
				if (vx == 1) {
					move = min(up, W - w - x);
					up -= move;
					x += move;
					if (x == W - w) vx = -vx;
				}
				else {
					move = min(up, x);
					up -= move;
					x -= move;
					if (x == 0) vx = -vx;
				}
			}
			y = 0;
			if (x == 0 || x == W - w) {
				cout << time;
				return 0;
			}
			if (vx == 1) {
				if (topR[x]) {
					cout << -1;
					return 0;
				}
				topR[x] = 1;
			}
			else {
				if (topL[x]) {
					cout << -1;
					return 0;
				}
				topL[x] = 1;
			}
		}
		vy = -vy;
	}
}
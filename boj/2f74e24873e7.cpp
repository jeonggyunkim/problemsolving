#include <iostream>
#define D 200
using namespace std;

int a[401][401];
int arr[300000];

int main() {
	int n, t;
	cin >> n;

	int x, y;
	int dir = 0, cnt = 0, now = 0;
	int con = 0, d = 0;

	while (n--) {
		cin >> x >> y;
		a[D + y][D + x] = 1;
		cnt++;
	}
	cin >> t;

	x = D; y = D;
	while (1) {
		arr[now] = cnt;
		if (now >= 104) {
			int nowd = arr[now] - arr[now - 104];
			if (nowd == d) con++;
			else {
				con = 0;
				d = nowd;
			}
			if (con > 2000) {
				if (t <= now) cout << arr[t];
				else {
					int p = (t - now) / 104 + 1;
					int q = (t - now) % 104;
					cout << arr[now - (104 - q)] + d * p;
				}
				break;
			}
		}

		if (a[x][y] == 0) {
			dir = (dir + 3) % 4;
			a[x][y] = 1; cnt++;
		}
		else {
			dir = (dir + 1) % 4;
			a[x][y] = 0; cnt--;
		}
		if (dir == 0) x--;
		else if (dir == 1) y++;
		else if (dir == 2) x++;
		else y--;
		now++;
	}
}
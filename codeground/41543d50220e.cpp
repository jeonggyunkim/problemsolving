#include <bits/stdc++.h>
#define PI (atan(1) * 4)
using namespace std;

int a, b, c, d, e;
int board[20] = {13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10, 6};

int dart(int x, int y) {
	int r = x * x + y * y;
	if (r < a) return 50;
	else {
		int ret;
		double theta;
		if (x == 0) theta = y > 0 ? PI / 2 : PI * 3 / 2;
		else if (y == 0) theta = x > 0 ? 0 : PI;
		else {
			theta = atan((double)y / x);
			if (x < 0) theta += PI;
			if (theta < 0) theta += 2 * PI;
		}
		theta = theta * 180.0 / PI;
		theta -= 9;
		if (theta < 0) ret = 6;
		else ret = board[(int)(theta / 18)];
		
		if (r > e) return 0;
		if (b < r && r < c) return 3 * ret;
		else if (d < r && r < e) return 2 * ret;
		else return ret;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> a >> b >> c >> d >> e >> n;
		a *= a; b *= b; c *= c; d *= d; e *= e;
		int x, y, score = 0;
		while (n--) {
			cin >> x >> y;
			score += dart(x, y);
		}
		cout << "Case #" << test << '\n';
		cout << score << '\n';
	}
}
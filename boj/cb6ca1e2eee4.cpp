#include <iostream>
#include <cmath>
#define SQ(x) ((x) * (x))
using namespace std;

typedef pair<long long, long long> ll;

int ccw(ll a, ll b, ll c) {
	ll ab = {b.first - a.first, b.second - a.second};
	ll ac = {c.first - a.first, c.second - a.second};
	long long d = (ab.first * ac.second) - (ab.second * ac.first);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

int main() {
	int l, w, cx, cy, tx, ty, n;
	while (cin >> l >> w >> cx >> cy >> tx >> ty >> n, l) {
		double ans = 1e10;
		for (int i = 0; i < 201; ++i) {
			for (int j = 0; j < 201; ++j) {
				int hit = abs(100 - i) + abs(100 - j);
				if (hit == n) {
					int x, y;
					if (i & 1) x = (i - 99) * l - tx;
					else x = (i - 100) * l + tx;

					if (j & 1) y = (j - 99) * w - ty;
					else y = (j - 100) * w + ty;

					bool col = 0;
					for (int ii = min(i, 100); ii <= max(i, 100); ++ii) {
						for (int jj = min(j, 100); jj <= max(j, 100); ++jj) {
							if (ii == i && jj == j) continue;

							int xx, yy;
							if (ii & 1) xx = (ii - 99) * l - tx;
							else xx = (ii - 100) * l + tx;

							if (jj & 1) yy = (jj - 99) * w - ty;
							else yy = (jj - 100) * w + ty;
							if (ccw({xx, yy}, {x, y}, {cx, cy}) == 0) {
								if (ii == 100 && jj == 100) {
									if ((xx < cx) == (x < cx) && (yy < cy) == (y < cy)) col = 1;
								}
								else col = 1;
							}
						}
					}

					if (!col) {
						ans = min(ans, sqrt(SQ(x - cx) + SQ(y - cy)));
					}
				}
			}
		}
		cout.precision(3);
		cout << fixed;
		cout << ans << '\n';
	}
}
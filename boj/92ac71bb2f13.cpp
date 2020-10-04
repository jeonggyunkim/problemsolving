#include <iostream>
#include <tuple>
#include <vector>
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l, n;
	cin >> l >> n;

	vector<iii> garo, sero;
	garo.push_back({l + 1, -l - 1, l + 1});
	garo.push_back({-l - 1, -l - 1, l + 1});
	sero.push_back({l + 1, -l - 1, l + 1});
	sero.push_back({-l - 1, -l - 1, l + 1});
	garo.push_back({0, 0, 0});

	int dir = 0, d;
	int x = 0, y = 0;
	char c;
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		if (i == n) {
			d = INF;
		}
		else {
			cin >> d >> c;
		}

		int nowmove = d;
		bool col = 0;
		if (dir == 0) {
			for (iii u: garo) {
				if (get<0>(u) == y && get<1>(u) >= x + 1 && get<1>(u) <= x + d) {
					nowmove = min(nowmove, get<1>(u) - x);
					col = 1;
				}
			}
			for (iii u: sero) {
				if (get<0>(u) >= x + 1 && get<0>(u) <= x + d && get<1>(u) <= y && y <= get<2>(u)) {
					nowmove = min(nowmove, get<0>(u) - x);
					col = 1;
				}
			}
			garo.push_back({y, x + 1, x + d});
			x += d;
		}
		else if (dir == 1) {
			for (iii u: sero) {
				if (get<0>(u) == x && get<1>(u) >= y + 1 && get<1>(u) <= y + d) {
					nowmove = min(nowmove, get<1>(u) - y);
					col = 1;
				}
			}
			for (iii u: garo) {
				if (get<0>(u) >= y + 1 && get<0>(u) <= y + d && get<1>(u) <= x && x <= get<2>(u)) {
					nowmove = min(nowmove, get<0>(u) - y);
					col = 1;
				}
			}
			sero.push_back({x, y + 1, y + d});
			y += d;
		}
		else if (dir == 2) {
			for (iii u: garo) {
				if (get<0>(u) == y && get<2>(u) >= x - d && get<2>(u) <= x - 1) {
					nowmove = min(nowmove, x - get<2>(u));
					col = 1;
				}
			}
			for (iii u: sero) {
				if (get<0>(u) >= x - d && get<0>(u) <= x - 1 && get<1>(u) <= y && y <= get<2>(u)) {
					nowmove = min(nowmove, x - get<0>(u));
					col = 1;
				}
			}
			garo.push_back({y, x - d, x - 1});
			x -= d;
		}
		else {
			for (iii u: sero) {
				if (get<0>(u) == x && get<2>(u) >= y - d && get<2>(u) <= y - 1) {
					nowmove = min(nowmove, y - get<2>(u));
					col = 1;
				}
			}
			for (iii u: garo) {
				if (get<0>(u) >= y - d && get<0>(u) <= y - 1 && get<1>(u) <= x && x <= get<2>(u)) {
					nowmove = min(nowmove, y - get<0>(u));
					col = 1;
				}
			}
			sero.push_back({x, y - d, y - 1});
			y -= d;
		}

		if (col) {
			cout << ans + nowmove;
			return 0;
		}
		ans += nowmove;

		if (c == 'L') dir = (dir + 1) % 4;
		else dir = (dir + 3) % 4;
	}
}
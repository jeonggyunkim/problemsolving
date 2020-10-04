#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int dist(int a, int b) {
	return abs(a / 10000 - b / 10000) + abs(a % 10000 - b % 10000);
}

struct info {
	int d;
	int now;
	info* prev;
	info() {}
	info(int d, int now, info* prev) : d(d), now(now), prev(prev) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w;
	cin >> n >> w;

	vector<int> loc(w);
	int x, y;
	for (int i = 0; i < w; ++i) {
		cin >> x >> y;
		loc[i] = x * 10000 + y;
	}

	vector<map<ii, info>> mem(w + 1);
	mem[0][ii(10001, n * 10000 + n)] = info(0, 0, nullptr);

	for (int i = 0; i < w; ++i) {
		for (auto it = mem[i].begin(); it != mem[i].end(); ++it) {
			x = it->first.first;
			y = it->first.second;

			ii next = ii(loc[i], y);
			if (mem[i + 1].count(next)) {
				int nowd = it->second.d + dist(x, loc[i]);
				if (mem[i + 1][next].d > nowd) {
					mem[i + 1][next] = info(nowd, 1, &it->second);
				}
			}
			else mem[i + 1][next] = info(it->second.d + dist(x, loc[i]), 1, &it->second);

			next = ii(x, loc[i]);
			if (mem[i + 1].count(next)) {
				int nowd = it->second.d + dist(y, loc[i]);
				if (mem[i + 1][next].d > nowd) {
					mem[i + 1][next] = info(nowd, 2, &it->second);
				}
			}
			else mem[i + 1][next] = info(it->second.d + dist(y, loc[i]), 2, &it->second);
		}
	}

	int ans = 987654321;
	vector<int> order;
	info* now;
	for (auto it = mem[w].begin(); it != mem[w].end(); ++it) {
		if (it->second.d < ans) {
			ans = it->second.d;
			now = &it->second;
		}
	}

	while (now->prev) {
		order.push_back(now->now);
		now = now->prev;
	}

	cout << ans << '\n';
	for (int i = w - 1; i >= 0; --i) cout << order[i] << '\n';
}
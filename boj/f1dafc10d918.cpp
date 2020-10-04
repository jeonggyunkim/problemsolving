#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;

char w1[22][22];
char w2[22][22];

bool insert(ii w, set<ii>& d) {
	auto it = d.lower_bound(w);
	if (it != d.begin()) {
		it--;
		if (it->second <= w.second) return 0;
		it++;
	}
	while (it != d.end()) {
		if (it->second >= w.second) {
			auto jt = it;
			it++;
			d.erase(jt);
		}
		else break;
	}
	d.insert(w);
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> w1[i];
	for (int i = 0; i < n; ++i) cin >> w2[i];

	set<ii> d[20];
	queue<iii> q;
	q.push({0, {0, 0}});
	d[0].insert({0, 0});

	while (!q.empty()) {
		iii now = q.front(); q.pop();
		if (d[now.first].count(now.second) == 0) continue;
		for (int i = 0; i < n; ++i) {
			if (w1[now.first][i] != '.') {
				ii w = now.second;
				w.first += w1[now.first][i] - '0';
				w.second += w2[now.first][i] - '0';
				if (insert(w, d[i])) {
					q.push({i, w});
				}
			}
		}
	}

	int ans = 987654321;
	for (ii u: d[1]) {
		ans = min(ans, u.first * u.second);
	}
	if (ans == 987654321) cout << -1;
	else cout << ans;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#define INF ((1 << 31) - 1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d, l;
	cin >> n >> m >> d >> l;

	vector<int> hole(n);
	hole[0] = 0;
	for (int i = 1; i < n; ++i) cin >> hole[i];

	set<int> cd;
	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		cd.insert(t);
	}
	cd.insert(-INF);
	cd.insert(INF);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (cd.lower_bound(hole[i] - l) != cd.upper_bound(hole[i] + l)) ans++;
	}

	int x, y;
	for (int i = 0; i < d; ++i) {
		cout << ans << '\n';

		cin >> x >> y;

		auto it = cd.find(x);
		auto jt = it, kt = it;
		jt--; kt++;
		auto left = lower_bound(hole.begin(), hole.end(), max(*jt + l + 1, x - l));
		auto right = lower_bound(hole.begin(), hole.end(), min(*kt - l, x + l + 1));
		int d = right - left;
		ans -= max(d, 0);
		cd.erase(it);

		kt = cd.lower_bound(y);
		jt = kt; jt--;
		left = lower_bound(hole.begin(), hole.end(), max(*jt + l + 1, y - l));
		right = lower_bound(hole.begin(), hole.end(), min(*kt - l, y + l + 1));
		d = right - left;
		ans += max(d, 0);
		cd.insert(y);
	}
	cout << ans;
}

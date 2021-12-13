#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> i3;

int s[2000], t[2000], y[2000];
i3 center;

long long ccw(i3& p, i3& q, i3& r) {
	return (get<0>(q) - get<0>(p)) * (get<1>(r) - get<1>(p)) - (get<1>(q) - get<1>(p)) * (get<0>(r) - get<0>(p));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> t[i] >> y[i];
		if (s[i] > t[i]) {
			swap(s[i], t[i]);
		}
		if (s[i] == t[i]) {
			i--; n--;
		}
	}

	center = {0, 0, 0};
	for (int i = 0; i < n; ++i) {
		for (int rep = 0; rep < 2; ++rep) {
			vector<i3> up, down;
			for (int j = 0; j < n; ++j) {
				if (y[j] > y[i]) {
					if (rep == 0) {
						down.push_back({s[j] - s[i], y[i] - y[j], t[j] - s[j]});
						down.push_back({t[j] - s[i], y[i] - y[j], s[j] - t[j]});
					}
					else {
						down.push_back({s[j] - t[i], y[i] - y[j], t[j] - s[j]});
						down.push_back({t[j] - t[i], y[i] - y[j], s[j] - t[j]});
					}
				}
				else if (y[j] < y[i]) {
					if (rep == 0) {
						up.push_back({s[j] - s[i], y[i] - y[j], s[j] - t[j]});
						up.push_back({t[j] - s[i], y[i] - y[j], t[j] - s[j]});
					}
					else {
						up.push_back({s[j] - t[i], y[i] - y[j], s[j] - t[j]});
						up.push_back({t[j] - t[i], y[i] - y[j], t[j] - s[j]});
					}
				}
			}

			sort(down.begin(), down.end(), [](i3& x, i3& y) {
				return ccw(center, x, y) > 0 || (ccw(center, x, y) == 0 && get<2>(x) > get<2>(y));
			});
			sort(up.begin(), up.end(), [](i3& x, i3& y) {
				return ccw(center, x, y) > 0 || (ccw(center, x, y) == 0 && get<2>(x) > get<2>(y));
			});

			ans = max(ans, t[i] - s[i]);
			int len = t[i] - s[i], k = 0;
			for (int j = 0; j < up.size(); ++j) {
				len += get<2>(up[j]);
				if (j != 0 && ccw(center, up[j], up[j - 1]) == 0 && get<2>(up[j]) < 0) continue;
				else {
					while (k < down.size() && (ccw(up[j], center, down[k]) < 0 || (ccw(up[j], center, down[k]) == 0 && get<2>(down[k]) > 0))) {
						len += get<2>(down[k]);
						k++;
					}
					ans = max(ans, len);
				}
			}

			len = t[i] - s[i]; k = 0;
			for (int j = 0; j < down.size(); ++j) {
				len += get<2>(down[j]);
				if (j != 0 && ccw(center, down[j], down[j - 1]) == 0 && get<2>(down[j]) < 0) continue;
				else {
					while (k < up.size() && (ccw(down[j], center, up[k]) < 0 || (ccw(down[j], center, up[k]) == 0 && get<2>(up[k]) > 0))) {
						len += get<2>(up[k]);
						k++;
					}
					ans = max(ans, len);
				}
			}
		}
	}
	cout << ans << '\n';
}

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#define SQ(x) ((x) * (x))
using namespace std;

typedef pair<int, int> ii;

bool can_put(double x1, double r1, double x2, double r2, double t) {
	double x = x1 + sqrt(SQ(r1 + t) - SQ(r1 - t));
	return x < x2 && (SQ(x2 - x) + SQ(r2 - t)) > SQ(r2 + t);
}

double find_max(double x1, double r1, double x2, double r2) {
	double low = 0, high = 1e7, mid;
	for (int i = 0; i < 60; ++i) {
		double mid = (low + high) / 2;
		if (can_put(x1, r1, x2, r2, mid)) low = mid;
		else high = mid;
	}
	return low;
}

double put(double r, double x, double t, int pos) {
	if (pos == 1) return x + sqrt(SQ(r + t) - SQ(r - t));
	else return x - sqrt(SQ(r + t) - SQ(r - t));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		vector<ii> r(n);
		int t;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			r[i] = ii(t, i);
		}

		sort(r.begin(), r.end(), greater<ii>());

		vector<double> ans(n);
		set<pair<double, int>> s;

		ans[r[0].second] = 0;
		s.insert(make_pair(0.0, r[0].first));
		double x = put(r[0].first, 0, r[1].first, 1);
		ans[r[1].second] = x;
		s.insert(make_pair(x, r[1].first));

		for (int i = 2; i < n; ++i) {
			int find = 0;
			auto it = s.begin();
			auto jt = it;
			jt++;
			double maximum_size = 1e10;
			while (jt != s.end()) {
				double t = find_max(it->first, it->second, jt->first, jt->second);
				if (r[i].first < t && t < maximum_size) {
					maximum_size = t;
					if (it->second < jt->second) x = put(it->second, it->first, r[i].first, 1);
					else x = put(jt->second, jt->first, r[i].first, -1);
					find = 1;
				}
				it++; jt++;
			}
			if (find) {
				s.insert(make_pair(x, r[i].first));
				ans[r[i].second] = x;
			}
			else {
				x = put(s.rbegin()->second, s.rbegin()->first, r[i].first, 1);
				s.insert(make_pair(x, r[i].first));
				ans[r[i].second] = x;
			}
		}

		cout.precision(20);
		cout << "Case #" << test << '\n';
		for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
	}
}

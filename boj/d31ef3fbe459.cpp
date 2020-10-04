#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> cow(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cow[i];
		sum += cow[i];
	}

	sort(cow.begin(), cow.end());

	map<ll, pair<ll, int>> mp;
	vector<ii> milk(m);
	for (int i = 0; i < m; ++i) {
		cin >> milk[i].second >> milk[i].first;
	}
	sort(milk.begin(), milk.end(), greater<ii>());
	ll msum = 0, mprice = 0;
	for (int i = 0; i < m; ++i) {
		msum += milk[i].second;
		mprice += (ll)milk[i].first * milk[i].second;
		mp[msum] = {mprice, milk[i].first};
	}

	vector<int> farm(r);
	for (int i = 0; i < r; ++i) cin >> farm[i];
	sort(farm.begin(), farm.end(), greater<int>());

	ll ans = -1;
	auto it = mp.lower_bound(sum);
	if (it == mp.end()) {
		it--;
		ans = it->second.first;
	}
	else {
		ans = it->second.first - it->second.second * (it->first - sum);
	}

	ll rentsum = 0, now;
	for (int i = 1; i <= min(n, r); ++i) {
		sum -= cow[i - 1];
		auto it = mp.lower_bound(sum);
		if (it == mp.end()) {
			it--;
			now = it->second.first;
		}
		else {
			now = it->second.first - it->second.second * (it->first - sum);
		}
		rentsum += farm[i - 1];
		now += rentsum;
		ans = max(ans, now);
	}
	cout << ans;
}
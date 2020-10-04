#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<ll, ll>> city(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> city[i].first >> city[i].second;
		sum += city[i].second;
	}

	sort(city.begin(), city.end());
	ll now = 0;

	for (int i = 0; i < n; ++i) {
		now += city[i].second;
		if (now >= sum - now) {
			cout << city[i].first;
			break;
		}
	}
}
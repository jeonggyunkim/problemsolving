#include <iostream>
#include <vector>
#include <algorithm>
#define SQ(a) ((a) * (a))
#define INF (1LL << 60)
#define N 100000
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> i3;

ll d[N];

ll ccw(ii& q, ii& r) {
	return q.first * r.second - q.second * r.first;
}

ll dist(ii& b) {
	return SQ(b.first) + SQ(b.second);
}

void clockwise_sort(vector<i3>& arr) {
	vector<i3> upper, lower;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i].first.second == 0) {
			if (arr[i].first.first > 0) upper.push_back(arr[i]);
			else lower.push_back(arr[i]);
		}
		else {
			if (arr[i].first.second > 0) upper.push_back(arr[i]);
			else lower.push_back(arr[i]);
		}
	}
	sort(upper.begin(), upper.end(), [](i3& x, i3& y) {
		return ccw(x.first, y.first) > 0 || (ccw(x.first, y.first) == 0 && dist(x.first) < dist(y.first));
	});
	sort(lower.begin(), lower.end(), [](i3& x, i3& y) {
		return ccw(x.first, y.first) > 0 || (ccw(x.first, y.first) == 0 && dist(x.first) < dist(y.first));
	});
	auto it = arr.begin();
	for (i3 u: upper) {
		*it = u; it++;
	}
	for (i3 u: lower) {
		*it = u; it++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<i3> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	}
	clockwise_sort(arr);
	for (int i = 0; i < n; ++i) {
		d[i] = SQ(arr[i].first.first) + SQ(arr[i].first.second);
	}

	ll ans = -INF;
	for (int i = 0; i < m; ++i) {
		ll price;
		cin >> price;
		ans = max(ans, -price);

		vector<i3> star;
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (d[j] <= price) {
				star.push_back(arr[j]);
				cnt++;
			}
		}
		for (int j = 0; j < cnt; ++j) star.push_back(star[j]);
		int ind = 0;
		ll sum = 0;
		for (int j = 0; j < cnt; ++j) {
			ii rotate = {-star[j].first.second, star[j].first.first};
			while (ind != j + cnt && ccw(star[j].first, star[ind].first) >= 0 && ccw(rotate, star[ind].first) <= 0) {
				sum += star[ind].second;
				ind++;
			}
			ans = max(ans, sum - price);
			sum -= star[j].second;
		}
	}
	cout << ans;
}
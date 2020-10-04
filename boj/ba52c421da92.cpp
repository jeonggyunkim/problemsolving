#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ii find(ll t) {
	if (t == 0) return {0, 0};
	ll low = 0, high = 1e9;
	while (high - low != 1) {
		ll mid = (low + high) / 2;
		if (t <= mid * mid) high = mid;
		else low = mid;
	}
	return {high, high * high - t};
}

int main() {
	ll t;
	cin >> t;

	vector<ii> ans;
	queue<ll> q;
	q.push(t);
	while (!q.empty()) {
		ii t = find(q.front());
		q.pop();

		ans.push_back(t);
		if (t.first > 2) q.push(t.first);
		if (t.first > 2) q.push(t.second);
	}
	
	set<ll> s;
	s.insert(0);
	s.insert(1);
	s.insert(2);

	for (int i = (int)ans.size() - 1; i >= 0; --i) {
		if (!s.count(ans[i].first * ans[i].first - ans[i].second)) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
			s.insert(ans[i].first * ans[i].first - ans[i].second);
		}
	}
}
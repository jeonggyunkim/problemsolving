#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

ll a[40];
ll b[40];
ll c[40];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll goal = 0;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		goal += b[i];
	}
	for (int i = 0; i < n; ++i) c[i] = a[i] + b[i];

	int nn = n / 2;

	map<ll, int> m[20];
	for (int i = 0; i < (1 << nn); ++i) {
		ll now = 0;
		int cnt = 0;
		for (int j = 0; j < nn; ++j) {
			if (i & (1 << j)) {
				cnt++;
				now += c[n - 1 - j];
			}
		}
		m[cnt][now] = i;
	}

	ll diff = (1LL << 60), dif;
	int ans = 0, ans2;
	for (int i = (1 << nn) - 1; i >= 0; --i) {
		ll now = 0;
		int cnt = 0;
		for (int j = 0; j < nn; ++j) {
			if (i & (1 << j)) {
				cnt++;
				now += c[nn - 1 - j];
			}
		}
		auto it = m[nn - cnt].lower_bound(goal - now);
		if (it != m[nn - cnt].end()) {
			dif = abs(goal - now - it->first);
			if (dif < diff) {
				diff = dif;
				ans = i;
				ans2 = it->second;
			}
		}
		if (it != m[nn - cnt].begin()) {
			it--;
			dif = abs(goal - now - it->first);
			if (dif < diff) {
				diff = dif;
				ans = i;
				ans2 = it->second;
			}
			else if (dif == diff && ans == i) {
				ans2 = max(it->second, ans2);
			}
		}
	}

	for (int i = nn - 1; i >= 0; --i) {
		if (ans & (1 << i)) cout << "1 ";
		else cout << "2 ";
	}
	for (int i = nn - 1; i >= 0; --i) {
		if (ans2 & (1 << i)) cout << "1 ";
		else cout << "2 ";
	}
}
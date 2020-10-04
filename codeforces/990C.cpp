#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> v(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int f = 0, d = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') f++;
			else {
				f--;
				if (f < d) d = f;
			}
		}
		v[i] = ii(f, d);
	}

	sort(v.begin(), v.end());

	long long ans = 0, mem;
	for (int i = 0; i < n; ++i) {
		if (v[i].second < 0) continue;
		auto low = lower_bound(v.begin(), v.end(), ii(-v[i].first, -v[i].first));
		auto high = upper_bound(v.begin(), v.end(), ii(-v[i].first + 1, -987654321));
		ans += high - low;
	}
	cout << ans;
}
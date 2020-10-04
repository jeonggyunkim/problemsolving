#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int sum = 0;
	vector<ii> v;
	int a = 0, b;
	while (n) {
		cin >> b; n--;
		v.push_back(ii(a, b));
		sum += b - a;

		if (n) {
			cin >> a;
			n--;
			if (n == 0) {
				b = m;
				v.push_back(ii(a, b));
				sum += b - a;
			}
		}
	}

	long long ans = sum, s;
	int add = 0;

	if (v[0].second != 1) {
		s = 1;
		ans = max(ans, 2 * s - 1 + m - sum);
	}

	n = v.size();
	for (int i = 0; i < n; ++i) {
		add += v[i].second - v[i].first;
		if (v[i].second - 1 != v[i].first) {
			s = add - 1;
			ans = max(ans, 2 * s - v[i].second + 1 + m - sum);
		}
		if (i != n - 1 && v[i].second + 1 != v[i + 1].first) {
			s = add;
			ans = max(ans, 2 * s - v[i].second - 1 + m - sum);
		}
	}
	if (v[n - 1].second + 1 != m && v[n - 1].second != m) {
		s = sum;
		ans = max(ans, 2 * s - v[n - 1].second - 1 + m - sum);
		ans = max(ans, 2 * s + 1 - sum);
	}

	cout << ans;
}
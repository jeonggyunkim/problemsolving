#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

bool comp(ii& a, ii& b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		vector<ii> v(n);
		int a, b;
		for (int i = 0; i < n; ++i) cin >> v[i].first;
		for (int i = 0; i < n; ++i) cin >> v[i].second;

		sort(v.begin(), v.end(), comp);

		int m = 0, t = 0;
		for (int i = 0; i < n; ++i) {
			t += v[i].first;
			m = max(m, t + v[i].second);
		}

		cout << m << '\n';
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, n, m, t;
	int suma[1001] = {}, sumb[1001] = {};
	cin >> s >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		suma[i] = suma[i - 1] + t;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> t;
		sumb[i] = sumb[i - 1] + t;
	}

	vector<int> suba, subb;
	for (int i = 1; i <= n; ++i) for (int j = i; j <= n; ++j) {
		suba.push_back(suma[j] - suma[i - 1]);
	}
	for (int i = 1; i <= m; ++i) for (int j = i; j <= m; ++j) {
		subb.push_back(sumb[j] - sumb[i - 1]);
	}

	sort(subb.begin(), subb.end());
	long long ans = 0;
	for (int i = 0; i < suba.size(); ++i) {
		auto t = equal_range(subb.begin(), subb.end(), s - suba[i]);
		ans += t.second - t.first;
	}
	cout << ans;
}
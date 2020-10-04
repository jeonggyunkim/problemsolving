#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int a[101];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		sort(v.begin(), v.end());
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			if (it != v.end()) {
				cnt++;
				v.erase(it);
			}
		}

		cout << cnt << '\n';
	}
}

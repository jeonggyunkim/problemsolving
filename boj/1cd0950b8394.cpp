#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		vector<ii> arr;
		multiset<long long> st;
		long long a, b;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			arr.push_back({a, b});
			st.insert(b);
		}

		sort(arr.begin(), arr.end(), greater<ii>());

		long long max_before = -1, ans = (1LL << 62);
		for (int i = 0; i < n; ++i) {
			auto it = st.find(arr[i].second);
			st.erase(it);

			it = st.upper_bound(arr[i].first);
			if (it != st.end()) {
				ans = min(ans, abs(max(*it, max_before) - arr[i].first));
			}
			if (it != st.begin()) {
				it--;
				ans = min(ans, abs(max(*it, max_before) - arr[i].first));
			}
			if (i) ans = min(ans, abs(max_before - arr[i].first));
			max_before = max(max_before, arr[i].second);
		}
		cout << ans << '\n';
	}
}
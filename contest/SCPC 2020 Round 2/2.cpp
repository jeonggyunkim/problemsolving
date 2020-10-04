#include <bits/stdc++.h>
using namespace std;

long long arr[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		long long n, m;
		cin >> n >> m;

		long long ans = 0;
		multiset<long long> st;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (i) arr[i] += arr[i - 1];
			st.insert(arr[i]);
		}

		for (int i = 0; i < n; ++i) {
			long long now;
			if (i == 0) now = 0;
			else now = arr[i - 1];

			auto it = st.upper_bound(m + now);
			if (it != st.begin()) {
				it--;
				ans = max(ans, *it - now);
			}
			st.erase(st.find(arr[i]));
		}

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, x, t;
		cin >> n >> x;

		multiset<int> st;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			st.insert(t);
		}

		int ans = 0;
		while (!st.empty()) {
			if (st.size() == 1) {
				ans++;
				break;
			}
			int i = *st.rbegin();
			auto it = st.upper_bound(x - i);
			if (it == st.begin()) {
				it = st.end(); it--;
				st.erase(it);
			}
			else {
				if (it == st.end()) {
					it = st.end(); it--;
					st.erase(it);
					it = st.end(); it--;
					st.erase(it);
				}
				else {
					it--;
					st.erase(it);
					it = st.end(); it--;
					st.erase(it);
				}
			}
			ans++;
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}
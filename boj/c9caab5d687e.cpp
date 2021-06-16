#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int arr[100000];
ii pool[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) cin >> arr[i];

		for (int i = 0; i < m; ++i) {
			cin >> pool[i].first >> pool[i].second;
		}

		sort(arr, arr + n);
		sort(pool, pool + m);

		int ind = 0, ans = 0;
		multiset<int> st;
		for (int i = 0; i < n; ++i) {
			while (ind < m && pool[ind].first <= arr[i]) {
				st.insert(pool[ind].second);
				ind++;
			}
			while (!st.empty() && *(st.begin()) < arr[i]) {
				st.erase(st.begin());
			}
			if (!st.empty()) {
				ans++;
				st.erase(st.begin());
			}
		}
		cout << ans << '\n';
	}
}
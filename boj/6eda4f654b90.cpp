#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<ii> bo;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		bo.push_back({b, a});
	}
	sort(bo.begin(), bo.end(), greater<ii>());

	multiset<int> st;
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		st.insert(c);
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		auto it = st.lower_bound(bo[i].second);
		if (it != st.end()) {
			ans += bo[i].first;
			st.erase(it);
		}
	}
	cout << ans;
}
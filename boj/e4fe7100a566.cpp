#include <iostream>
#include <set>
using namespace std;

int e[200010];
long long sum[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> e[i];
		sum[i] = sum[i - 1] + e[i];
	}

	set<int> st;
	int op, s, t;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> t;
			st.insert(t);
		}
		else {
			cin >> s >> t;
			auto it = st.lower_bound(t);
			if (it != st.begin()) {
				it--;
				s = max(*it + 1, s);
			}
			cout << sum[t] - sum[s - 1] << '\n';
		}
	}
}
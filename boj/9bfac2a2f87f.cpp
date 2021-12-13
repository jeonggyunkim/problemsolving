#include <iostream>
#include <unordered_set>
#define N 1000010
using namespace std;

typedef long long ll;

const ll A = 950922101;

ll p[N + 1];
ll h[N + 1];

inline ll strhash(int a, int b) {
	return h[b + 1] - h[a] * p[b - a + 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	p[0] = 1;
	for (int i = 1; i <= N; ++i) p[i] = p[i - 1] * A;

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		string s, t;

		cin >> n >> m;
		cin >> s >> t;

		if (n < m) {
			cout << "0\n";
			continue;
		}

		unordered_set<ll> st;
		ll hash = 0;
		for (int i = 0; i < m; ++i) hash = hash * A + t[i];
		st.insert(hash);
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				for (int ii = i, jj = j; ii < jj; ++ii, --jj) swap(t[ii], t[jj]);
				hash = 0;
				for (int k = 0; k < m; ++k) hash = hash * A + t[k];
				st.insert(hash);
				for (int ii = i, jj = j; ii < jj; ++ii, --jj) swap(t[ii], t[jj]);
			}
		}

		for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * A + s[i - 1];

		int ans = 0;
		for (int i = 0; i <= n - m; ++i) {
			if (st.count(strhash(i, i + m - 1))) ans++;;
		}
		cout << ans << '\n';
	}
}
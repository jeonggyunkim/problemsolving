#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		int n, m, t;
		cin >> n >> m;
		
		vector<bool> s(m + 1, 0);
		s[0] = 1;
		while (n--) {
			cin >> t;
			if (!s[m]) {
				for (int i = m; i >= 0; --i) {
					if (s[i] && i + t <= m) s[i + t] = 1;
				}
			}
		}
		
		cout << "Case #" << test << '\n';
		for (int i = m; i >= 0; --i) {
			if (s[i]) {
				cout << i << '\n';
				break;
			}
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int t;
	map<int, int> m;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		m[t] = i;
	}

	if (m.size() >= k) {
		cout << "YES" << '\n';
		int i = 0;
		auto it = m.begin();
		while (i < k) {
			cout << it->second << ' ';
			it++; i++;
		}
	}
	else cout << "NO" << '\n';
}
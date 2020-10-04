#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	int t;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] %= n;
	}
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		t %= n;
		if (m.count(t)) m[t]++;
		else m[t] = 1;
	}

	for (int i = 0; i < n; ++i) {
		int f = n - a[i];
		if (f == n) f = 0;
		auto it = m.lower_bound(f);
		if (it == m.end()) it = m.begin();
		cout << (a[i] + it->first) % n << ' ';
		it->second--;
		if (it->second == 0) m.erase(it);
	}
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	map<string, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		m[s]++;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (m.count(s)) {
			m[s]--;
			if (m[s] == 0) m.erase(s);
		}
		else ans++;
	}
	cout << ans;
}
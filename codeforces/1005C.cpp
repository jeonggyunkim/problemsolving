#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<unsigned int, pair<bool, int>> m;
	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		m[t].second++;
	}

	int ans = 0;
	auto it = m.end();
	it--;
	while (true) {
		unsigned int i = 1;
		while (true) {
			if (i > it->first) {
				unsigned int j = i - it->first;
				if (j > it->first) break;
				if (j == it->first) {
					if ((it->second).second >= 2) {
						(it->second).first = 1;
					}
				}
				else if (m.find(j) != m.end()) {
					m[j].first = 1;
					(it->second).first = 1;
				}
			}
			i <<= 1;
		}
		if (!(it->second).first) ans += it->second.second;
		if (it == m.begin()) break;
		it--;
	}
	cout << ans;
}
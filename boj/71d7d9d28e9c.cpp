#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> v(n);

	int k, t;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		while (k--) {
			cin >> t;
			v[i].push_back(t);
		}
	}

	map<int, int> m;
	m[0] = 0;
	for (int i = 0; i < n; ++i) {
		map<int, int> tm = m;
		for (int j = 0; j < n; ++j) {
			bool b = 0;
			for (int u : v[j]) if (m.count(u)) b = 1;
			if (b) {
				for (int u : v[j]) {
					if (tm.count(u) == 0) tm[u] = i;
				}
			}
		}
		m = tm;
	}

	int f;
	cin >> f;
	if (m.count(f) == 0) cout << -1;
	else cout << m[f];
}
#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		set<ii> s;
		int ans = 0;
		while (n--) {
			ii t;
			bool ins = false;
			cin >> t.first >> t.second;
			auto it = s.lower_bound(t);
			if (it == s.end() || it->second < t.second) ins = true;

			while (it != s.begin()) {
				it--;
				if (it->second < t.second) {
					auto jt = it;
					jt++;
					s.erase(it);
					it = jt;
				}
				else break;
			}

			if (ins) s.insert(t);
			ans += s.size();
		}
		cout << ans << '\n';
	}
}

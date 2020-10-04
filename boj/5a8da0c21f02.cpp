#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string a, b;
		map<string, int> m;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			m[b] += 1;
		}
		vector<int> v;
		for (auto it = m.begin(); it != m.end(); ++it) v.push_back(it->second);

		int ans = 1;
		for (int i = 0; i < v.size(); ++i) {
			ans *= v[i] + 1;
		}
		cout << ans - 1 << '\n';
	}
}
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s;
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		mp[s]++;
	}

	int k;
	cin >> k;

	int ans = 0;
	for (auto it: mp) {
		int cng = 0;
		for (int i = 0; i < m; ++i) {
			if (it.first[i] == '0') cng++;
		}
		if (k >= cng && (k - cng) % 2 == 0) ans = max(ans, it.second);
	}

	cout << ans;
}
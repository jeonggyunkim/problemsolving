#include <iostream>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	unordered_map<string, int> group;
	for (int i = 0; i < n; ++i) {
		string s;
		for (int j = 0; j < n; ++j) {
			cin >> t;
			s += '0' + t;
		}
		group[s]++;
	}

	long long ans = 1;

	for (auto it = group.begin(); it != group.end(); ++it) {
		if (it->second != 1) {
			for (int i = it->second - 1; i >= 1; --i) {
				ans *= i;
				ans %= 1000000007;
			}

			for (auto jt = group.begin(); jt != group.end(); ++jt) {
				bool sub = 1;
				int cnt = 0;
				for (int i = 0; i < n; ++i) {
					if (it->first[i] == '1' && jt->first[i] == '0') sub = 0;
					if (jt->first[i] == '1') cnt++;
				}
				if (sub && cnt == it->second + 1) {
					ans *= it->second;
					ans %= 1000000007;
				}
			}
		}
	}
	cout << ans;
}
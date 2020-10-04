#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

vector<ii> st[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	string s;
	for (int i = 0; i < k; ++i) {
		cin >> s;
		int start = 0;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'U') {
				st[i].push_back({start, j});
				start = j + 1;
			}
		}
		st[i].push_back({start, m});
		st[i].push_back({m + 1, m + 1});
	}

	string map;
	cin >> map;

	long long ans = 0;
	int low = m - 1, high = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		auto it = upper_bound(st[map[i] - 'A'].begin(), st[map[i] - 'A'].end(), ii(low, INF));
		it--;
		low = it->first;

		if (i == n - 1) high = m - 1;
		else {
			it = upper_bound(st[map[i] - 'A'].begin(), st[map[i] - 'A'].end(), ii(high + 1, INF));
			it--;
			if (it == st[map[i] - 'A'].begin()) break;
			it--;
			high = it->second;
		}
		ans += high - low + 1;
	}

	cout << ans;
}
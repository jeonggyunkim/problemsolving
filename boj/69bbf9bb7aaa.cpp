#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define INF (1LL << 60)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	map<int, pair<int, vector<int>>> mp;

	int w, p;
	for (int i = 0; i < n; ++i) {
		cin >> w >> p;
		mp[p].first += w;
		mp[p].second.push_back(w);
	}

	long long ans = INF, sum = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (sum + it->second.first >= m) {
			sort(it->second.second.begin(), it->second.second.end(), greater<int>());
			int loc = it->second.second[0], i = 1;
			while (loc + sum < m) {
				loc += it->second.second[i++];
			}
			ans = min(ans, (long long)it->first * i);
		}
		sum += it->second.first;
	}
	if (ans == INF) cout << -1;
	else cout << ans;
}
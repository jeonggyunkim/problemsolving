#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int card[200001];
int p[200001];
map<int, pair<vector<int>, vector<int>>> mp;

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) p[i] = i;

	for (int i = 1; i <= n; ++i) cin >> card[i];
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		mp[find(i)].first.push_back(i);
		mp[find(i)].second.push_back(card[i]);
	}
	long long ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		sort(it->second.first.begin(), it->second.first.end());
		sort(it->second.second.begin(), it->second.second.end());
		for (int i = 0; i < it->second.first.size(); ++i) {
			ans += abs(it->second.first[i] - it->second.second[i]);
		}
	}
	cout << ans;
}
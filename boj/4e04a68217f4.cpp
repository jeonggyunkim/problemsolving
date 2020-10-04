#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define SQ(a) ((a) * (a))
using namespace std;

typedef long long ll;
typedef pair<long long, pair<int, int>> lii;

int p[1010];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) p[i] = i;

	vector<pair<ll, ll>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	vector<lii> edge;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			edge.push_back({SQ(arr[i].first - arr[j].first) + SQ(arr[i].second - arr[j].second), {i, j}});
		}
	}

	sort(edge.begin(), edge.end());

	int a, b;
	while (m--) {
		cin >> a >> b;
		a--; b--;
		a = find(a); b = find(b);
		if (a != b) p[a] = b;
	}

	double ans = 0;
	for (int i = 0; i < edge.size(); ++i) {
		int a = find(edge[i].second.first);
		int b = find(edge[i].second.second);
		if (a != b) {
			p[a] = b;
			ans += sqrt(edge[i].first);
		}
	}

	cout.precision(2);
	cout << fixed << ans;
}
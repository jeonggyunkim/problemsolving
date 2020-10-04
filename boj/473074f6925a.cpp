#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int maxd, maxi;
vector<ii> v[10001];

void dfs(int i, int p, int d) {
	if (d > maxd) {
		maxd = d;
		maxi = i;
	}
	for (ii u: v[i]) {
		if (u.first != p) {
			dfs(u.first, i, d + u.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	dfs(0, -1, 0);
	maxd = 0;
	dfs(maxi, -1, 0);

	cout << maxd;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	vector<ii> time(v);
	for (int i = 0; i < v; ++i) {
		cin >> time[i].first;
		time[i].second = i;
	}

	sort(time.begin(), time.end());

	vector<vector<int>> dist(v, vector<int>(v, INF));
	vector<vector<int>> ans(v, vector<int>(v, INF));

	int a, b, c;
	while (e--) {
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = dist[b][a] = c;
		ans[a][b] = ans[b][a] = c;
	}

	for (int i = 0; i < v; ++i) dist[i][i] = ans[i][i] = 0;

	for (int k = 0; k < v; ++k) {
		int w = time[k].second;
		for (int i = 0; i < v; ++i) for (int j = 0; j < v; ++j) {
			dist[i][j] = min(dist[i][j], dist[i][w] + dist[w][j]);
			ans[i][j] = min(ans[i][j], dist[i][w] + time[k].first + dist[w][j]);
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << ans[a][b] << '\n';
	}
}

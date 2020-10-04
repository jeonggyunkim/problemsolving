#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int n, m, k;
int flowk, bMatch[1000];
bool Match[1000], kMatch[1000], visited[2010];
vector<vector<int>> edge;

bool dfs(int now) {
	visited[now] = 1;
	if (now == 0) {
		if (flowk < k && dfs(1)) {
			flowk++;
			return 1;
		}
		for (int i = 0; i < n; ++i) {
			if (!Match[i] && !visited[i + 2] && dfs(i + 2)) {
				Match[i] = 1;
				return 1;
			}
		}
	}
	else if (now == 1) {
		for (int i = 0; i < n; ++i) {
			if (!kMatch[i] && !visited[i + 2] && dfs(i + 2)) {
				kMatch[i] = 1;
				return 1;
			}
		}
	}
	else if (now >= 2 && now < n + 2) {
		if (kMatch[now - 2] && !visited[1] && dfs(1)) {
			kMatch[now - 2] = 0;
			return 1;
		}
		for (int u: edge[now - 2]) {
			if (!visited[u + n + 2] && bMatch[u] != now && dfs(u + n + 2)) {
				bMatch[u] = now;
				return 1;
			}
		}
	}
	else {
		if (bMatch[now - n - 2] == -1) return 1;
		else if (!visited[bMatch[now - n - 2]] && dfs(bMatch[now - n - 2])) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	edge.resize(n);
	int t, tt;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		while (t--) {
			cin >> tt;
			edge[i].push_back(tt - 1);
		}
	}
	memset(bMatch, -1, sizeof(bMatch));
	int ans = 0;
	while (dfs(0)) {
		ans++;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans;
}
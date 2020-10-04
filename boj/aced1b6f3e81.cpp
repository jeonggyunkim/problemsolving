#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<ii> edge[100001];

bool dfs(int start, int end, int w) {
	bool visited[100001] = {0};
	vector<int> v;
	v.push_back(start);
	v[start] = 1;
	while (!v.empty()) {
		int now = v.back(); v.pop_back();
		for (int i = 0; i < edge[now].size(); ++i) {
			ii t = edge[now][i];
			if (t.second >= w && !visited[t.first]) {
				v.push_back(t.first);
				visited[t.first] = 1;
			}
		}
	}
	return visited[end];
}

int main() {
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(ii(b, c));
		edge[b].push_back(ii(a, c));
	}

	int start, end;
	scanf("%d %d", &start, &end);

	int low = 1, high = (1 << 30), mid;
	while (1 < high - low) {
		mid = (low + high) / 2;
		if (dfs(start, end, mid)) low = mid;
		else high = mid;
	}
	printf("%d\n", low);
}
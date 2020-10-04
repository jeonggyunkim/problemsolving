#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int tc;
	scanf("%d", &tc);

	vector<int> edge[10000];
	for (int i = 0; i < 10000; ++i) {
		edge[i].push_back((i * 2) % 10000);
		edge[i].push_back((10000 + i - 1) % 10000);
		edge[i].push_back((i * 10 + i / 1000) % 10000);
		edge[i].push_back((i / 10 + (i % 10) * 1000) % 10000);
	}

	while (tc--) {
		int a, b;
		scanf("%d %d", &a, &b);

		ii visited[10000];
		memset(visited, -1, sizeof(visited));

		queue<int> q;
		visited[a].first = -3;
		q.push(a);

		while (!q.empty()) {
			int i = q.front(); q.pop();
			for (int j = 0; j < 4; ++j) {
				int t = edge[i][j];
				if (visited[t].first == -1) {
					visited[t].first = i;
					visited[t].second = j;
					q.push(t);
				}
			}
			if (visited[b].first != -1) break;
		}

		char ans[10000];
		int len = 0;
		int i = b;
		while (true) {
			ans[len++] = visited[i].second;
			i = visited[i].first;
			if (i == -3) break;
		}

		for (i = len - 1; i >= 0; --i) {
			if (ans[i] == 0) printf("D");
			else if (ans[i] == 1) printf("S");
			else if (ans[i] == 2) printf("L");
			else if (ans[i] == 3) printf("R");
		}
		printf("\n");
	}
}
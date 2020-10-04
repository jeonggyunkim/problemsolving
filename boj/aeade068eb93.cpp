#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n, m;
	vector<int> edge[1001];
	bool visit[1001] = {0};

	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int cnt = 0;
	stack<int> s;
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			cnt++;
			visit[i] = 1; s.push(i);
			while (!s.empty()) {
				int t = s.top(); s.pop();
				for (int j = 0; j < edge[t].size(); ++j) {
					int tt = edge[t][j];
					if (!visit[tt]) {
						visit[tt] = 1; s.push(tt);
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int v, e;
		char color[20001] = {0};
		scanf("%d %d", &v, &e);
		vector< vector<int> > edge(v + 1);

		int a, b;
		for (int i = 0; i < e; ++i) {
			scanf("%d %d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		bool cant = false;
		stack<int> s;
		for (int i = 1; i <= v; ++i) {
			if (!color[i]) {
				color[i] = 1; s.push(i);
				while (!s.empty()) {
					int t = s.top(); s.pop();
					for (int j = 0; j < edge[t].size(); ++j) {
						int tt = edge[t][j];
						if (!color[tt]) {
							color[tt] = -color[t]; s.push(tt);
						}
						else if (color[tt] == color[t]) {
							cant = true;
							break;
						}
					}
					if (cant) break;
				}
			}
			if (cant) break;
		}
		if (cant) printf("NO\n");
		else printf("YES\n");
	}
}
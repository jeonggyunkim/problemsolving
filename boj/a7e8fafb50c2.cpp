#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m;
	vector<ii> v[1001];
	scanf("%d %d", &n, &m);

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(ii(b, c));
	}

	scanf("%d %d", &a, &b);

	vector<int> min(n + 1, (1 << 30));
	min[a] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, a));
	while (!pq.empty()) {
		ii t = pq.top(); pq.pop();
		int d = t.first, u = t.second;
		if (min[u] < d) continue;
		for (int j = 0; j < v[u].size(); ++j) {
			ii tt = v[u][j];
			if (min[tt.first] > min[u] + tt.second) {
				min[tt.first] = min[u] + tt.second;
				pq.push(ii(min[tt.first], tt.first));
			}
		}
	}

	printf("%d\n", min[b]);
}
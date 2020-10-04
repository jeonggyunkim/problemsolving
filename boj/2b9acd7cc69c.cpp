#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1010];
int time[1010];
int ctime[1010];

int cal(int n) {
	if (ctime[n] >= 0) return ctime[n];
	int max = 0, t;
	for (int i = 0; i < v[n].size(); ++i) {
		t = cal(v[n][i]);
		if (t > max) max = t;
	}
	return ctime[n] = time[n] + max;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k, w;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			v[i].clear();
			scanf("%d", time + i);
			ctime[i] = -1;
		}
		int x, y;
		for (int i = 0; i < k; ++i) {
			scanf("%d %d", &x, &y);
			v[y].push_back(x);
		}
		scanf("%d", &w);
		printf("%d\n", cal(w));
	}
}
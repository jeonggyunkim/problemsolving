#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int n, max, maxi;
vector<ii> v[100001];
int d[100001];

void dfs(int n) {
	for (int i = 0; i < v[n].size(); ++i) {
		ii t = v[n][i];
		if (d[t.first] != -1) continue;
		d[t.first] = d[n] + t.second;
		if (d[n] + t.second > ::max) {
			::max = d[n] + t.second;
			maxi = t.first;
		}
		dfs(t.first);
	}
}

int main() {
	scanf("%d", &n);
	int num, a, b;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		while (scanf("%d", &a), a != -1) {
			scanf("%d", &b);
			v[num].push_back(ii(a, b));
		}
	}

	memset(d, -1, sizeof(d));
	d[1] = 0; ::max = -1;
	dfs(1);

	memset(d, -1, sizeof(d));
	d[maxi] = 0; ::max = -1;
	dfs(maxi);

	printf("%d\n", ::max);
}
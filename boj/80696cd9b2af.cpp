#include <iostream>
#include <vector>
using namespace std;

int p[100001] = {0};
vector<int> v[100001];

void dfs(int n) {
	for (int i = 0; i < v[n].size(); ++i) {
		if (p[v[n][i]] == 0) {
			p[v[n][i]] = n;
			dfs(v[n][i]);
		}
	}
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	p[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; ++i) printf("%d\n", p[i]);
}
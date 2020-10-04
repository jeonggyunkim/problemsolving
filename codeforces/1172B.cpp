#include <bits/stdc++.h>
#define MOD 998244353
#define N 200001
using namespace std;

vector<vector<int>> edge;
int cnt[N];
int child[N];
long long ans;

void cal(int cld, int ct) {
	for (int i = 1; i <= cld + 1; ++i) {
		ans = (ans * i) % MOD;
	}
}

int count(int n, int p) {
	int ret = 1;
	for (int u: edge[n]) {
		if (u != p) {
			ret += count(u, n);
			child[n]++;
		}
	}
	return cnt[n] = ret;
}

void dfs(int n, int p) {
	if (n != 0) cal(child[n], cnt[n]);
	for (int u: edge[n]) {
		if (u != p) dfs(u, n);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	edge.resize(n);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	count(0, -1);

	ans = n;
	for (int i = 1; i <= child[0]; ++i) {
		ans = (ans * i) % MOD;
	}
	dfs(0, -1);
	cout << ans;
}
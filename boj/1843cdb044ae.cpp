#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int p[100010];
int cnt[100010];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

long long merge(int a, int b) {
	a = find(a); b = find(b);
	if (a != b) {
		long long ret = (long long)cnt[a] * cnt[b];
		p[a] = b;
		cnt[b] += cnt[a];
		return ret;
	}
	else return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n; ++i) {
		p[i] = i;
		cnt[i] = 1;
	}

	vector<ii> edge(m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[i] = {a, b};
	}

	vector<int> rmv(q);
	vector<bool> toRmv(m, 0);
	for (int i = 0; i < q; ++i) {
		cin >> rmv[i];
		rmv[i]--;
		toRmv[rmv[i]] = 1;
	}

	for (int i = 0; i < m; ++i) {
		if (!toRmv[i]) merge(edge[i].first, edge[i].second);
	}

	long long ans = 0;
	for (int i = q - 1; i >= 0; --i) {
		a = edge[rmv[i]].first;
		b = edge[rmv[i]].second;
		ans += merge(a, b);
	}
	cout << ans;
}
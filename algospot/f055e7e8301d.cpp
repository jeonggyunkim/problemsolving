#include <iostream>
#include <vector>
using namespace std;

int route[200010];
int num[100010];
int stree[530010];
int d[100010];
int ind;

int build(int li, int ri, int i) {
	if (li == ri) return stree[i] = d[route[li]];
	int i1 = build(li, (li + ri) / 2, 2 * i + 1);
	int i2 = build((li + ri) / 2 + 1, ri, 2 * i + 2);
	return stree[i] = min(i1, i2);
}

int find(int l, int r, int li, int ri, int i) {
	if (l == li && r == ri) return stree[i];
	int mid = (li + ri) / 2;
	if (r <= mid) return find(l, r, li, mid, 2 * i + 1);
	if (l >= mid + 1) return find(l, r, mid + 1, ri, 2 * i + 2);
	int r1 = find(l, mid, li, mid, 2 * i + 1);
	int r2 = find(mid + 1, r, mid + 1, ri, 2 * i + 2);
	return min(r1, r2);
}

void travel(int n, int depth, vector<vector<int>>& edge) {
	d[n] = depth;
	num[n] = ind;
	route[ind++] = n;
	for (int i : edge[n]) {
		travel(i, depth + 1, edge);
		route[ind++] = n;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		ind = 0;
		vector<vector<int>> v(n);
		int a, b;
		for (int i = 1; i < n; ++i) {
			cin >> a;
			v[a].push_back(i);
		}

		travel(0, 0, v);
		build(0, 2 * n - 2, 0);

		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			a = num[a];
			b = num[b];
			if (a > b) swap(a, b);

			int t = find(a, b, 0, 2 * n - 2, 0);
			cout << d[route[a]] + d[route[b]] - 2 * t << '\n';
		}
	}
}

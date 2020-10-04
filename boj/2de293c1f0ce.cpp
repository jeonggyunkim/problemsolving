#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define N 100010
#define MOD 1000000000
using namespace std;

int p[N], sz[N];

int find(int i) {
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		p[a] = b;
		sz[b] += sz[a];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		sz[i] = 1;
	}

	vector<tuple<int, int, int>> arr(m);
	int a, b, w;
	long long total = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		arr[i] = {w, a, b};
		total += w;
	}

	sort(arr.rbegin(), arr.rend());

	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		w = get<0>(arr[i]);
		a = get<1>(arr[i]);
		b = get<2>(arr[i]);
		if (find(a) != find(b)) {
			ans += (((total * sz[find(a)]) % MOD) * sz[find(b)]) % MOD;
			ans %= MOD;
			merge(a, b);
		}
		total -= w;
	}

	cout << ans;
}
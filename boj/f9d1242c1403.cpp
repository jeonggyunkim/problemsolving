#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#define N 1010
#define MOD 1000000007
using namespace std;

typedef pair<int, int> ii;

int arr[100], a[N], tree[N];
ii to_sort[N];
int n;

void insert(int i, int d) {
	while (i <= n) {
		(tree[i] += d) %= MOD;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		(ret += tree[i]) %= MOD;
		i &= (i - 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int test = 1; test <= tc; ++test) {
		memset(tree, 0, sizeof(tree));
		long long m, x, y, z;
		cin >> n >> m >> x >> y >> z;
		for (int i = 0; i < m; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; ++i) {
			int ind = i % m;
			a[i] = arr[ind];
			to_sort[i] = {a[i], i};
			arr[ind] = (x * arr[ind] + y * (i + 1)) % z;
		}

		sort(to_sort, to_sort + n);

		int ind = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || to_sort[i].first != to_sort[i - 1].first) {
				ind++;
			}
			a[to_sort[i].second] = ind;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int d = get(a[i] - 1);
			d++;
			(ans += d) %= MOD;
			insert(a[i], d);
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}
}
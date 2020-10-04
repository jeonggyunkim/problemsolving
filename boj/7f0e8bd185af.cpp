#include <iostream>
using namespace std;

int n, tree[100010];

void set(int i) {
	while (i <= n) {
		tree[i]++;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i &= i - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int t;
	int ans[100010];
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		int low = 0, high = n, mid;
		while (high - low > 1) {
			mid = (high + low) / 2;
			int r = mid - get(mid);
			if (r > t) high = mid;
			else low = mid;
		}
		set(high);
		ans[high] = i;
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}
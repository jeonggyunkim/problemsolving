#include <iostream>
#include <memory.h>
using namespace std;

int tree[1000001];

void set(int i) {
	while (i < 1000001) {
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

	int tc;
	cin >> tc;
	while (tc--) {
		memset(tree, 0, sizeof(tree));
		int n, t;
		cin >> n;
		int arr[50000];
		for (int i = 0; i < n; ++i) cin >> arr[i];

		long long ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans += get(arr[i]);
			set(arr[i] + 1);
		}

		cout << ans << '\n';
	}
}

#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int n;
int tree[100010];

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
	int arr[100010];
	int ans[100010] = {};

	for (int i = 0; i < n; ++i) cin >> arr[i];
	int nn = n / 2;

	for (int i = 0; i < n; ++i) {
		if (arr[i] <= nn) {
			ans[arr[i]] = get(n - arr[i] + 1) - get(arr[i]);
		}
		set(arr[i]);
	}
	memset(tree, 0, sizeof(tree));

	if (n & 1) nn += 2;
	else nn++;

	for (int i = n - 1; i >= 0; --i) {
		if (arr[i] >= nn) {
			ans[arr[i]] = get(arr[i] - 1) - get(n - arr[i] + 1);
		}
		set(arr[i]);
	}

	for (int i = 1; i <= n / 2; ++i) {
		cout << ans[i] << '\n';
		cout << ans[n - i + 1] << '\n';
	}
	if (n & 1) cout << ans[n / 2 + 1] << '\n';
}
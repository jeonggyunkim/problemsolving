#include <iostream>
#include <memory.h>
using namespace std;

long long n, tree[100010];

void set(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

long long get(int i) {
	long long ret = 0;
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
	int temp[100010];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i] = n + 1 - arr[i];
	}
	for (int i = 0; i < n; ++i) {
		temp[i] = get(arr[i] - 1);
		set(arr[i], 1);
	}
	memset(tree, 0, sizeof(tree));
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += get(arr[i] - 1);
		set(arr[i], temp[i]);
	}
	cout << ans;
}
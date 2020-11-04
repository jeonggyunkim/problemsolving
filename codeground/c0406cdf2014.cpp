#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

ii arr[100000];
int tree[100001];
int treesz;

void insert(int i) {
	while (i <= treesz) {
		tree[i] += 1;
		i += (i & -i);
	}
}

int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
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
		cin >> treesz;

		for (int i = 0; i < treesz; ++i) {
			cin >> arr[i].first;
			arr[i].second = i + 1;
		}

		sort(arr, arr + treesz, greater<ii>());

		long long ans = 0;
		for (int i = 0; i < treesz; ++i) {
			ans += get(arr[i].second);
			insert(arr[i].second);
		}

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}

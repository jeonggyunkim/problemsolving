#include <iostream>
#include <vector>
using namespace std;

int n = 500000, tree[500001];

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

	int n, t;
	cin >> n;
	vector<int> index(1000001);

	for (int i = 1; i <= n; ++i) {
		cin >> t;
		index[t] = i;
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		set(index[t]);
		ans += i - get(index[t]);
	}
	cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int n, tree[100010];

void upd(int i) {
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
	vector<long long> ans(n + 1);
	vector<ii> task(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> task[i].first;
		task[i].second = i;
	}
	sort(task.begin() + 1, task.end());

	long long total = 0;
	for (int i = 1; i <= n; ++i) {
		long long p = task[i].first, q = task[i].second;
		int t = q - get(q);
		ans[q] = p * t;
		ans[q] += (p - 1) * (n - get(n) - t) + total;
		total += p;
		upd(q);
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}

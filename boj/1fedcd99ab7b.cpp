#include <iostream>
#define N 100100
using namespace std;

int l[N], r[N];
pair<int, int> loc[N];

int n;
int tree[N];

void insert(int i, int d) {
	while (i <= n) {
		tree[i] += d;
		i += (i & -i);
	}
}

long long get(int i) {
	long long ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
		loc[l[i]].first = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
		loc[r[i]].second = i;
	}

	long long ans = 0;
	for (int i = n; i >= 1; --i) {
		ans += get(loc[l[i]].second);
		insert(loc[l[i]].second, 1);
	}

	long long now = ans;

	for (int i = n; i >= 1; --i) {
		now -= n - loc[l[i]].second;
		now += loc[l[i]].second - 1;
		ans = min(ans, now);
	}
	for (int i = n; i >= 1; --i) {
		now -= n - loc[r[i]].first;
		now += loc[r[i]].first - 1;
		ans = min(ans, now);
	}
	cout << ans;
}
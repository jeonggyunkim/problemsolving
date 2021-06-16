#include <iostream>
#include <memory.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int treesz;
int tree[2501];
int x[2500], y[2500];

void insert(int i, int d) {
	while (i <= treesz) {
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

	int n;
	cin >> n;
	treesz = n;

	vector<ii> dot(n);
	map<int, int> y_re;
	for (int i = 0; i < n; ++i) {
		cin >> dot[i].first >> dot[i].second;
		y_re[dot[i].second] = 0;
	}
	int cnt = 1;
	for (auto it = y_re.begin(); it != y_re.end(); ++it) it->second = cnt++;
	for (int i = 0; i < n; ++i) {
		dot[i].second = y_re[dot[i].second];
	}
	sort(dot.begin(), dot.end());

	long long ans = n + 1;
	for (int i = 0; i < n; ++i) {
		memset(tree, 0, sizeof(tree));
		insert(dot[i].second, 1);
		for (int j = i + 1; j < n; ++j) {
			insert(dot[j].second, 1);

			int mi = min(dot[i].second, dot[j].second);
			int mx = max(dot[i].second, dot[j].second);
			ans += (long long)(1 + get(treesz) - get(mx)) * (1 + get(mi - 1));
		}
	}
	cout << ans;
}
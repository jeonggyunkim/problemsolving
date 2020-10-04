#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int n, cnt;
vector<int> tree(500010, INF);
int index[500010];
ii info[500010];

void set(int i, int s) {
	while (i <= n) {
		tree[i] = min(tree[i], s);
		i += (i & -i);
	}
}

int get(int i) {
	int ret = INF;
	while (i) {
		ret = min(tree[i], ret);
		i &= i - 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> index[i];
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		info[t].first = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> t;
		info[t].second= i;
	}

	for (int i = 0; i < n; ++i) {
		if (get(info[index[i]].first) >= info[index[i]].second) {
			cnt++;
			set(info[index[i]].first, info[index[i]].second);
		}
	}
	cout << cnt;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int, int> i4;

int tree[100001];
int treesz = 100000;

void insert(int i) {
	while (i <= treesz) {
		tree[i]++;
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

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end(), greater<ii>());

	int q;
	cin >> q;
	vector<i4> queries(q);
	vector<int> ans(q);
	int a, b, c;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b >> c;
		queries[i] = i4(c, a, b, i);
	}
	sort(queries.begin(), queries.end(), greater<i4>());

	int j = 0;
	for (int i = 0; i < q; ++i) {
		while (j < n && arr[j].first > get<0>(queries[i])) {
			insert(arr[j].second);
			j++;
		}
		ans[get<3>(queries[i])] = get(get<2>(queries[i])) - get(get<1>(queries[i]) - 1);
	}

	for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}
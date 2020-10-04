#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define SQ(x) ((x) * (x))
using namespace std;

int p[2000];
int x[2000], y[2000];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		p[i] = i;
	}

	vector<tuple<int, int, int>> arr;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cost = SQ(x[i] - x[j]) + SQ(y[i] - y[j]);
			if (cost >= c) {
				arr.push_back({cost, i, j});
			}
		}
	}

	sort(arr.begin(), arr.end());
	long long cnt = 0, ans = 0;
	for (int i = 0; i < arr.size(); ++i) {
		int cost = get<0>(arr[i]);
		int x = get<1>(arr[i]);
		int y = get<2>(arr[i]);
		if (find(x) != find(y)) {
			merge(x, y);
			cnt++;
			ans += cost;
		}
	}
	if (cnt != n - 1) cout << -1;
	else cout << ans;
}
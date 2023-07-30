#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> edge[50];
	int a, b;
	while (cin >> a >> b, a != -1 && b != -1) {
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int d[50], ans = 99;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		memset(d, -1, sizeof(d));
		queue<int> q;
		q.push(i);
		d[i] = 0;
		int mx = -1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int u : edge[now]) {
				if (d[u] == -1) {
					d[u] = d[now] + 1;
					mx = max(mx, d[u]);
					q.push(u);
				}
			}
		}
		if (mx < ans) {
			ans = mx;
			arr.clear();
			arr.push_back(i + 1);
		}
		else if (mx == ans) arr.push_back(i + 1);
	}
	cout << ans << ' ' << arr.size() << '\n';
	for (int u : arr) cout << u << ' ';
}
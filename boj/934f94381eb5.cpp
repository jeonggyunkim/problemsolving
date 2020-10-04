#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int l[300], r[300];
bool edge[300][300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (max(l[i], l[j]) <= min(r[i], r[j])) {
				edge[i][j] = edge[j][i] = 1;
			}
		}
	}

	int q;
	cin >> q;

	int a, b;
	while (q--) {
		cin >> a >> b;
		a--; b--;
		int d[300];
		memset(d, -1, sizeof(d));
		queue<int> q;
		q.push(a);
		d[a] = 0;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i < n; ++i) {
				if (edge[now][i] && d[i] == -1) {
					d[i] = d[now] + 1;
					q.push(i);
				}
			}
			if (d[b] != -1) break;
		}
		cout << d[b] << '\n';
	}
}
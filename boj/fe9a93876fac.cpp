#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int d[100001];
	int p[100001];
	memset(d, -1, sizeof(d));

	if (n >= k) {
		cout << n - k << '\n';
		for (int i = n; i >= k; --i) cout << i << ' ';
		return 0;
	}

	queue<int> q;
	q.push(n);
	d[n] = 0;
	p[n] = -1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int next = now + 1;
		if (next <= 100000 && d[next] == -1) {
			d[next] = d[now] + 1;
			p[next] = now;
			q.push(next);
		}
		next = now - 1;
		if (next >= 0 && d[next] == -1) {
			d[next] = d[now] + 1;
			p[next] = now;
			q.push(next);
		}
		next = 2 * now;
		if (next <= 100000 && d[next] == -1) {
			d[next] = d[now] + 1;
			p[next] = now;
			q.push(next);
		}
		if (d[k] != -1) {
			cout << d[k] << '\n';

			vector<int> ans = {k};
			while (p[k] != -1) {
				ans.push_back(p[k]);
				k = p[k];
			}
			for (int i = ans.size() - 1; i >= 0; --i) {
				cout << ans[i] << ' ';
			}
			return 0;
		}
	}
}
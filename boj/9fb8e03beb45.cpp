#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int d[100001];
	int cnt[100001] = {};
	memset(d, -1, sizeof(d));

	if (n >= k) {
		cout << n - k << '\n' << 1;
		return 0;
	}

	queue<int> q;
	q.push(n);
	d[n] = 0;
	cnt[n] = 1;

	bool brk = 0;
	int brkd;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (brk && d[now] != brkd) break;

		int next = now + 1;
		if (next <= 100000) {
			if (d[next] == -1) {
				d[next] = d[now] + 1;
				cnt[next] = cnt[now];
				q.push(next);
			}
			else if (d[next] == d[now] + 1) cnt[next] += cnt[now];
		}
		next = now - 1;
		if (next >= 0) {
			if (d[next] == -1) {
				d[next] = d[now] + 1;
				cnt[next] = cnt[now];
				q.push(next);
			}
			else if (d[next] == d[now] + 1) cnt[next] += cnt[now];
		}
		next = 2 * now;
		if (next <= 100000) {
			if (d[next] == -1) {
				d[next] = d[now] + 1;
				cnt[next] = cnt[now];
				q.push(next);
			}
			else if (d[next] == d[now] + 1) cnt[next] += cnt[now];
		}
		if (d[k] != -1) {
			brkd = d[now];
			brk = 1;
		}
	}
	cout << d[k] << '\n' << cnt[k];
}

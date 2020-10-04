#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int d[100001];
	memset(d, -1, sizeof(d));

	if (n >= k) {
		cout << n - k;
		return 0;
	}

	queue<int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int next = now + 1;
		if (next >= 0 && next <= 100000 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}
		next = now - 1;
		if (next >= 0 && next <= 100000 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}
		next = 2 * now;
		if (next >= 0 && next <= 100000 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}
		if (d[k] != -1) {
			cout << d[k];
			return 0;
		}
	}
}
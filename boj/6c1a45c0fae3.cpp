#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int d[100001];
queue<int> q;

void insert(int n, int dn) {
	while (n <= 100000 && d[n] == -1) {
		d[n] = dn;
		q.push(n);
		n *= 2;
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	memset(d, -1, sizeof(d));

	if (n >= k) {
		cout << n - k;
		return 0;
	}

	insert(n, 0);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int next = now + 1;
		if (next >= 0 && next <= 100000 && d[next] == -1) {
			insert(next, d[now] + 1);
		}
		next = now - 1;
		if (next >= 0 && next <= 100000 && d[next] == -1) {
			insert(next, d[now] + 1);
		}
		if (d[k] != -1) {
			cout << d[k];
			return 0;
		}
	}
}
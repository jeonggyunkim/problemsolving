#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
	int n;
	cin >> n;

	int start = 0, final = (1 << (2 * n)) - 1;

	vector<int> hanoi(1 << (2 * n), 0);
	queue<int> q;

	hanoi[final] = -1;
	q.push(final);

	int a, b;
	for (int i = 0; i < 4; ++i) {
		cin >> a;
		while (a--) {
			cin >> b;
			b--;
			start |= (i << (2 * b));
		}
	}
	hanoi[start] = 1;
	q.push(start);

	if (start == final) {
		cout << 0;
		return;
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		int d = hanoi[now];

		int minblock[4] = { 20, 20, 20, 20 };
		for (int i = 0; i < n; ++i) {
			int t = (now >> (2 * i)) & 3;
			minblock[t] = min(minblock[t], i);
		}

		for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
			if (i == j) continue;
			if (minblock[i] < minblock[j]) {
				int next = now & ~(3 << (2 * minblock[i]));
				next = next | (j << (2 * minblock[i]));
				if (hanoi[next] == 0) {
					if (d > 0) hanoi[next] = d + 1;
					else hanoi[next] = d - 1;
					q.push(next);
				}
				else if ((hanoi[next] > 0) ^ (d > 0)) {
					cout << abs(hanoi[next] - d) - 1 << '\n';
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		solve();
	}
}

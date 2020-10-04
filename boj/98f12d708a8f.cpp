#include <iostream>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;

int arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<int> s;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (arr[i] + arr[j] <= n) {
				s.insert(arr[i] + arr[j]);
			}
		}
	}

	int d[10001];
	memset(d, -1, sizeof(d));

	queue<int> q;
	q.push(n);
	d[n] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int u: s) {
			if (now - u >= 0 && d[now - u] == -1) {
				d[now - u] = d[now] + 1;
				q.push(now - u);
			}
		}
	}

	cout << d[0];
}
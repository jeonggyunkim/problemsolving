#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int p[1000010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(p, -1, sizeof(p));

	int n;
	cin >> n;

	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now % 3 == 0 && now >= 3 && p[now / 3] == -1) {
			p[now / 3] = now;
			q.push(now / 3);
		}
		if (now % 2 == 0 && now >= 2 && p[now / 2] == -1) {
			p[now / 2] = now;
			q.push(now / 2);
		}
		if (now >= 2 && p[now - 1] == -1) {
			p[now - 1] = now;
			q.push(now - 1);
		}
	}

	vector<int> ans;
	int i = 1;
	while (i != n) {
		ans.push_back(i);
		i = p[i];
	}
	ans.push_back(n);

	cout << ans.size() - 1 << '\n';
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
}
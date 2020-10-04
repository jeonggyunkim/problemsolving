#include <iostream>
using namespace std;

int nxt[200000];
int vis[200000];
int cnt, cycle;

int search(int i) {
	if (vis[i] < 0) {
		cycle = vis[i];
		return vis[i] - cnt;
	}
	else if (vis[i] > 0) {
		return vis[i] + 1;
	}
	else {
		vis[i] = cnt--;
		int t = search(nxt[i]);
		if (vis[i] >= cycle) {
			vis[i] = t;
			return vis[i] + 1;
		}
		else {
			vis[i] = t;
			return vis[i];
		}
	}
}

int sum(int n) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		nxt[i] = (i + sum(i + 1)) % n;
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			cnt = -1;
			cycle = -987654321;
			search(i);
		}
	}

	int ans = -1;
	for (int i = 0; i < n; ++i) ans = max(ans, vis[i]);
	cout << ans;
}
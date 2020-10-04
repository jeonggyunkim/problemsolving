#include <iostream>
#include <vector>
#include <queue>
#define N 1000100
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> prime(N, 1);
	prime[0] = prime[1] = 0;
	for (int i = 0; i * i < N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) prime[j] = 0;
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;

		int small = -1;
		for (int i = b; i >= a; --i) if (prime[i]) small = i;

		if (small == -1) cout << -1 << '\n';
		else if (n <= small) cout << small - n << '\n';
		else {
			queue<ii> q;
			vector<bool> vis(N, 0);
			q.push({n, 0});
			vis[n] = 1;
			while (!q.empty()) {
				ii now = q.front();
				q.pop();
				int t = now.first, d = now.second;
				if (t >= a && t <= b && prime[t]) {
					cout << d << '\n';
					break;
				}
				if (t && !vis[t - 1]) {
					q.push({t - 1, d + 1});
					vis[t - 1] = 1;
				}
				if (!vis[t + 1]) {
					q.push({t + 1, d + 1});
					vis[t + 1] = 1;
				}
				if (!vis[t / 2]) {
					q.push({t / 2, d + 1});
					vis[t / 2] = 1;
				}
				if (!vis[t / 3]) {
					q.push({t / 3, d + 1});
					vis[t / 3] = 1;
				}
			}
		}
	}
}
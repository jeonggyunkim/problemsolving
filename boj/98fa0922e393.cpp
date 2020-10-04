#include <iostream>
#include <queue>
using namespace std;

int arr[10000];
int dp[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = 98765;
	}

	int a, b;
	cin >> a >> b;
	a--; b--;

	queue<int> q;
	dp[a] = 0;
	q.push(a);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = now - (now / arr[now]) * arr[now]; i < n; i += arr[now]) {
			if (dp[now] + 1 < dp[i]) {
				dp[i] = dp[now] + 1;
				q.push(i);
			}
		}
	}

	if (dp[b] == 98765) cout << -1;
	else cout << dp[b];
}
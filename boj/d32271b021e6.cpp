#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, t, mini = (1LL << 60);
	cin >> n;

	priority_queue<long long> pq;
	while (n--) {
		cin >> t;
		pq.push(t);
		mini = min(mini, t);
	}

	long long prev = -1;
	int ans = 0;
	while (!pq.empty()) {
		long long now = pq.top();
		pq.pop();
		if (now == prev) continue;
		prev = now;
		ans++;
		if (mini == now) continue;
		now /= 2;
		if (now) {
			pq.push(now);
			mini = min(mini, now);
		}
	}
	cout << ans;
}
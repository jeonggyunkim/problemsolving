#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	long long a, b, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		pq.push(t);
	}

	while (m--) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	long long ans = 0;
	while (!pq.empty()) {
		t = pq.top(); pq.pop();
		ans += t;
	}
	cout << ans;
}
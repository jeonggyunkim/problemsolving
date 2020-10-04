#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;

		priority_queue<int> low;
		priority_queue<int, vector<int>, greater<int>> high;

		long long now = 1983;
		int sum = 1983;
		low.push(now);
		now = (now * a + b) % 20090711;

		for (int i = 1; i < n; ++i) {
			if (i & 1) {
				if (now <= low.top()) {
					low.push(now);
					high.push(low.top()); low.pop();
				}
				else high.push(now);
			}
			else {
				if (now <= low.top()) low.push(now);
				else {
					high.push(now);
					low.push(high.top()); high.pop();
				}
			}
			now = (now * a + b) % 20090711;
			sum = (sum + low.top()) % 20090711;
		}
		cout << sum << '\n';
	}
}

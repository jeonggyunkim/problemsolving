#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	priority_queue<int> pos, neg;
	int z = 0;
	while (n--) {
		cin >> t;
		if (t == 0) z++;
		else if (t > 0) pos.push(t);
		else neg.push(-t);
	}

	long long ans = 0;
	while (neg.size() >= 2) {
		long long now;
		now = neg.top(); neg.pop();
		now *= neg.top(); neg.pop();
		ans += now;
	}

	while (pos.size() >= 2) {
		long long a, b;
		a = pos.top(); pos.pop();
		b = pos.top(); pos.pop();
		if (b == 1) {
			ans += a;
			ans += b;
			while (pos.size()) {
				ans += pos.top();
				pos.pop();
			}
		}
		else {
			ans += a * b;
		}
	}
	if (pos.size()) ans += pos.top();
	if (neg.size() && z == 0) ans -= neg.top();
	cout << ans;
}
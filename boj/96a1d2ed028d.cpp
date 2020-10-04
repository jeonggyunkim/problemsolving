#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	priority_queue<int> low;
	priority_queue<int, vector<int>, greater<int>> high;
	cin >> t;
	low.push(t);
	cout << t << '\n';
	for (int i = 1; i < n; ++i) {
		cin >> t;
		if (i & 1) {
			if (t >= low.top()) high.push(t);
			else {
				high.push(low.top());
				low.pop();
				low.push(t);
			}
		}
		else {
			if (t <= high.top()) low.push(t);
			else {
				low.push(high.top());
				high.pop();
				high.push(t);
			}
		}
		cout << low.top() << '\n';
	}
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	string s;
	queue<int> q;
	while (m--) {
		cin >> s >> t;
		if (s[0] == 'd') {
			n += t;
			while (!q.empty()) {
				if (q.front() <= n) {
					n -= q.front();
					q.pop();
				}
				else break;
			}
		}
		else if (s[0] == 'p') {
			if (n >= t) n -= t;
		}
		else {
			if (q.empty() && t <= n) n -= t;
			else q.push(t);
		}
	}
	cout << n;
}
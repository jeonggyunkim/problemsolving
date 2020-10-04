#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	char op[10];
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		cin >> op;
		if (op[0] == 's') cout << q.size() << '\n';
		else if (op[0] == 'e') cout << q.empty() << '\n';
		else if (op[0] == 'f') cout << (q.empty() ? -1 : q.front()) << '\n';
		else if (op[0] == 'b') cout << (q.empty() ? -1 : q.back()) << '\n';
		else {
			if (op[1] == 'u') {
				int t;
				cin >> t;
				q.push(t);
			}
			else {
				cout << (q.empty() ? -1 : q.front()) << '\n';
				if (!q.empty()) q.pop();
			}
		}
	}
}
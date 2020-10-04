#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	cout << '<';
	for (int i = 1; i < n; ++i) {
		for (int i = 0; i < m - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << '>';
}
#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}

	cout << '<';
	for (int i = 1; i < N; ++i) {
		for (int i = 0; i < M - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << '>';
}
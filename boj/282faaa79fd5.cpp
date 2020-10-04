#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s;
	n -= s + 1;

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	cin >> m;

	vector<int> arr(m);
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		pq.push({0, i});
	}

	while (n--) {
		ii now = pq.top();
		pq.pop();

		pq.push({now.first + arr[now.second], now.second});
	}

	cout << pq.top().second + 1;
}
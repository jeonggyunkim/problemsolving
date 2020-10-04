#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ii> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	int ind = 0;
	for (int day = 1; day <= n; ++day) {
		while (ind < n && arr[ind].first <= day) pq.push(arr[ind++].second);
		while (pq.size() > day) pq.pop();
	}

	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}
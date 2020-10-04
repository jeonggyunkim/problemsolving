#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int convert(int a, int b) {
	static int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	return month[a] + b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b, c, d, e, f;
	int start = convert(3, 1), end = convert(12, 1);
	vector<ii> arr;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		e = convert(a, b);
		f = convert(c, d);
		if (f >= end) {
			pq.push(e);
		}
		else arr.push_back({f, e});
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	while (1) {
		if (end <= start) break;
		if (pq.empty() || pq.top() >= end) {
			cout << 0;
			return 0;
		}
		end = pq.top();
		pq.pop();
		ans++;
		while (!arr.empty() && arr.back().first >= end) {
			pq.push(arr.back().second);
			arr.pop_back();
		}
	}
	cout << ans;
}
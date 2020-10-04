#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> ii;

vector<ii> arr;

long long ccw(ii& p, ii& q, ii& r) {
	return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

long long dist(ii& a, ii& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());
	sort(arr.begin() + 1, arr.end(), [](ii& x, ii& y) {
			return ccw(arr[0], x, y) > 0 || (ccw(arr[0], x, y) == 0 && (dist(arr[0], x) < dist(arr[0], y)));
			});

	stack<int> s;
	s.push(0); s.push(1);

	int next = 2;
	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(arr[first], arr[second], arr[next]) > 0) {
				s.push(second);
				break;
			}
		}

		s.push(next++);
	}

	cout << s.size();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> i3;

vector<i3> arr;

long long ccw(i3& p, i3& q, i3& r) {
	return (get<0>(q) - get<0>(p)) * (get<1>(r) - get<1>(p)) - (get<1>(q) - get<1>(p)) * (get<0>(r) - get<0>(p));
}

long long dist(i3& a, i3& b) {
	return abs(get<0>(a) - get<0>(b)) + abs(get<1>(a) - get<1>(b));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		arr.resize(n);

		for (int i = 0; i < n; ++i) {
			cin >> get<0>(arr[i]) >> get<1>(arr[i]);
			get<2>(arr[i]) = i;
		}

		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), [](i3& x, i3& y) {
			return ccw(arr[0], x, y) > 0 || (ccw(arr[0], x, y) == 0 && dist(arr[0], x) < dist(arr[0], y));
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

				if (ccw(arr[first], arr[second], arr[next]) >= 0) {
					s.push(second);
					break;
				}
			}
			s.push(next++);
		}

		vector<bool> used(n, 0);
		while (s.size() >= 2) {
			int first = s.top(); s.pop();
			int second = s.top();
			if (arr[first] > arr[second]) {
				s.push(first);
				break;
			}
		}

		while (!s.empty()) {
			cout << get<2>(arr[s.top()]) << ' ';
			used[s.top()] = 1;
			s.pop();
		}

		vector<i3> left;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) left.push_back(arr[i]);
		}
		sort(left.begin(), left.end());
		for (int i = 0; i < left.size(); ++i) {
			cout << get<2>(left[i]) << ' ';
		}
		cout << '\n';
	}
}
#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<iii> arr;

int ccw(iii& p, iii& q, iii& r) {
	return (get<0>(q) - get<0>(p)) * (get<1>(r) - get<1>(p)) - (get<1>(q) - get<1>(p)) * (get<0>(r) - get<0>(p));
}

int dist(iii& a, iii& b) {
	return (get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b)) + (get<1>(a) - get<1>(b)) * (get<1>(a) - get<1>(b));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr.resize(n);
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		arr[i] = {a, b, i};
	}

	vector<int> ans(n, 0);
	int h = 1;
	while (1) {
		if (arr.size() <= 2) break;
		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), [](iii& x, iii& y) {
			return ccw(arr[0], x, y) > 0 || (ccw(arr[0], x, y) == 0 && (dist(arr[0], x) < dist(arr[0], y)));
			});

		stack<int> s;
		s.push(0); s.push(1);

		int next = 2;
		while (next < arr.size()) {
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
		if (s.size() <= 2) break;
		vector<bool> used(arr.size(), 0);
		vector<iii> temp(arr.size() - s.size());
		while (!s.empty()) {
			used[s.top()] = 1;
			ans[get<2>(arr[s.top()])] = h;
			s.pop();
		}
		h++;
		int j = 0;
		for (int i = 0; i < arr.size(); ++i) {
			if (!used[i]) temp[j++] = arr[i];
		}
		arr = temp;
	}
	for (int u: ans) cout << u << ' ';
}

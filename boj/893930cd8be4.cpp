#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

vector<ii> arr;

int ccw(ii& p, ii& q, ii& r) {
	return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

int dist(ii& a, ii& b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

double dist2(int a, int b) {
 	double t = sqrt((arr[a].first - arr[b].first) * (arr[a].first - arr[b].first) + (arr[a].second - arr[b].second) * (arr[a].second - arr[b].second));
	return t;
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
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	sort(arr.begin() + 1, arr.end(), [](ii& x, ii& y) {
			return ccw(arr[0], x, y) > 0 || (ccw(arr[0], x, y) == 0 && (dist(arr[0], x) < dist(arr[0], y)));
			});

	vector<int> s;
	s.push_back(0); s.push_back(1);

	int next = 2;
	while (next < n) {
		while (s.size() >= 2) {
			int first, second;
			second = s.back();
			s.pop_back();
			first = s.back();

			if (ccw(arr[first], arr[second], arr[next]) > 0) {
				s.push_back(second);
				break;
			}
		}

		s.push_back(next++);
	}

	double ans = -1;
	for (int i = 0; i <s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			ans = max(ans, dist2(s[i], s[j]));
		}
	}
	cout.precision(15);
	cout << ans;
}
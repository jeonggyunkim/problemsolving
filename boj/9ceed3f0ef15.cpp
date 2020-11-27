#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#define eps 1e-7
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

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

	int n, test = 1;
	while (cin >> n, n) {
		arr.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), [](ii& x, ii& y) {
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

				if (ccw(arr[first], arr[second], arr[next]) > 0) {
					s.push(second);
					break;
				}
			}

			s.push(next++);
		}

		vector<int> conv;
		while (s.size()) {
			conv.push_back(s.top());
			s.pop();
		}

		int ans = INF;
		for (int j = 0; j < conv.size(); ++j) {
			int loc = -1;
			for (int i = 0; i < conv.size(); ++i) {
				int now[3] = {conv[i], conv[j], conv[(j + 1) % conv.size()]};
				long long area = 0;
				for (int k = 0; k < 3; ++k) {
					area += arr[now[k]].first * arr[now[(k + 1) % 3]].second;
					area -= arr[now[k]].second * arr[now[(k + 1) % 3]].first;
				}
				area = abs(area);
				if (area != 0) {
					double d = sqrt(dist(arr[now[1]], arr[now[2]]));
					loc = max(loc, (int)(area / d * 100 - eps) + 1);
				}
			}
			ans = min(ans, loc);
		}
		cout << "Case " << test++ << ": " << ans / 100 << '.';
		if (ans % 100 < 10) cout << '0';
		cout << ans % 100 << endl;
	}
}
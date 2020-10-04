#include <iostream>
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

long long area(ii a, ii b, ii c) {
	long long ret = 0;
	ret += a.first * b.second;
	ret += b.first * c.second;
	ret += c.first * a.second;
	ret -= b.first * a.second;
	ret -= c.first * b.second;
	ret -= a.first * c.second;
	return abs(ret);
}

long long ternary(int i, int j, int low, int high, vector<int>& s) {
	while (high - low >= 3) {
		int mid1 = (2 * low + high) / 3;
		int mid2 = (low + 2 * high) / 3;
		long long area1 = area(arr[s[i]], arr[s[j]], arr[s[mid1]]);
		long long area2 = area(arr[s[i]], arr[s[j]], arr[s[mid2]]);
		if (area1 > area2) high = mid2;
		else low = mid1;
	}
	long long ret = 0;
	for (int k = low; k <= high; ++k) {
		ret = max(ret, area(arr[s[i]], arr[s[j]], arr[s[k]]));
	}
	return ret;
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
			cin >> arr[i].first >> arr[i].second;
		}

		sort(arr.begin(), arr.end());
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

		int sz = s.size();
		if (sz < 3) {
			cout << 0 << '\n';
			continue;
		}
		long long ans = 0;
		if (sz == 3) {
			ans = area(arr[s[0]], arr[s[1]], arr[s[2]]);
		}
		else {
			for (int i = 0; i < sz - 1; ++i) s.push_back(s[i]);
			for (int i = 0; i < sz; ++i) {
				for (int j = i + 2; j < sz; ++j) {
					if (i == 0 && j == sz - 1) continue;
					int low = i + 1, high = j - 1;
					long long now = ternary(i, j, low, high, s);
					low = j + 1, high = i + sz - 1;
					now += ternary(i, j, low, high, s);
					ans = max(ans, now);
				}
			}
		}
		cout << ans / 2;
		if (ans & 1) cout << ".5";
		cout << '\n';
	}
}
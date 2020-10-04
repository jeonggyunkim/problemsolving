#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct D {
	long long x, y;
	bool operator<(const D& r) {
		return x < r.x || (x == r.x && y < r.y);
	}
	long long ccw(D& p, D& q) {
		return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x);
	}
};

vector<D> arr;

long long dist(D& a, D& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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
			cin >> arr[i].x >> arr[i].y;
		}

		sort(arr.begin(), arr.end());
		sort(arr.begin() + 1, arr.end(), [](D& x, D& y) {
			return arr[0].ccw(x, y) > 0 || (arr[0].ccw(x, y) == 0 && (dist(arr[0], x) < dist(arr[0], y)));
		});

		vector<int> s;
		s.push_back(0); s.push_back(1);

		int next = 2;
		while (next < n) {
			while (s.size() >= 2) {
				int x, y;
				y = s.back();
				s.pop_back();
				x = s.back();

				if (arr[x].ccw(arr[y], arr[next]) > 0) {
					s.push_back(y);
					break;
				}
			}

			s.push_back(next++);
		}

		int maxx = -987654321, p1 = 0, p2;
		for (int i = 0; i < s.size(); ++i) {
			if (arr[s[i]].x > maxx) {
				maxx = arr[s[i]].x; p2 = i;
			}
		}

		long long d = -1;
		int ans1, ans2, sz = s.size();
		long long x1 = 0, x2 = 0, y1 = -1, y2 = 1;
		for (int i = 0; i < sz; ++i) {
			if (dist(arr[s[p1]], arr[s[p2]]) > d) {
				d = dist(arr[s[p1]], arr[s[p2]]);
				ans1 = s[p1], ans2 = s[p2];
			}

			long long xx1, yy1, xx2, yy2;
			double cos1, cos2;

			xx1 = arr[s[(p1 + 1) % sz]].x - arr[s[p1]].x;
			yy1 = arr[s[(p1 + 1) % sz]].y - arr[s[p1]].y;
			xx2 = arr[s[(p2 + 1) % sz]].x - arr[s[p2]].x;
			yy2 = arr[s[(p2 + 1) % sz]].y - arr[s[p2]].y;

			cos1 = (double)(x1 * xx1 + y1 * yy1) / sqrt(x1 * x1 + y1 * y1) / sqrt(xx1 * xx1 + yy1 * yy1);
			cos2 = (double)(x2 * xx2 + y2 * yy2) / sqrt(x2 * x2 + y2 * y2) / sqrt(xx2 * xx2 + yy2 * yy2);

			if (cos1 > cos2) {
				p1 = (p1 + 1) % sz;
				x1 = xx1; y1 = yy1;
				x2 = -x1; y2 = -y1;
			}
			else {
				p2 = (p2 + 1) % sz;
				x2 = xx2; y2 = yy2;
				x1 = -x2; y1 = -y2;
			}
		}
		cout << arr[ans1].x << ' ' << arr[ans1].y << ' ';
		cout << arr[ans2].x << ' ' << arr[ans2].y << '\n';
	}
}
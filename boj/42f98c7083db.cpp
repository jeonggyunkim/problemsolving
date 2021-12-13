#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> ii;
typedef pair<ii, int> i3;

int ccw(ii a, ii b, ii c) {
	ii ab = {b.first - a.first, b.second - a.second};
	ii ac = {c.first - a.first, c.second - a.second};
	long long d = (ab.first * ac.second) - (ab.second * ac.first);
	if (d > 0) return 1;
	else if (d < 0) return -1;
	else return 0;
}

ii black[100], white[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) cin >> black[i].first >> black[i].second;
		for (int i = 0; i < m; ++i) cin >> white[i].first >> white[i].second;

		bool pos = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				vector<i3> line;
				int b = 0, w = 0;
				int flip = 0;
				for (int x = 0; x < n; ++x) {
					int t = ccw(black[i], white[j], black[x]);
					if (t == 0) line.push_back({black[x], 0});
					else {
						if (b == 0) b = t;
						if ((b > 0) != (t > 0)) goto end;
					}
				}
				for (int y = 0; y < m; ++y) {
					int t = ccw(black[i], white[j], white[y]);
					if (t == 0) line.push_back({white[y], 1});
					else {
						if (w == 0) {
							w = t;
							if ((b > 0) == (w > 0)) goto end;
						}
						if ((w > 0) != (t > 0)) goto end;
					}
				}

				sort(line.begin(), line.end());
				for (int i = 1; i < line.size(); ++i) {
					if (line[i - 1].second != line[i].second) flip++;
				}
				if (flip == 1) {
					pos = 1;
					break;
				}
				end:;
			}
			if (pos) break;
		}

		if (pos) cout << "YES\n";
		else cout << "NO\n";
	}
}
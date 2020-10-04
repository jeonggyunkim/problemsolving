#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int l, s, e;
		cin >> l >> s >> e;

		vector<iii> seg;
		int sum = 0;
		int a, b;
		int len, h;

		cin >> a;
		for (int i = 0; i < a; ++i) {
			cin >> len >> h;
			seg.push_back(iii(sum, h, 0));
			sum += len;
		}

		sum = 0;
		cin >> b;
		for (int i = 0; i < b; ++i) {
			cin >> len >> h;
			seg.push_back(iii(sum, h, 1));
			sum += len;
		}
		seg.push_back(iii(l, INF, INF));

		sort(seg.begin(), seg.end());

		vector<iii> minmax;
		int high = -1, low = INF;
		for (int i = 0; i < seg.size() - 1; ++i) {
			if (get<2>(seg[i]) == 0) high = get<1>(seg[i]);
			else low = get<1>(seg[i]);

			if (i != seg.size() - 1 && get<0>(seg[i]) == get<0>(seg[i + 1]));
			else {
				minmax.push_back(iii(low, high, get<0>(seg[i + 1]) - get<0>(seg[i])));
			}
		}

		vector<int> route(minmax.size());
		int now = s;
		for (int i = 0; i < minmax.size(); ++i) {
			int low = get<0>(minmax[i]);
			int high = get<1>(minmax[i]);
			if (high < now) now = high;
			else if (low > now) now = low;
			route[i] = now;
		}
		route.push_back(e);

		high = e, low = e;
		long long ans = 0;
		for (int i = route.size() - 2; i >= 0; --i) {
			if (route[i] != route[i + 1]) {
				if (route[i] < route[i + 1]) low = min(low, route[i]);
				else high = max(high, route[i]);
			}
			high = min(get<1>(minmax[i]), high);
			low = min(get<1>(minmax[i]), low);
			high = max(get<0>(minmax[i]), high);
			low = max(get<0>(minmax[i]), low);

			ans += (long long)(high - low) * get<2>(minmax[i]);
		}


		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
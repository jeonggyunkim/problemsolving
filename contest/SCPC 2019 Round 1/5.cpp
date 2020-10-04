
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#define INF (1LL << 60)
using namespace std;

typedef tuple<long long, long long, int> lli;

multiset<long long> low, mid, high;

long long getnow(long long x) {
	long long ret = INF;
	if (!low.empty()) ret = min(ret, -(*low.rbegin() + x));
	if (!mid.empty()) ret = min(ret, -(*mid.rbegin()));
	if (!high.empty()) ret = min(ret, -(*high.rbegin() - x));
	return ret;
}

bool ishighmin(long long x) {
	long long ret = INF, now;
	int t = -1;
	if (!low.empty()) {
		now = -(*low.rbegin() + x);
		if (now < ret) {
			ret = now;
			t = 1;
		}
	}
	if (!mid.empty()) {
		now = -(*mid.rbegin());
		if (now < ret) {
			ret = now;
			t = 2;
		}
	}
	if (!high.empty()) {
		now = -(*high.rbegin() - x);
		if (now < ret) {
			ret = now;
			t = 3;
		}
	}
	return t == 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		long long l, r;
		cin >> l >> r;

		int n;
		cin >> n;

		low.clear();
		mid.clear();
		high.clear();

		vector<lli> arr;
		while (n--) {
			long long x, y;
			cin >> x >> y;

			if (y < 0) y = -y;

			long long xm, xp;
			xm = x - y;
			xp = x + y;
			if (xm > l) {
				arr.push_back(lli(xm, y, 1));
				arr.push_back(lli(xp, y, 2));
				low.insert(-xm - y);
			}
			else if (xp > l) {
				arr.push_back(lli(xp, y, 2));
				mid.insert(-y);
			}
			else {
				high.insert(xp - y);
			}
		}

		sort(arr.begin(), arr.end());

		long long ans = -1;
		ans = max(ans, 2 * getnow(l));

		int i = 0;
		while (i < arr.size()) {
			long long x = get<0>(arr[i]);
			long long y = get<1>(arr[i]);
			int op = get<2>(arr[i]);

			if (x > r) break;
			if (op == 1) {
				auto it = low.find(-x - y);
				low.erase(it);
				mid.insert(-y);
			}
			else {
				auto it = mid.find(-y);
				mid.erase(it);
				high.insert(x -y);
			}
			i++;
			while (i < arr.size() && get<0>(arr[i]) == x) {
				x = get<0>(arr[i]);
				y = get<1>(arr[i]);
				op = get<2>(arr[i]);
				if (op == 1) {
					auto it = low.find(-x - y);
					low.erase(it);
					mid.insert(-y);
				}
				else {
					auto it = mid.find(-y);
					mid.erase(it);
					high.insert(x - y);
				}
				i++;
			}
			long long ny = getnow(x);
			ans = max(ans, 2 * ny);
			if (ishighmin(x)) {
				long long cy = -(*high.rbegin() - x);
				if (i < arr.size() - 1) {
					long long next = get<0>(arr[i + 1]);
					long long realnow = INF;
					if (!low.empty()) {
						long long that = -(*low.rbegin() + x) - cy;
						if (2 * x + that < 2 * next) {
							realnow = min(realnow, 2 * ny + that);
						}
					}
					if (!mid.empty()) {
						long long that = -(*mid.rbegin()) - cy;
						if (x + that < next) {
							realnow = min(realnow, 2 * (ny + that));
						}
					}
					if (realnow != INF)	ans = max(ans, realnow);
				}
			}
		}

		if (i != arr.size()) ans = max(ans, 2 * getnow(r));

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}

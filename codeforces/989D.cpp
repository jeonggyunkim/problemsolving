#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int l, w;

bool maxpos(double a, double d) {
	double t = a + l + d * (1 + w) / 2;
	if (t > EPS) return true;
	t = a + (d / 2 + l) * (1 + w);
	if (t > EPS) return true;
	return false;
}

bool minneg(double a, double d) {
	double t = a + l + d * (1 - w) / 2;
	if (t < -EPS) return true;
	t = a + (d / 2 + l) * (1 - w);
	if (t < -EPS) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> l >> w;

	int a, b;
	vector<int> front, back;
	while (n--) {
		cin >> a >> b;
		if (b == 1) front.push_back(a);
		else back.push_back(a);
	}
	sort(back.begin(), back.end());

	long long ans = 0;
	for (int i = 0; i < front.size(); ++i) {
		if (back.size() == 0) {
			cout << 0;
			return 0;
		}
		int low = 0, high = back.size() - 1, mid;

		int d = back[low] - front[i] - l;
		if (maxpos(front[i], d) && minneg(front[i], d)) {
			ans += back.size();
			continue;
		}
		d = back[high] - front[i] - l;
		if (!maxpos(front[i], d) || !minneg(front[i], d)) continue;

		while (true) {
			if (high - low <= 1) break;
			mid = (high + low) / 2;
			int d = back[mid] - front[i] - l;
			if (d < 0) {
				low = mid;
				continue;
			}
			if (maxpos(front[i], d) && minneg(front[i], d)) high = mid;
			else low = mid;
		}
		ans += back.size() - high;
	}
	cout << ans;
}
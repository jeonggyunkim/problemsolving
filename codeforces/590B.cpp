#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<bool, double> equation(ll a, ll b, ll c, double t) {
	ll d = b * b - 4 * a * c;
	if (d < 0) return make_pair(0, 0);
	else if (d == 0) {
		double t1 = (double)(-b) / (2 * a);
		if (t1 >= t) return make_pair(1, t1);
		return make_pair(0, 0);
	}
	else {
		double t1 = (double)(-b - sqrt(d)) / (2 * a);
		double t2 = (double)(-b + sqrt(d)) / (2 * a);
		if (t1 >= t) return make_pair(1, t1);
		if (t2 >= t) return make_pair(1, t2);
		return make_pair(0, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ll x = x2 - x1;
	ll y = y2 - y1;

	ll v, t;
	cin >> v >> t;

	ll vx, vy;
	cin >> vx >> vy;
	vx = -vx; vy = -vy;

	ll a = vx * vx + vy * vy - v * v;
	ll b = 2 * x * vx + 2 * y * vy;
	ll c = x * x + y * y;

	cout.precision(15);

	pair<bool, double> ans = equation(a, b, c, 0);
	if (ans.first && ans.second <= t) {
		cout << ans.second;
		return 0;
	}

	x = x + vx * t; y = y + vy * t;
	cin >> vx >> vy;
	vx = -vx; vy = -vy;

	a = vx * vx + vy * vy - v * v;
	b = (x - vx * t) * vx * 2;
	b += (y - vy * t) * vy * 2;
	c = x * x + y * y + vx * vx * t * t + vy * vy * t * t - 2 * x * vx * t - 2 * y * vy * t;
	ans = equation(a, b, c, t);
	cout << ans.second;
}
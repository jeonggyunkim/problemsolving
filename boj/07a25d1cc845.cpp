#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll low(ll a, ll b) {
	if (a < 0) return a / b;
	else {
		ll ret = a / b;
		if (a % b != 0) ret++;
		return ret;
	}
}

ll high(ll a, ll b) {
	if (a > 0) return a / b;
	else {
		ll ret = a / b;
		if (a % b != 0) ret--;
		return ret;
	}
}

ii find_sol(int a, int b) {
	if (b == 1) return ii(0, 1);
	vector<int> q;
	while (b != 1) {
		q.push_back(a / b);
		int t = b;
		b = a % b;
		a = t;
	}

	ll a1 = 1, a2 = -q.back();
	q.pop_back();
	while (!q.empty()) {
		ll t = a2;
		a2 = a2 * -q.back() + a1;
		a1 = t;
		q.pop_back();
	}
	return ii(a1, a2);
}

int main() {
	int a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	int aa = abs(a), bb = abs(b), cc = abs(c);

	if (a == 0 || b == 0) {
		if (a == 0) {
			if (b == 0) {
				if (c == 0) cout << (ll)(x2 - x1 + 1) * (y2 - y1 + 1);
				else cout << 0;
			}
			else {
				if (cc % bb == 0 && (c / b >= y1 && c / b <= y2)) cout << (x2 - x1 + 1);
				else cout << 0;
			}
		}
		else {
			if (cc % aa == 0 && (c / a >= x1 && c / a <= x2)) cout << (y2 - y1 + 1);
			else cout << 0;
		}
	}
	else {
		int d = __gcd(aa, bb);
		if (cc % d != 0) cout << 0;
		else {
			ll x0, y0;
			if (aa > bb) {
				ii t = find_sol(aa / d, bb / d);
				if (a < 0) x0 = -t.first;
				else x0 = t.first;
				if (b < 0) y0 = -t.second;
				else y0 = t.second;
			}
			else {
				ii t = find_sol(bb / d, aa / d);
				if (a < 0) x0 = -t.second;
				else x0 = t.second;
				if (b < 0) y0 = -t.first;
				else y0 = t.first;
			}
			x0 *= -c / d;
			y0 *= -c / d;
			int dx = -b / d, dy = a / d;
			ll x_low, x_high, y_low, y_high;
			if (dx > 0) {
				x_low = low(x1 - x0, dx);
				x_high = high(x2 - x0, dx);
			}
			else {
				x_low = low(x0 - x2, -dx);
				x_high= high(x0 - x1, -dx);
			}

			if (dy > 0) {
				y_low = low(y1 - y0, dy);
				y_high = high(y2 - y0, dy);
			}
			else {
				y_low = low(y0 - y2, -dy);
				y_high= high(y0 - y1, -dy);
			}

			if (x_low > x_high || y_low > y_high || y_low > x_high || x_low > y_high) cout << 0;
			else {
				cout << min(x_high, y_high) - max(x_low, y_low) + 1;
			}
		}
	}
}
#include <iostream>
using namespace std;

typedef pair<long long, long long> ii;
typedef pair<double, double> dd;

long long ccw(ii a, ii b, ii c) {
	ii ab = { b.first - a.first, b.second - a.second };
	ii ac = { c.first - a.first, c.second - a.second };
	return (ab.first * ac.second) - (ab.second * ac.first);
}

double ccw(dd a, dd b, dd c) {
	dd ab = { b.first - a.first, b.second - a.second };
	dd ac = { c.first - a.first, c.second - a.second };
	return (ab.first * ac.second) - (ab.second * ac.first);
}

bool mid(ii a, ii b, ii c) {
	if (a > b) swap(a, b);
	if (c < a || c > b) return 0;
	else return 1;
}

int main() {
	ii a, b, c, d;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	cin >> d.first >> d.second;

	long long d1 = ccw(a, b, c), d2 = ccw(a, b, d);
	if (d1 == 0 || d2 == 0) {
		if (d1 == 0 && d2 == 0) {
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			if (d < a || c > b) cout << 0;
			else {
				cout << "1\n";
				if (d == a) cout << a.first << ' ' << a.second;
				else if (b == c) cout << b.first << ' ' << b.second;
			}
		}
		else if (d1 == 0 && mid(a, b, c)) {
			cout << "1\n";
			cout << c.first << ' ' << c.second;
		}
		else if (d2 == 0 && mid(a, b, d)) {
			cout << "1\n";
			cout << d.first << ' ' << d.second;
		}
		else cout << 0;
	}
	else if ((d1 > 0) == (d2 > 0)) cout << 0;
	else {
		d1 = ccw(c, d, a);
		d2 = ccw(c, d, b);
		if (d1 == 0 || d2 == 0) {
			if (d1 == 0 && mid(c, d, a)) {
				cout << "1\n";
				cout << a.first << ' ' << a.second;
			}
			else if (d2 == 0 && mid(c, d, b)) {
				cout << "1\n";
				cout << b.first << ' ' << b.second;
			}
			else cout << 0;
		}
		else if ((d1 > 0) == (d2 > 0)) cout << 0;
		else {
			cout << "1\n";
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			dd a1 = a, p = a, q = b, r = c, s = d;
			for (int i = 0; i < 100; ++i) {
				dd m = { (p.first + q.first) / 2, (p.second + q.second) / 2 };
				if ((ccw(r, s, m) > 0) == (ccw(r, s, a1) > 0)) p = m;
				else q = m;
			}
			cout.precision(20);
			cout << p.first << ' ' << p.second;
		}
	}
}
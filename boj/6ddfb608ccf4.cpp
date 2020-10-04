#include <iostream>
using namespace std;

typedef long long ll;

struct V {
	V(ll x_ = 0, ll y_ = 0, ll z_ = 0) {
		x = x_; y = y_; z = z_;
	}
	ll x, y, z;
};

V cross(V& a, V& b) {
	ll x = a.y * b.z - a.z * b.y;
	ll y = a.z * b.x - a.x * b.z;
	ll z = a.x * b.y - a.y * b.x;
	return V(x, y, z);
}

ll dot(V& a, V& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

int main() {
	int n;
	cin >> n;

	if (n <= 3) {
		cout << "TAK";
		return 0;
	}

	int xi, yi, zi, x, y, z;
	cin >> xi >> yi >> zi;

	V a1, a2, a3;
	cin >> x >> y >> z;
	a1.x = x - xi;
	a1.y = y - yi;
	a1.z = z - zi;

	int cnt = 2;
	while (cnt < n) {
		cin >> x >> y >> z;
		cnt++;
		a2.x = x - xi;
		a2.y = y - yi;
		a2.z = z - zi;

		a3 = cross(a1, a2);
		if (a3.x || a3.y || a3.z) break;
	}
	if (cnt == n) {
		cout << "TAK";
		return 0;
	}

	for (int i = cnt; i < n; ++i) {
		cin >> x >> y >> z;
		a2.x = x - xi;
		a2.y = y - yi;
		a2.z = z - zi;
		if (dot(a2, a3) != 0) {
			cout << "NIE";
			return 0;
		}
	}
	cout << "TAK";
}

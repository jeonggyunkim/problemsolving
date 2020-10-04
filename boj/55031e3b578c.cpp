#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int p, d;
	cin >> p >> d;

	int a[1010] = {}, b[1010] = {};
	int x, y, z;
	for (int i = 0; i < p; ++i) {
		cin >> x >> y >> z;
		a[x] += y;
		b[x] += z;
	}

	int total = 0, adie = 0, bdie = 0;
	for (int i = 1; i <= d; ++i) {
		int p, q;
		if (a[i] < b[i]) {
			cout << "B ";
			p = a[i];
			q = b[i] - ((a[i] + b[i]) / 2 + 1);
		}
		else {
			cout << "A ";
			p = a[i] - ((a[i] + b[i]) / 2 + 1);
			q = b[i];
		}
		adie += p;
		bdie += q;
		total += a[i] + b[i];
		cout << p << ' ' << q << '\n';
	}
	cout.precision(10);
	cout << (double)abs(adie - bdie) / total;
}
#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double x, y;
	cin >> x >> y;

	double t1 = y * log(x);
	double t2 = x * log(y);

	if (abs(t1 - t2) < EPS) cout << '=';
	else {
		if (t1 > t2) cout << '>';
		else cout << '<';
	}
}
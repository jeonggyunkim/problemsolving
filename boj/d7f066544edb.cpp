#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) {
		if (b > a) swap(a, b);
		if (c > b) swap(b, c);
		if (b > a) swap(a, b);

		if (a >= b + c) cout << "Invalid\n";
		else if (a == b && b == c) cout << "Equilateral\n";
		else if (a == b || b == c) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
}
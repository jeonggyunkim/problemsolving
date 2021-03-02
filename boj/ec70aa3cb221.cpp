#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int a, b, c;
		cin >> a >> b >> c;

		cout << "Case #" << test << ": ";
		if (a == b && b == c) cout << "equilateral";
		else {
			if (a >= b + c || b >= a + c || c >= a + b) cout << "invalid!";
			else {
				if (a == b || b == c || c == a) cout << "isosceles";
				else cout << "scalene";
			}
		}
		cout << '\n';
	}
}
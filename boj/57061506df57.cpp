#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) {
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);

		if (a * a + b * b == c * c) cout << "right\n";
		else cout << "wrong\n";
	}
}
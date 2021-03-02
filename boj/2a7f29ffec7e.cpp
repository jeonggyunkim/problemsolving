#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	while (cin >> a >> b >> c >> d, a || b || c || d) {
		cout << c - b << ' ' << d - a << '\n';
	}
}
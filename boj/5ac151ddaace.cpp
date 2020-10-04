#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	while (cin >> a >> b, a || b) {
		int d = __gcd(a, b);
		if (d == a) cout << "factor";
		else if (d == b) cout << "multiple";
		else cout << "neither";
		cout << '\n';
	}
}
#include <iostream>
using namespace std;

int main() {
	int x, l, r;
	cin >> x >> l >> r;

	if (x < l) cout << l;
	else if (x > r) cout << r;
	else cout << x;
}
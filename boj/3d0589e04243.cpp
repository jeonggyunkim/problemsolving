#include <iostream>
using namespace std;

int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	cout << l - max((a + c - 1) / c, (b + d - 1) / d);
}
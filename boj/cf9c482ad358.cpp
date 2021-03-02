#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;

	c = b * 1000000 + a;

	bool pos = 1;
	for (int i = 2; i * i <= a; ++i) {
		if (a % i == 0) pos = 0;
	}
	for (int i = 2; i * i <= c; ++i) {
		if (c % i == 0) pos = 0;
	}
	if (pos) cout << "Yes\n";
	else cout << "No\n";
}
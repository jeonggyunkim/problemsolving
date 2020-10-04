#include <iostream>
using namespace std;

int cnv(int n, bool big) {
	int ret = 0;
	int i = 1;
	while (n) {
		int t = n % 10;
		if (big && t == 5) ret += i * 6;
		else if (!big && t == 6) ret += i * 5;
		else ret += i * t;
		i *= 10;
		n /= 10;
	}
	return ret;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << cnv(a, 0) + cnv(b, 0) << ' ';
	cout << cnv(a, 1) + cnv(b, 1);
}
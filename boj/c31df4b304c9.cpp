#include <iostream>
using namespace std;

int rev(int n) {
	int ret = 0;
	while (n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b));
}
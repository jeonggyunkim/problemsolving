#include <iostream>
using namespace std;

int d(int n) {
	int m = n;
	while (n) {
		m += n % 10;
		n /= 10;
	}
	return m;
}

int main() {
	bool a[10010] = {};
	for (int i = 1; i <= 10000; i++) {
		if (!a[i]) cout << i << '\n';
		int t = d(i);
		if (t <= 10000) a[t] = 1;
	}
}
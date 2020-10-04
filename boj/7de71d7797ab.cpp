#include <iostream>
using namespace std;

int len;
char num[5];

int main() {
	int n, m;
	cin >> n >> m;

	int t = n;
	while (t) {
		num[len++] = t % 10 + '0';
		t /= 10;
	}

	for (int i = 0; i < min(n, m / len); ++i) cout << n;
	if (n * len > m) {
		for (int i = 0; i < m % len; ++i) cout << num[len - 1 - i];
	}
}
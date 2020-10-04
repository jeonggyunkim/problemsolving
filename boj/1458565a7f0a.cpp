#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;

	char bi[60];
	char ans[100];
	int len = 0, k = 0;
	while (n) {
		if (n & 1) bi[len++] = 1;
		else bi[len++] = 0;
		n /= 2;
	}

	len--;
	while (len >= 0) {
		if (bi[len] == 1) ans[k++] = '+';
		if (len) ans[k++] = '*';
		len--;
	}
	ans[k++] = '/';
	cout << k << '\n';
	for (int i = 0; i < k; ++i) cout << '[' << ans[i] << "] ";
}
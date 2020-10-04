#include <bits/stdc++.h>
using namespace std;

int main() {
	char input[53];
	int n = -1;
	cin >> input;
	while (input[++n]);

	for (int i = 0; i < n / 2; ++i) {
		if (input[i] != input[n - 1 - i]) {
			cout << n;
			return 0;
		}
	}
	for (int i = 1; i <= n / 2; ++i) if (input[i - 1] != input[i]) {
		cout << n - 1;
		return 0;
	}
	cout << 0;
}
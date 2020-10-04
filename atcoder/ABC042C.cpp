#include <bits/stdc++.h>
using namespace std;

bool cant[10];

bool pay(int n) {
	while (n) {
		if (cant[n % 10]) return 0;
		n /= 10;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	while (k--) {
		cin >> t;
		cant[t] = 1;
	}

	while (1) {
		if (pay(n)) {
			cout << n;
			return 0;
		}
		n++;
	}
}
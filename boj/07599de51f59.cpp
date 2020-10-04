#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> n;

	int cnt = 0;
	int x = 0;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == 1) cnt++;
		else x ^= t;
	}

	if (n == cnt) {
		if (n & 1) cout << "cubelover";
		else cout << "koosaga";
	}
	else {
		if (x == 0) cout << "cubelover";
		else cout << "koosaga";
	}
}
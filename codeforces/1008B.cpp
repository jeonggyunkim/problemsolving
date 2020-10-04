#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int prev = 1 << 30, a, b;
	while (n--) {
		cin >> a >> b;
		if (b > a) swap(a, b);

		if (prev >= a) prev = a;
		else if (prev >= b) prev = b;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	int cnt = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (b[i] == b[n - 1 - i]) {
			if (a[i] != a[n - 1 - i]) cnt++;
		}
		else {
			if (a[i] == b[i] || a[i] == b[n - 1 - i]) {
				if (a[i] == b[i]) {
					if (a[n - 1 - i] != b[n - 1 - i]) cnt++;
				}
				else {
					if (a[n - 1 - i] != b[i]) cnt++;
				}
			}
			else {
				if (a[n - 1 - i] == b[i] || a[n - 1 - i] == b[n - 1 - i]) cnt++;
				else cnt += 2;
			}
		}
	}
	if (n & 1) {
		if (a[n / 2] != b[n / 2]) cnt++;
	}
	cout << cnt;
}
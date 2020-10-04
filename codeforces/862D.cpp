#include <bits/stdc++.h>
using namespace std;

int n;

int print(int s, int f) {
	int ret;
	cout << "? ";
	for (int i = 0; i < s; ++i) cout << 0;
	for (int i = s; i < f; ++i) cout << 1;
	for (int i = f; i < n; ++i) cout << 0;
	cout << endl;
	cin >> ret;
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t1, t2, num;
	cin >> n;

	t1 = print(0, 0);
	t2 = print(0, 1);

	if (t1 < t2) num = 1;
	else num = 0;

	int s = 0, f = n;
	while (f - s != 1) {
		int mid = (s + f) / 2;
		t2 = print(mid, f);

		int len = f - mid;
		int one = (len - (t2 - t1)) / 2;
		int zero = len - one;
		if (num == 0) {
			if (zero) s = mid;
			else f = mid;
		}
		else {
			if (one) s = mid;
			else f = mid;
		}
	}
	cout << "! ";
	if (num == 1) cout << 1 << ' ' << s + 1;
	else cout << s + 1 << ' ' << 1;
	cout << endl;
}
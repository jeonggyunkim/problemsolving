#include <iostream>
#include <algorithm>
using namespace std;

int arr[11], x[11], y[11];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		arr[i - 1] = i;
	}

	int ans = 0;
	do {
		int d, nowd = -1, nowx = 0, nowy = 0, pos = 1;
		for (int i = 0; i <= n; ++i) {
			if (nowx == x[arr[i]]) {
				if (y[arr[i]] > nowy) d = 0;
				else d = 1;
			}
			else if (nowy == y[arr[i]]) {
				if (x[arr[i]] > nowx) d = 2;
				else d = 3;
			}
			else {
				pos = 0;
				break;
			}
			if (d == nowd) {
				pos = 0;
				break;
			}
			nowx = x[arr[i]];
			nowy = y[arr[i]];
			nowd = d;
		}
		if (pos) {
			ans++;
		}
	} while (next_permutation(arr, arr + n));
	cout << ans;
}
#include <iostream>
#include <algorithm>
using namespace std;

char t[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> t[i];

	int r;
	cin >> r;

	if (r == 1) {
		for (int i = 0; i < n; ++i) cout << t[i] << '\n';
	}
	else if (r == 2) {
		for (int i = 0; i < n; ++i) {
			reverse(t[i], t[i] + n);
			cout << t[i] << '\n';
		}
	}
	else {
		for (int i = n - 1; i >= 0; --i) cout << t[i] << '\n';
	}
}
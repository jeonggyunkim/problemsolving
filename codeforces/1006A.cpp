#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		if (t & 1) cout << t;
		else cout << t - 1;
		cout << ' ';
	}
}
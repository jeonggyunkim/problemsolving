#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t;
		cout << sum / m << ' ';
		sum %= m;
	}
}
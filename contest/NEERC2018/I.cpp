#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int mini = 1987654321, maxi = -1;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		mini = min(mini, t);
		maxi = max(maxi, t);
	}

	cout << maxi - mini + 1 - n;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	int ans = a.size() + b.size();
	int i = a.size() - 1, j = b.size() - 1;

	while (i >= 0 && j >= 0) {
		if (a[i] == b[j]) {
			i--; j--;
			ans -= 2;
		}
		else break;
	}
	cout << ans;
}
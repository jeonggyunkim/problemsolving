#include <bits/stdc++.h>
using namespace std;
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;

		a += c;
		if (a <= b) cout << "0\n";
		else {
			cout << min(c + 1, (a - b + 1) / 2) << '\n';
		}
	}
}
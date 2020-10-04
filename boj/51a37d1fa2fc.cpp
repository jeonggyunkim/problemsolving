#include <iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		int i = 10;
		while (i < n) i *= 10;

		int t = (n * n) % i;

		if (t == n) cout << "YES\n";
		else cout << "NO\n";
	}
}
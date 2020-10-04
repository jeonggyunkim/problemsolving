#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		int a = 0, b = 1, c;
		while (n--) {
			c = b;
			b = (a + b) % MOD;
			a = c;
		}

		cout << b << '\n';
	}
}

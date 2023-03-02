#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		long long n;
		cin >> n;

		if (n % 3 == 2 || n % 9 == 0) cout << "TAK\n";
		else cout << "NIE\n";
	}
}
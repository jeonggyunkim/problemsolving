#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		long long sum = 0, t;
		while (n--) {
			cin >> t;
			sum += t;
		}
		cout << sum << '\n';
	}
}
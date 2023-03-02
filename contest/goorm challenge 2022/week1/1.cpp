#include <iostream>
using namespace std;

int main() {
	int n, t;
	long long ans = 1;
	cin >> n;

	while (n--) {
		cin >> t;
		ans *= t;
	}
	cout << ans;
}
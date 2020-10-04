#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	long long ans = 0, sum = 0;
	while (n--) {
		cin >> t;
		ans += t * sum;
		sum += t;
	}
	cout << ans;
}
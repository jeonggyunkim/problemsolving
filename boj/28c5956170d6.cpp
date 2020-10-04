#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long ans = 0, sum = 0, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t;
		ans = max(ans, 2 * t);
	}
	cout << max(ans, sum);
}
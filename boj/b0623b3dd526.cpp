#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long ans = n;
	for (int i = 1; i < n; ) {
		int t = (n - 1) / i;
		int range = (n - 1) / t - (n - 1) / (t + 1);
		ans += (long long)t * range;
		i = (n - 1) / t + 1;
	}
	cout << ans;
}
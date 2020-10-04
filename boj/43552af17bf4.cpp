#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans += n;
		n *= 10;
	}
	cout << ans;
}
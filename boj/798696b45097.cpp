#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int low = k - 1, ans = 0;
	while (low) {
		low--;
		low /= 2;
		ans++;
	}
	cout << min(ans + m, __builtin_ctz(n));
}
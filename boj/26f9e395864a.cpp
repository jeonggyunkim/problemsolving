#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long maxi = -1, mini = 1e9, t, ans = 1;
	while (n--) {
		cin >> t;
		maxi = max(maxi, t);
		mini = min(mini, t);
		ans = ans * t / __gcd(ans, t);
	}
	if (ans == maxi) ans *= mini;
	cout << ans;
}
#include <iostream>
using namespace std;

int main() {
	long long n, i, a;
	cin >> n >> a;
	i = a;
	long long ans = 0;
	while (i <= n) {
		ans += n / i;
		i *= a;
	}
	cout << ans;
}
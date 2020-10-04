#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, M = 1234567891;
	string s;

	cin >> n >> s;

	long long ans = 0, p = 1;
	for (int i = 0; i < n; ++i) {
		ans += p * (s[i] - 'a' + 1);
		ans %= M;

		p *= 31;
		p %= M;
	}

	cout << ans;
}
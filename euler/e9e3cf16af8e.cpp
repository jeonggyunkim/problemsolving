#include <iostream>
#define MOD 10000000000
using namespace std;

long long simplepow(int n) {
	long long ret = 1;
	for (int i = 0; i < n; ++i) {
		(ret *= n) %= MOD;
	}
	return ret;
}

int main() {
	long long ans = 0;
	for (int i = 1; i <= 1000; ++i) {
		(ans += simplepow(i)) %= MOD;
	}
	cout << ans << endl;
}
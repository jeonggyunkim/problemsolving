#include <iostream>
using namespace std;

bool notPrime[2000010];

int main() {
	for (int i = 2; i * i <= 2000000; ++i) {
		if (!notPrime[i]) {
			for (int j = i * i; j <= 2000000; j += i) {
				notPrime[j] = 1;
			}
		}
	}

	long long ans = 0;
	for (int i = 2; i <= 2000000; ++i) {
		if (!notPrime[i]) ans += i;
	}
	cout << ans << endl;
}
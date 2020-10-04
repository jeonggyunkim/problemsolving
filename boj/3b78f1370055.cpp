#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	int n;
	cin >> n;
	n--;
	
	long long ans = 1;
	while (n != 1) {
		(ans *= n) %= MOD;
		n -= 2;
	}
	cout << ans;
}
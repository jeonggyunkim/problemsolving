#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	
	int cnt = 0;
	for (int i = 2; i * i <= k; ++i) {
		while (k % i == 0) {
			cnt++;
			k /= i;
		}
	}
	if (k != 1) cnt++;

	int ans = 0;
	for (int p = 1; p < cnt; p *= 2) {
		ans++;
	}
	cout << ans;
}

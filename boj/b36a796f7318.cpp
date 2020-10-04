#include <iostream>
#define MOD 1000000009
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 100000; ++i) {
		arr[i] = (arr[i - 3] + arr[i - 2]) % MOD;
		arr[i] = (arr[i] + arr[i - 1]) % MOD;
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		if (n == 1) cout << "1\n";
		else cout << (arr[n / 2] + arr[n / 2 - 1]) % MOD << '\n';
	}
}
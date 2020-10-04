#include <iostream>
#define MOD 1000000009
using namespace std;

int arr[100001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[1][0] = 1;
	arr[2][1] = 1;
	arr[3][0] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	for (int i = 4; i <= 100000; ++i) {
		arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % MOD;
		arr[i][1] = (arr[i - 2][0] + arr[i - 2][2]) % MOD;
		arr[i][2] = (arr[i - 3][0] + arr[i - 3][1]) % MOD;
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		cout << ((arr[n][0] + arr[n][1]) % MOD + arr[n][2]) % MOD << '\n';
	}
}
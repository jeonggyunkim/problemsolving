#include <iostream>
#define MOD 1000000009
using namespace std;

int arr[100001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[1][1] = 1;
	arr[2][0] = 1;
	arr[2][1] = 1;
	arr[3][0] = 2;
	arr[3][1] = 2;
	for (int i = 4; i <= 100000; ++i) {
		for (int j = 0; j < 2; ++j) {
			arr[i][j] = (arr[i - 3][1 - j] + arr[i - 2][1 - j]) % MOD;
			arr[i][j] = (arr[i][j] + arr[i - 1][1 - j]) % MOD;
		}
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		cout << arr[n][1] << ' ' << arr[n][0] << '\n';
	}
}
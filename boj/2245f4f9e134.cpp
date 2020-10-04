#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int n, cnt = 0;
		cin >> n;

		while (n != 6174) {
			int arr[4];
			arr[0] = n / 1000;
			arr[1] = (n % 1000) / 100;
			arr[2] = (n % 100) / 10;
			arr[3] = n % 10;
			sort(arr, arr + 4);

			int mini = 10000, maxi = -1;
			do {
				int now = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
				mini = min(mini, now);
				maxi = max(maxi, now);
			} while (next_permutation(arr, arr + 4));
			n = maxi - mini;
			cnt++;
		}
		cout << cnt << '\n';
	}
}

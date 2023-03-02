#include <iostream>
#include <algorithm>
#define INF 1987654321
using namespace std;

int main() {
	int n, d, ans = INF;
	cin >> n >> d;

	int arr[9];
	for (int i = 0; i < d; ++i) arr[i] = i;
	swap(arr[0], arr[1]);

	do {
		int now = 0;
		for (int i = 0; i < d; ++i) {
			now *= d;
			now += arr[i];
		}
		if (now > n) ans = min(ans, now);
	} while (next_permutation(arr, arr + d));

	if (ans == INF) cout << -1;
	else cout << ans;
}
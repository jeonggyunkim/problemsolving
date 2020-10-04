#include <iostream>
#include <algorithm>
using namespace std;

int arr[20][20];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	int per[20] = {};
	for (int i = n / 2; i < n; ++i) per[i] = 1;
	
	int ans = 987654321;
	do {
		int cnt[2] = {};
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (per[i] == per[j]) {
					cnt[per[i]] += arr[i][j];
					cnt[per[i]] += arr[j][i];
				}
			}
		}
		ans = min(ans, abs(cnt[1] - cnt[0]));
	} while (next_permutation(per, per + n));

	cout << ans;
}
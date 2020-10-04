#include <iostream>
#include <memory.h>
using namespace std;

int arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		int cnt[10001] = {};
		memset(cnt, -1, sizeof(cnt));

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			cnt[arr[i]] = i;
		}

		long long ans = 0;
		for (int i = 10000; i >= 1; --i) {
			if (cnt[i] == -1) continue;
			for (int j = cnt[i]; j >= 0 && arr[j] != -1; --j) {
				ans += i - arr[j];
				arr[j] = -1;
			}
		}
		cout << '#' << test << ' ' << ans << '\n';
	}
}
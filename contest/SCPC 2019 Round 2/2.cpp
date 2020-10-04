#include <iostream>
using namespace std;

int arr1[5010], arr2[5010];
int same1[5010], same2[5010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i) cin >> arr1[i];
		for (int i = 1; i <= n; ++i) cin >> arr2[i];

		same1[0] = 0;
		for (int i = 1; i <= n; ++i) {
			same1[i] = same1[i - 1];
			if (arr1[i] == arr2[i]) same1[i]++;
		}

		same2[n + 1] = 0;
		for (int i = n; i >= 1; --i) {
			same2[i] = same2[i + 1];
			if (arr1[i] == arr2[i]) same2[i]++;
		}

		int ans = -1;
		for (int start = 1; start <= n; ++start) {
			int i = start, j = start;
			int cnt = arr1[i] == arr2[i] ? -1 : 0;
			while (i >= 1 && j <= n) {
				if (arr1[i] == arr2[j]) cnt++;
				if (arr1[j] == arr2[i]) cnt++;
				ans = max(ans, cnt + same1[i - 1] + same2[j + 1]);
				i--; j++;
			}
		}

		for (int start = 1; start < n; ++start) {
			int i = start, j = start + 1;
			int cnt = 0;
			while (i >= 1 && j <= n) {
				if (arr1[i] == arr2[j]) cnt++;
				if (arr1[j] == arr2[i]) cnt++;
				ans = max(ans, cnt + same1[i - 1] + same2[j + 1]);
				i--; j++;
			}
		}

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
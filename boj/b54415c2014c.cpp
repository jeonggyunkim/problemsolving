#include <iostream>
#define N 1000010
using namespace std;

int arr[N];
int cnt[N];
long long sum[N + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	while (k--) {
		cin >> t;
		cnt[t]++;
	}

	for (int i = 1; i < n; ++i) {
		if (cnt[i]) {
			for (int j = 0; j < N; j += i) {
				arr[j] += cnt[i];
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + arr[i];
	}

	int q, l, r;
	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << sum[r + 1] - sum[l] << '\n';
	}
}
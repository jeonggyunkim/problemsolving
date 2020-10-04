#include <iostream>
#include <vector>
#define INF (1LL << 60)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<long long> arr(n);
	cin >> arr[n - 1];
	for (int i = 0; i < n - 1; ++i) cin >> arr[i];

	if (n % 3 == 0) {
		vector<long long> big(n);
		big[n - 1] = 0;
		big[n - 2] = 0;
		for (int i = n - 3; i >= 0; --i) {
			big[i] = arr[i] - big[i + 1] - big[i + 2];
		}

		long long p = -INF, q = -INF, pq = INF;
		for (int i = 0; i < n / 3; ++i) {
			pq = min(pq, big[3 * i]);
			p = max(p, -big[3 * i + 1]);
			q = max(q, -big[3 * i + 2]);
		}
		for (int i = 0; i < n; ++i) {
			if (i % 3 == 0) cout << big[i] - p - q - 2 << '\n';
			else if (i % 3 == 1) cout << big[i] + p + 1 << '\n';
			else cout << big[i] + q + 1 << '\n';
		}
	}
	else {
		for (int i = 0; i < n / 3; ++i) {
			arr[n - 2] -= arr[3 * i];
			arr[n - 2] += arr[3 * i + 1];
		}
		for (int i = 0; i < n / 3; ++i) {
			arr[n - 1] -= arr[3 * i];
			arr[n - 1] += arr[3 * i + 2];
		}

		if (n % 3 == 1) {
			arr[n - 1] /= 3;
			arr[n - 2] -= arr[n - 1];
		}
		else {
			arr[n - 1] *= 2;
			arr[n - 1] -= arr[n - 2];
			arr[n - 1] /= 3;
			arr[n - 2] += arr[n - 1];
			arr[n - 2] /= 2;
		}

		for (int i = n - 1; i >= 1; --i) {
			if (i - 1 >= 0) arr[i - 1] -= arr[i];
			if (i - 2 >= 0) arr[i - 2] -= arr[i];
		}
		for (int i = 0; i < n; ++i) cout << arr[i] << '\n';
	}
}
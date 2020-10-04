#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int arr[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);

	long long sum = 0;
	long long p = 1;
	for (int i = 0; i < n; ++i) {
		(sum += arr[i] * (p - 1)) %= MOD;
		(p *= 2) %= MOD;
	}

	p = 1;
	for (int i = n - 1; i >= 0; --i) {
		long long sub = arr[i] * (p - 1);
		sub %= MOD;
		sum -= sub;
		if (sum < 0) sum += MOD;
		(p *= 2) %= MOD;
	}

	cout << sum;
}
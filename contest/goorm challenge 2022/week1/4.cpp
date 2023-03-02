#include <iostream>
using namespace std;

int arr[100000];
bool notPrime[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	notPrime[1] = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (!notPrime[i]) {
			for (int j = i * i; j <= n; j += i) notPrime[j] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!notPrime[i]) ans += arr[i - 1];
	}
	cout << ans;
}
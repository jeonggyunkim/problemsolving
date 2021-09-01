#include <iostream>
#define MOD 1000000007
using namespace std;

int arr[500000];
int sum[500000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int mx, mind;
	sum[0] = 1;
	mx = arr[0];
	mind = 0;
	
	for (int i = 1; i < n; ++i) {
		if (arr[i] > mx) {
			mx = arr[i];
			mind = i;
		}
		if (mind == 0) sum[i] = 1;
		else sum[i] = sum[mind - 1] + 1;
		if (i == n - 1) cout << sum[i];
		(sum[i] += sum[i - 1]) %= MOD;
	}
}
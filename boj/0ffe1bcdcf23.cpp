#include <iostream>
#define MAX 10087654321ULL
using namespace std;

typedef unsigned long long ull;

int main() {
	int n;
	cin >> n;

	ull arr[10][2];
	ull ans = MAX;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 1; i < (1 << n); ++i) {
		ull sum = 0, prod = 1;
		for (int j = 0; j < n; ++j) {
			if ((1 << j) & i) {
				if (prod != MAX) prod *= arr[j][0];
				sum += arr[j][1];
			}
			if (prod > MAX) prod = MAX;
		}
		if (sum > prod) ans = min(ans, sum - prod);
		else ans = min(ans, prod - sum);
	}
	cout << ans;
}
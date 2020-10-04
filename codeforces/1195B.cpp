#include <bits/stdc++.h>
using namespace std;

int n, k;
long long rem(int t) {
	long long put = n - t;
	long long num = put * (put + 1) / 2 - t;
	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int low = 0, high = n;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		long long now = rem(mid);
		if (now < k) high = mid;
		else low = mid;
	}
	cout << low;
}
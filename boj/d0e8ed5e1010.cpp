#include <iostream>
using namespace std;

int n;
int arr[1000000];

long long cnt(long long t) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += t / arr[i];
	}
	return ret;
}

int main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	long long low = 0, high = arr[0] * m;
	while (high - low != 1) {
		long long mid = (low + high) / 2;
		if (cnt(mid) >= m) high = mid;
		else low = mid;
	}
	cout << high;
}
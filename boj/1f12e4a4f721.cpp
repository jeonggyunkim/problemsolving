#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[1001] = {};
	int ptr = 0;
	int n, m, t;
	cin >> n >> m;

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		arr[ptr]++;
		ptr -= t % m;
		if (ptr < 0) ptr += m;
		sum += arr[ptr];
	}
	cout << sum;
}
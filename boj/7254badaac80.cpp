#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	int num[40010], size = 1;
	num[0] = t;
	for (int i = 1; i < n; ++i) {
	cin >> t;
		if (t < num[size - 1]) *lower_bound(num, num + size, t) = t;
		else if (t > num[size - 1]) num[size++] = t;
	}
	cout << size;
}
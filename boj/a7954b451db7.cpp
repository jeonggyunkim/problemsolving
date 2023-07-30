#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int mi = 9999, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t & 1) mi = min(mi, t);
		sum += t;
	}
	if (sum & 1) cout << sum - mi;
	else cout << sum;
}
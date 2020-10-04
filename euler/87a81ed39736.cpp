#include <iostream>
using namespace std;

int main() {
	freopen("in", "rt", stdin);

	char buf[1010];
	cin >> buf;

	long long ans = -1;
	for (int i = 0; i < 1000 - 13; ++i) {
		long long prod = 1;
		for (int j = 0; j < 13; ++j) prod *= (buf[i + j] - '0');
		ans = max(ans, prod);
	}
	cout << ans << endl;
}
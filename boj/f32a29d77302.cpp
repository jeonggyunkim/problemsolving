#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	int ans = -1;
	for (int i = 0; i < 2; ++i) {
		cin >> a >> b >> c >> d;
		ans = max(ans, a + b + c + d);
	}
	cout << ans;
}
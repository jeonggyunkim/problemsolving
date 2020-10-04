#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	while (n) {
		ans += n;
		n /= m;
	}

	cout << ans;
}
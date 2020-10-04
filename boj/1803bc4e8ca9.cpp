#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	
	int now = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t == now) {
			ans++;
			now = (now + 1) % 3;
		}
	}
	cout << ans;
}
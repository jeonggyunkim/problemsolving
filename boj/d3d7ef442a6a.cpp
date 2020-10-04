#include <iostream>
using namespace std;

char t[10010];

int main() {
	int n;
	cin >> n >> t;

	int ans = 0, bonus = 0;
	for (int i = 0; i < n; ++i) {
		if (t[i] == 'O') {
			ans += i + 1;
			ans += bonus++;
		}
		else bonus = 0;
	}
	cout << ans;
}
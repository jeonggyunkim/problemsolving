#include <iostream>
#include <vector>
using namespace std;

int get(int n) {
	vector<bool> arr(100 * n + 1, 0);
	for (int i = 2; i <= 100; ++i) {
		for (int j = 1; j <= n; ++j) arr[i * j] = 1;
	}
	int ret = 0;
	for (bool u: arr) if (u) ret++;
	return ret;
}

int main() {
	int ans = 99 * 99;
	ans -= 99 * 6;
	ans += get(6);

	ans -= 99 * 4;
	ans += get(4);

	for (int i = 0; i < 4; ++i) {
		ans -= 99 * 2;
		ans += get(2);
	}

	cout << ans << endl;
}
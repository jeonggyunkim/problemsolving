#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool check[30] = {};
	int n = 28, t;
	while (n--) {
		cin >> t;
		check[t - 1] = 1;
	}
	for (int i = 0; i <30; ++i) {
		if (!check[i]) cout << i + 1 << '\n';
	}
}
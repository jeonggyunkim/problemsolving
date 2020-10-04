#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, sum, t;
	cin >> n;
	cin >> sum;

	for (int i = 1; i < n; ++i) {
		cin >> t;
		sum += t - 1;
	}
	cout << sum;
}
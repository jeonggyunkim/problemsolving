#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		sum += t;
	}

	if (sum <= n / 2) cout << "Junhee is not cute!";
	else cout << "Junhee is cute!";
}
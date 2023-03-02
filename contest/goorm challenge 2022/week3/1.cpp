#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	long long sum = 0;
	cin >> n;

	while (n--) {
		cin >> t;
		sum += t;
	}
	cout << sum << '\n';
}
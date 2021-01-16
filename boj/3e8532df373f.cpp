#include <iostream>
using namespace std;

int main() {
	int a[2];
	pair<int, int> b[2];
	for (int i = 0; i < 2; ++i) {
		cin >> a[i] >> b[i].first >> b[i].second;
	}
	cout << a[1] - a[0] + (b[0] > b[1] ? -1 : 0) << '\n';
	cout << a[1] - a[0] + 1 << '\n';
	cout << a[1] - a[0] << '\n';
}
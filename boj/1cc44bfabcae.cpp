#include <iostream>
using namespace std;

int main() {
	int n, t, arr[110] = {};
	cin >> n;

	int cnt = 0;
	while (n--) {
		cin >> t;
		if (arr[t]) cnt++;
		arr[t] = 1;
	}
	cout << cnt;
}
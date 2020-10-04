#include <iostream>
using namespace std;

bool is6(int n) {
	int cnt = 0;
	while (n) {
		if (n % 10 == 6) cnt++;
		else cnt = 0;
		if (cnt == 3) return 1;
		n /= 10;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	int i = 666;
	int cnt = 0;
	while (i) {
		if (is6(i)) cnt++;
		if (cnt == n) {
			cout << i;
			return 0;
		}
		i++;
	}
}
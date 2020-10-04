#include <iostream>
using namespace std;

bool hs(int n) {
	int a[5];
	int i = 0;
	while (n != 0) {
		a[i] = n % 10;
		n /= 10;
		i++;
	}
	for (int j = 0; j < i - 2; j++) {
		if (a[j + 1] - a[j] != a[j + 2] - a[j + 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int num;
	int cnt = 0;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		if (hs(i)) cnt++;
	}
	cout << cnt;
}
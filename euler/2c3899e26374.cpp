#include <iostream>
using namespace std;

int num[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int ten[10] = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
int hund = 7, thou = 8, an = 3;

int main() {
	int ans = 0;
	for (int i = 1; i <= 1000; ++i) {
		int j = i % 100;
		if (i == 1000) ans += num[1] + thou;
		else if (i >= 100) {
			ans += num[i / 100];
			ans += hund;
			if (j) ans += an;
		}
		if (j < 20) ans += num[j];
		else {
			ans += ten[j / 10];
			ans += num[j % 10];
		}
	}
	cout << ans << endl;
}
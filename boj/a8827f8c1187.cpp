#include <iostream>
using namespace std;

int price[10];

int main() {
	int n;
	cin >> n;

	int minp = 100;
	for (int i = 0; i < n; ++i) {
		cin >> price[i];
		if (i) minp = min(minp, price[i]);
	}

	int money;
	cin >> money;

	money -= minp;
	int len = max(0, money) / min(price[0], minp) + 1;
	money += minp;
	minp = min(minp, price[0]);

	for (int i = 0; i < len; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (money - price[j] >= (len - 1 - i) * minp) {
				cout << j;
				money -= price[j];
				break;
			}
		}
	}
}
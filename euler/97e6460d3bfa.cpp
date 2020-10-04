#include <iostream>
#include <memory.h>
using namespace std;

int arr[200], temp[200];

int main() {
	int p = 100;
	for (int i = 1; i < 10; ++i) p *= i;

	int len = 0;
	while (p) {
		arr[len++] = p % 10;
		p /= 10;
	}
	for (int i = 10; i <= 99; ++i) {
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < len; ++j) {
			temp[j] += arr[j] * (i % 10);
			temp[j + 1] += arr[j] * (i / 10);
		}
		for (int j = 0; j < len + 2; ++j) {
			if (temp[j] >= 10) {
				temp[j + 1] += temp[j] / 10;
				temp[j] %= 10;
			}
		}
		if (temp[len + 1]) len += 2;
		else len++;
		for (int j = 0; j < len; ++j) arr[j] = temp[j];
	}

	int ans = 0;
	for (int i = 0; i < len; ++i) ans += arr[i];
	cout << ans << endl;
}
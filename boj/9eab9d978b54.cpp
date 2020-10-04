#include <iostream>
using namespace std;

int main() {
	int m, d;
	cin >> m >> d;

	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int date = 0;

	for (int i = 1; i < m; i++) {
		date += a[i - 1];
	}
	date += d;

	const char* day = "SUNMONTUEWEDTHUFRISAT";

	int t = 3 * (date % 7);
	cout << day[t] << day[t + 1] << day[t + 2];
}
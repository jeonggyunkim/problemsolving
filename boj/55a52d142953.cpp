#include <iostream>
using namespace std;

char* str[2] = {"even", "odd"};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, test = 0;
	while (cin >> n, n) {
		test++;
		printf("%d. %s %d\n", test, str[n & 1], n / 2);
	}
}
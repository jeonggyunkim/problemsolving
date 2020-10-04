#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	char a[110];
	cin >> a;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] - 48;
	}
	cout << sum;
}

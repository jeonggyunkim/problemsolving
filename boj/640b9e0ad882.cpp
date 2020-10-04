#include <iostream>
using namespace std;

long long f[120];

int main() {
	int n;
	cin >> n;

	f[1] = f[2] = f[3] = 1;
	for (int i = 4; i <= 116; ++i) f[i] = f[i - 1] + f[i - 3];

	cout << f[n];
}
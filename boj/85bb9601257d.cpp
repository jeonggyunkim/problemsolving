#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tile[31] = {0, 1, 3};
	for (int i = 3; i <= 30; ++i) tile[i] = tile[i - 1] + 2 * tile[i - 2];
	tile[0] = 1;

	int n;
	cin >> n;

	int t = tile[n];
	int sym;
	if (n & 1) sym = tile[n / 2];
	else sym = tile[n / 2] + 2 * tile[n / 2 - 1];

	cout << sym + (t - sym) / 2;
}
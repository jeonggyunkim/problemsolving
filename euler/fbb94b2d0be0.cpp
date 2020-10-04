#include <iostream>
using namespace std;

int main() {
	freopen("in", "rt", stdin);
	
	char input[51];
	int sum[55] = {};
	for (int i = 0; i < 100; ++i) {
		cin >> input;
		for (int j = 0; j < 50; ++j) {
			sum[49 - j] += input[j] - '0';
		}
	}

	int i = 0;
	while (sum[i]) {
		sum[i + 1] += sum[i] / 10;
		sum[i++] %= 10;
	}

	for (int j = 1; j <= 10; ++j) {
		cout << sum[i - j];
	}
	cout << endl;
}
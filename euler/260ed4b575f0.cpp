#include <iostream>
using namespace std;

int main() {
	int sum = 0, ssum = 0;
	for (int i = 1; i <= 100; ++i) {
		sum += i;
		ssum += i * i;
	}
	cout << sum * sum - ssum << endl;
}
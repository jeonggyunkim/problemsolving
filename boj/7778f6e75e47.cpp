#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int r = 1;
	for (int i = 1; i <= N ; ++i) r *= i;

	cout << r << endl;

	return 0;
}
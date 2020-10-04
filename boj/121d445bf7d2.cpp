#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int r = 0;
	r += N / 5;
	r += N / 25;
	r += N / 125;

	cout << r << endl;

	return 0;
}
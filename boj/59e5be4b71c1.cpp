#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	N -= 1;
	for (int i = 1; i < 10110; ++i) {
		if (i * (i + 1) == N) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
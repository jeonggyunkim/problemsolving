#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int count = 0;
	int temp = 1;

	while (temp <= N) {
		if (N % temp == 0) count++;
		if (count == K) {
			cout << temp << endl;
			return 0;
		}
		temp++;
	}
	cout << 0 << endl;

	return 0;
}
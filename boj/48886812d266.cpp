#include <iostream>
using namespace std;

int main() {
	int K, N, M;
	cin >> K >> N >> M;

	if (K*N - M >= 0) {
		cout << K*N - M << endl;
	}
	else {
		cout << 0 << endl;
	}
}
#include <iostream>
using namespace std;

int main() {
	int N, O, P;

	cin >> N >> O;

	N--;
	P = O / N;
	if (O - P * N == 0) cout << O + P - 1 << " " << O + P << endl;
	else cout << O + P << " " << O + P << endl;

	return 0;
}
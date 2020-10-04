#include <iostream>
using namespace std;

int main() {
	int A, B, C, n;
	cin >> A >> B >> C;
	if (C - B <= 0) cout << -1 << endl;
	else cout << A / (C - B) + 1 << endl;

	return 0;
}
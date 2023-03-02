#include <iostream>
using namespace std;

int main() {
	int t, s;
	cin >> t >> s;
	cout << (12 <= t && t <= 16 && !s ? 320 : 280);
}
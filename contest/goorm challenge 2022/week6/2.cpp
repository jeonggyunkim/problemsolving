#include <iostream>
#define SQ(a) (a) * (a)
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	for (int i = 0; i < n; i += 2) {
		cout << (char)('a' + ((s[i] - 'a') + SQ(s[i + 1] - '0')) % 26);
	}
}
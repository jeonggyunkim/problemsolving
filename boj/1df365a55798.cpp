#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s;
	while (n--) {
		cin >> s;
		if (s.back() & 1) cout << "odd\n";
		else cout << "even\n";
	}
}
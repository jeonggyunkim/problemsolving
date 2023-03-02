#include <iostream>
using namespace std;

string s = "rsefaqtdwczxvg";

int main() {
	int n;
	string t;
	cin >> n >> t;
	for (char u: s) {
		if (u == t.back()) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
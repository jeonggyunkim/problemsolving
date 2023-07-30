#include <iostream>
using namespace std;

int main() {
	string s, t = "MOBIS";
	cin >> s;

	int ans = 1;
	for (char u: t) {
		int pos = 0;
		for (char v: s) {
			if (u == v) pos = 1;
		}
		ans &= pos;
	}
	cout << (ans ? "YES" : "NO");
}
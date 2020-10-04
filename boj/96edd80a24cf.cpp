#include <iostream>
#include <string>
using namespace std;

string bottle(int n, bool first) {
	string s;
	if (n == 0) {
		if (first) s += "No more";
		else s += "no more";
	}
	else s += to_string(n);

	if (n == 1) s += " bottle";
	else s += " bottles";

	return s;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = n; i >= 0; --i) {
		cout << bottle(i, 1);
		cout << " of beer on the wall, ";
		cout << bottle(i, 0);
		cout << " of beer.\n";

		if (i == 0) cout << "Go to the store and buy some more, ";
		else cout << "Take one down and pass it around, ";

		cout << bottle(i == 0 ? n : i - 1, 0);
		cout << " of beer on the wall.\n";

		if (i) cout << '\n';
	}
}
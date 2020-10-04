#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int x = -1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'x') x = i;
	}

	int aa = 0, bb = 0;
	if (x == -1) {
		bb = atoi(s.c_str());
	}
	else {
		string a, b;
		for (int i = 0; i < x; ++i) a += s[i];
		aa = atoi(a.c_str());
		if (s.size() - 1 != x) {
			for (int i = x + 1; i < s.size(); ++i) b += s[i];
			bb = atoi(b.c_str());
		}
	}
	aa /= 2;

	if (aa) {
		if (aa == 1) ;
		else if (aa == -1) cout << '-';
		else cout << aa;
		cout << "xx";
	}
	if (bb) {
		if (aa && bb > 0) cout << "+";
		if (bb == 1) ;
		else if (bb == -1) cout << '-';
		else cout << bb;
		cout << "x";
	}
	if (aa || bb) cout << "+";
	cout << "W";
}
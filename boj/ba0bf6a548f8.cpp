#include <iostream>
#include <algorithm>
using namespace std;

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

string tail(string s) {
	return s.substr(1, s.size() - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string s;
		cin >> s;

		string t = s.substr(0, (s.size() + 2) / 3);
		if (s == t + rev(t) + t || s == t  + tail(rev(t)) + t || s == t + rev(t) + tail(t) || s == t + tail(rev(t)) + tail(t)) cout << "1\n";
		else cout << "0\n";
	}
}
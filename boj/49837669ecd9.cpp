#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int ans = s.size();
	for (char u: s) {
		if (u == ':') ans += 1;
		if (u == '_') ans += 5;
	}
	cout << ans;
}
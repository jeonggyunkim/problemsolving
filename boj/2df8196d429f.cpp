#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a = 0, b = 0;
	cin >> n;

	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') a++;
		else b++;
	}
	if (a == b) cout << "Tie";
	else if (a < b) cout << "B";
	else cout << "A";
}
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		string s;
		cin >> s;
		cout << s[0] << s.back() << '\n';
	}
}
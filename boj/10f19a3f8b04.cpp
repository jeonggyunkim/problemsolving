#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ispel(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	return a == b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 'a' - 'A';
		}
		if (ispel(s)) cout << "Yes\n";
		else cout << "No\n";
	}
}
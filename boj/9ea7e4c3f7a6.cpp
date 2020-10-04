#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		
		int i = 0;
		if (s[i] == 'A') ;
		else if (s[i] <= 'F') i++;
		else goto err;

		if (i >= s.size() || s[i] != 'A') goto err;
		while (i < s.size() && s[i] == 'A') i++;
		if (i >= s.size() || s[i] != 'F') goto err;
		while (i < s.size() && s[i] == 'F') i++;
		if (i >= s.size() || s[i] != 'C') goto err;
		while (i < s.size() && s[i] == 'C') i++;

		if (i == s.size() || (i == s.size() - 1 && s[i] <= 'F')) {
			cout << "Infected!\n";
			continue;
		}

		err:
		cout << "Good\n";
	}
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
	}
	cout << cnt;
}
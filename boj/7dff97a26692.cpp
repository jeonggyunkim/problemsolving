#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[i - 1]) cnt++;
	}
	cout << cnt / 2;
}
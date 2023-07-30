#include <iostream>
#include <algorithm>
using namespace std;

int score[8] = { 10, 8, 6, 5, 4, 3, 2, 1 };

int main() {
	char c;
	string s[8];
	for (int i = 0; i < 8; ++i) {
		cin >> s[i];
		cin >> c;
		s[i] += c;
	}
	sort(s, s + 8);

	int r = 0, b = 0;
	for (int i = 0; i < 8; ++i) {
		if (s[i].back() == 'R') r += score[i];
		else b += score[i];
	}
	if (r > b) cout << "Red";
	else if (r < b) cout << "Blue";
	else if (s[0].back() == 'R') cout << "Red";
	else cout << "Blue";
}
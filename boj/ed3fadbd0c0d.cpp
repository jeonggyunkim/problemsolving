#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	char buf[] = "CAMBRIDGE";
	for (int i = 0; i < s.size(); ++i) {
		bool brk = 0;
		for (int j = 0; j < 9; ++j) {
			if (s[i] == buf[j]) {
				brk = 1;
				break;
			}
		}
		if (!brk) cout << s[i];
	}
}
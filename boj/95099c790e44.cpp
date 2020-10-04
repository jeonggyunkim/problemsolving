#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	bool f = 0;
	for (int i = 1; i <= 5; ++i) {
		cin >> s;
		if (s.find("FBI") != -1) {
			cout << i << ' ';
			f = 1;
		}
	}
	if (!f) cout << "HE GOT AWAY!";
}
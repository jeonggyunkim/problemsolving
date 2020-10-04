#include <iostream>
using namespace std;

int main() {
	char s[3], t = 0;
	cin >> s;

	if (s[0] == 'F') {
		cout << "0.0";
		return 0;
	}
	t = ('A' - s[0] + 4) * 10;
	if (s[1] == '+') t += 3;
	else if (s[1] == '-') t -= 3;
	cout << t / 10 << '.' << t % 10;
}

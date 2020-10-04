#include <iostream>
using namespace std;

int main() {
	int a = 1, b = 0, c = 0;
	int temp;
	char d[51];

	cin >> d;
	int i = 0;
	while (d[i] != 0) {
		if (d[i] == 'A') swap(a, b);
		else if (d[i] == 'B') swap(b, c);
		else swap(a, c);
		++i;
	}

	if (a) cout << 1;
	if (b) cout << 2;
	if (c) cout << 3;
}
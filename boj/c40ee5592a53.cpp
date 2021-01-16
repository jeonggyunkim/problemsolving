#include <iostream>
using namespace std;

char* key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'\nZXCVBNM,./";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char t;
	while ((t = getchar()) != -1) {
		if (t == ' ' || t == '\n') cout << t;
		else {
			for (int i = 0; key[i]; ++i) {
				if (t == key[i]) cout << key[i - 1];
			}
		}
	}
}
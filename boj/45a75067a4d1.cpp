#include <iostream>
using namespace std;

int main() {
	char a[80];
	for (int i = 0; i < 80; ++i) {
		a[i] = 0;
	}
	for (int i = 0; i < 5; ++i) {
		scanf("%s", a + 16 * i);
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (a[j * 16 + i] != 0) printf("%c", a[j * 16 + i]);
		}
	}

	return 0;
}
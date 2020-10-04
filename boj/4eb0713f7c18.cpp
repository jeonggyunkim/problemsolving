#include <iostream>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	int aa = a;
	int bb = b;
	int p;
	for (int i = 0; i < 3; ++i) {
		if (aa % 10 != bb % 10) {
			if (aa % 10 > bb % 10) {
				p = a;
			}
			else {
				p = b;
			}
			break;
		}
		aa /= 10;
		bb /= 10;
	}

	for (int i = 0; i < 3; ++i) {
		cout << p % 10;
		p /= 10;
	}

	return 0;
}
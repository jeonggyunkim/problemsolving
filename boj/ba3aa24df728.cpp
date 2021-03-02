#include <iostream>
using namespace std;

int main() {
	int n, l, d;
	cin >> n >> l >> d;
	n--;

	if (d == 1) {
		cout << l;
		return 0;
	}

	int bell = 1, off = 0, gok = l, empty = 0, time = 0;
	while (1) {
		if (bell && empty) {
			cout << time;
			return 0;
		}

		if (bell) {
			bell--;
			if (bell == 0) off = d - 1;
		}
		else {
			off--;
			if (off == 0) bell = 1;
		}

		if (gok) {
			gok--;
			if (gok == 0) {
				empty = 5;
				if (n == 0) empty = 9999;
			}
		}
		else {
			empty--;
			if (empty == 0 && n) {
				gok = l;
				n--;
			}
		}
		time++;
	}
}
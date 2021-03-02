#include <iostream>
using namespace std;

int main() {
	int m, a, b;
	while (cin >> m >> a >> b, m || a || b) {
		if (a == b) {
			cout << "0:00:00\n";
		}
		else {
			int p = m * (b - a);
			int q = a * b;
			int hour, min, sec;
			hour = p / q;
			p %= q;
			p *= 60;
			min = p / q;
			p %= q;
			p *= 60;
			sec = p / q;
			p %= q;
			if (p >= (q + 1) / 2) sec++;
			if (sec == 60) {
				sec = 0;
				min++;
			}
			if (min == 60) {
				min = 0;
				hour++;
			}
			printf("%d:%02d:%02d\n", hour, min, sec);
		}
	}
}
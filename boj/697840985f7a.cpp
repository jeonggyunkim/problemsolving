#include <iostream>

int main() {
	char buf[1003];
	while (scanf("%s", buf), buf[0] != '0') {
		int i = 0, dgi = 0;
		while (buf[i]) {
			dgi += (buf[i] - '0');
			i++;
		}
		while (dgi >= 10) {
			int n = dgi;
			dgi = 0;
			while (n) {
				dgi += n % 10;
				n = n / 10;
			}
		}
		printf("%d\n", dgi);
	}
}
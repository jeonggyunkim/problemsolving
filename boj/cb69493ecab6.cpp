#include <iostream>
using namespace std;

int main() {
	char t;
	while ((t = getchar()) != EOF) {
		if ('A' <= t && t <= 'Z') putchar(t + 32);
		if ('a' <= t && t <= 'z') putchar(t - 32);
	}
}
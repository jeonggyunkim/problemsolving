#include <iostream>
using namespace std;

long long fib[50];

const char base1[] = "Messi ";
const char base2[] = "Messi Gimossi ";

char find(int i, int m) {
	if (i == 1) {
		return base1[m - 1];
	}
	if (i == 2) {
		return base2[m - 1];
	}
	if (m <= fib[i - 1]) return find(i - 1, m);
	else return find(i - 2, m - fib[i - 1]);
}

int main() {
	fib[1] = 6; fib[2] = 14;
	for (int i = 3; i < 50; ++i) fib[i] = fib[i - 1] + fib[i - 2];

	int m;
	cin >> m;
	int i = 1;
	while (fib[i] < m) i++;

	char t = find(i, m);
	if (t == ' ') cout << "Messi Messi Gimossi";
	else cout << t;
}
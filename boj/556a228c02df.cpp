#include <iostream>
#include <map>
using namespace std;

int p;

int cal(int n) {
	int r = 0, rr;
	while (n) {
		rr = 1;
		for (int i = 0; i < p; ++i) rr *= (n % 10);
		r += rr;
		n /= 10;
	}
	return r;
}

int main() {
	int a, i = 0;
	scanf("%d %d", &a, &p);
	map<int, int> m;
	while (m.find(a) == m.end()) {
		m[a] = i++;
		a = cal(a);
	}
	printf("%d\n", m[a]);
}
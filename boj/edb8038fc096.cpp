#include <iostream>

int n, cnt = 0;

int ver = 0;
int diag1 = 0;
int diag2 = 0;

void search(int line) {
	if (line == n) cnt++;
	for (int i = 0; i < n; ++i) {
		if (!(ver & (1 << i)) && !(diag1 & (1 << (line + i))) && !(diag2 & (1 << (line - i + 15)))) {
			if (line == n - 1) cnt++;
			else {
				ver |= (1 << i);
				diag1 |= (1 << (line + i));
				diag2 |= (1 << (line - i + 15));
				search(line + 1);
				ver &= ~(1 << i);
				diag1 &= ~(1 << (line + i));
				diag2 &= ~(1 << (line - i + 15));
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	search(0);
	printf("%d\n", cnt);
}
#include <iostream>
using namespace std;

int n;
int input[15];
int num[15];

void print() {
	for (int i = 0; i < 6; ++i) {
		printf("%d ", ::num[i]);
	}
	printf("\n");
}

void create(int* input, int r, int* num, int depth) {
	if (depth == 6) {
		print();
		return;
	}
	for (int i = 0; i < r; ++i) {
		*num = input[i];
		create(input + i + 1, r - i, num + 1, depth + 1);
	}
}

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", input + i);
		}
		create(input, n - 5, num, 0);
		printf("\n");
	}
}
#include <iostream>

int main() {
	int n;
	char input[100][100] = {0};
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &input[i][j]);

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (input[i][j] == 0 && input[i][k] == 1 && input[k][j] == 1) input[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) printf("%d ", input[i][j]);
		printf("\n");
	}
}
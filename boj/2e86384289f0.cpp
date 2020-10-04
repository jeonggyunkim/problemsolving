#include <iostream>

int main() {
	int H, M;
	bool h = false;
	scanf("%d %d", &H, &M);

	if (M < 45) {
		M += 15;
		h = true;
	}
	else M -= 45;

	if (h) {
		if (H) H -= 1;
		else H = 23;
	}
	printf("%d %d\n", H, M);
	return 0;
}
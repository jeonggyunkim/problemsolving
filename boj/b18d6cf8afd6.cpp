#include <iostream>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main() {
	int n;
	scanf("%d", &n);

	int ma[3] = {0}, mi[3] = {0}, num[3], t[3];
	while (n--) {
		scanf("%d %d %d", num, num + 1, num + 2);
		t[0] = max(ma[0], ma[1]) + num[0];
		t[1] = max(ma[0], max(ma[1], ma[2])) + num[1];
		t[2] = max(ma[1], ma[2]) + num[2];
		for (int i = 0; i < 3; ++i) ma[i] = t[i];
		t[0] = min(mi[0], mi[1]) + num[0];
		t[1] = min(mi[0], min(mi[1], mi[2])) + num[1];
		t[2] = min(mi[1], mi[2]) + num[2];
		for (int i = 0; i < 3; ++i) mi[i] = t[i];
	}
	printf("%d %d\n", max(ma[0], max(ma[1], ma[2])), min(mi[0], min(mi[1], mi[2])));
}
#include <iostream>

int in[100001];
int pre[100001];

void travel(int in_s, int in_f, int pre_s, int pre_f) {
	if (in_f - in_s <= 1) {
		if (in_f - in_s == 1) printf("%d ", in[in_s]);
		return;
	}

	int root = pre[pre_f - 1];
	printf("%d ", root);
	int n = in_s;
	while (in[n] != root) n++;
	n -= in_s;
	travel(in_s, in_s + n, pre_s, pre_s + n);
	travel(in_s + n + 1, in_f, pre_s + n, pre_f - 1);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", in + i);
	for (int i = 0; i < n; ++i) scanf("%d", pre + i);

	travel(0, n, 0, n);
}
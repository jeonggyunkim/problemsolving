#include <iostream>

char input[1005];
char temp[1005];

int rev(int n) {
	int i = n, mid, end;
	for (int rep = 0; rep < 4; ++rep) {
		if (input[i] == 'x') i = rev(++i);
		else ++i;
		if (rep == 1) mid = i;
		if (rep == 3) end = i;
	}

	i = 0;
	for (int j = n; j < mid; ++j) temp[i++] = input[j];
	i = n;
	for (int j = mid; j < end; ++j) input[i++] = input[j];
	for (int j = 0; j < mid - n; ++j) input[i++] = temp[j];

	return end;
}

int main() {
	int tc;
	scanf("%d", &tc);


	while (tc--) {
		scanf("%s", input);

		if (input[0] != 'x') {
			printf("%c\n", input[0]);
			continue;
		}

		rev(1);
		printf("%s\n", input);
	}
}

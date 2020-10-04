#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, t;
	scanf("%d", &n);

	vector<int> cnt(53, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		cnt[t]++;
	}

	char c;
	getchar();

	for (int i = 0; i < n; ++i) {
		c = getchar();
		if (c == ' ') cnt[0]--;
		if (c >= 'A' && c <= 'Z') cnt[c - 'A' + 1]--;
		if (c >= 'a' && c <= 'z') cnt[c - 'a' + 27]--;
	}

	for (int i = 0; i < 53; ++i) if (cnt[i] != 0) {
		printf("n");
		return 0;
	}
	printf("y");
}
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	ii input[500000];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &(input[i].first));
		input[i].second = i;
	}
	sort(input, input + n);

	int max = -1, t;
	for (int i = 0; i < n; ++i) {
		t = input[i].second - i;
		if (t > max) max = t;
	}
	printf("%d\n", max + 1);
}
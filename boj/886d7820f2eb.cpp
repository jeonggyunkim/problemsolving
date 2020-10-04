#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	pair<int, int> input[100001];
	char name[100001][101];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %s", &(input[i].first), name[i]);
		 input[i].second = i;
	}
	sort(input, input + n);
	for (int i = 0; i < n; ++i) {
		printf("%d %s\n", input[i].first, name[input[i].second]);
	}
}
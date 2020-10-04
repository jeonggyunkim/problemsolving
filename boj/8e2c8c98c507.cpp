#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	ii input[100001];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d %d", &(input[i].second), &(input[i].first));
	sort(input, input + n);
	for (int i = 0; i < n; ++i) printf("%d %d\n", input[i].second, input[i].first);
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int num[1000010];
	int ind[1000010];
	int lis[10010];

	scanf("%d", num);
	lis[0] = num[0]; ind[0] = 0;
	int index = 1;
	for (int i = 1; i < n; ++i) {
		scanf("%d", num + i);
		if (num[i] < lis[index - 1]) {
			int* ptr = lower_bound(lis, lis + index, num[i]);
			*ptr = num[i];
			ind[i] = ptr - lis;
		}
		else if (num[i] == lis[index - 1]) {
			ind[i] = index;
		}
		else {
			lis[index++] = num[i];
			ind[i] = index - 1;
		}
	}
	printf("%d\n", index--);
	vector<int> v;
	for (int i = n - 1; i >= 0; --i) {
		if (ind[i] == index) {
			v.push_back(num[i]);
			index--;
		}
	}
	while (!v.empty()) {
		printf("%d ", v.back());
		v.pop_back();
	}
	printf("\n");
}
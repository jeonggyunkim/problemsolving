#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char num[100001];
	scanf("%s", num);
	int sum = 0, i = 0;
	bool zero = false;
	while (num[i]) {
		if (num[i] == '0') zero = true;
		sum += num[i++] - '0';
	}
	if ((sum % 3 == 0) && zero) {
		sort(num, num + i, greater<char>());
		for (int j = 0; j < i; ++j) printf("%c", num[j]);
	}
	else printf("-1");
}
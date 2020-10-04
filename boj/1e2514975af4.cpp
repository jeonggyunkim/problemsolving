#include <iostream>
#include <vector>
using namespace std;

int main() {
	char buf[55];
	scanf("%s", buf);

	vector<int> num;
	vector<bool> sign;

	int i = 0, t = 0;
	while (buf[i] >= '0' && buf[i] <= '9') {
		t *= 10; t += (buf[i++] - '0');
	}
	num.push_back(t); sign.push_back(1);
	while (buf[i]) {
		if (buf[i++] == '+') sign.push_back(1);
		else sign.push_back(0);
		t = 0;
		while (buf[i] >= '0' && buf[i] <= '9') {
			t *= 10; t += (buf[i++] - '0');
		}
		num.push_back(t);
	}

	int ret = 0;
	i = 0;
	while (i < sign.size() && sign[i] == 1) ret += num[i++];
	while (i < sign.size()) ret -= num[i++];

	printf("%d\n", ret);
}
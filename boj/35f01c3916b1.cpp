#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> neg;
	vector<int> pos;
	bool zero = false;
	int n, t;
	scanf("%d", &n);

	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		if (t == 0) zero = true;
		else if (t < 0) neg.push_back(-t);
		else {
			if (t == 1) ret += 1;
			else pos.push_back(t);
		}
	}

	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end(), greater<int>());

	for (int i = 0; i < pos.size() / 2; ++i) ret += pos[2 * i] * pos[2 * i + 1];
	if (pos.size() & 1) ret += pos.back();
	for (int i = 0; i < neg.size() / 2; ++i) ret += neg[2 * i] * neg[2 * i + 1];
	if (neg.size() & 1 && !zero) ret -= neg.back();

	printf("%lld\n", ret);
}
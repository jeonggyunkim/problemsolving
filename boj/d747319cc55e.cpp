#include <iostream>
#include <set>
using namespace std;

int main() {
	int coin[103];

	int n, k, t;
	scanf("%d %d", &n, &k);

	set<int> s;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		s.insert(t);
	}

	int i = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) coin[i++] = *it;

	int num[10010] = {0};
	int temp[10010];
	for (i = 0; i <= k; ++i) {
		if (i % coin[0] == 0) num[i] = 1;
		else num[i] = 0;
	}
	for (int rep = 1; rep < s.size(); ++rep) {
		for (i = 0; i <= k; ++i) {
			t = i;
			int cnt = 0;
			while (t >= 0) {
				cnt += num[t];
				t -= coin[rep];
			}
			temp[i] = cnt;
		}
		for (i = 0; i <= k; ++i) num[i] = temp[i];
	}
	printf("%d\n", num[k]);
}
#include <iostream>
#include <set>
using namespace std;

int cnt = 0;
int val[103];
int coin[10010] = {0};

int cal(int n) {
	if (n == 0) return 0;
	if (coin[n] != 0) return coin[n];
	int min = 100000, t = 0;
	for (int i = 0 ; i < cnt; ++i) {
		if (n - val[i] >= 0) t = cal(n - val[i]) + 1;
		if (t != 0 && t < min) min = t;
	}
	if (min != 100000) return coin[n] = min;
	else return coin[n] = -1;
}

int main() {
	int m, k, t;
	scanf("%d %d", &m, &k);

	set<int> s;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		s.insert(t);
	}

	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) val[cnt++] = *it;
	printf("%d\n", cal(k));
}
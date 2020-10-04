#include <iostream>
#include <memory.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int, int, int, int> i6;

int seq[1010];

int main() {
	int p;
	scanf("%d", &p);

	int th = (p + 39) / 40 + 1;

	for (int i = 0; i < p; ++i) scanf("%d", seq + i);

	i6 ans;
	get<0>(ans) = 9876;
	int first[10][10], second[10][10], third[10][10], cnt[10][10], occ[10][10];
	for (int len = 2; len < p; ++len) {
		for (int m = 1; m < len; ++m) {
			int n = len - m;
			memset(first, -1, sizeof(first));
			memset(second, -1, sizeof(second));
			memset(third, -1, sizeof(third));
			memset(cnt, 0, sizeof(cnt));
			for (int ai = 0; ai < p - len; ++ai) {
				int a = seq[ai], b = seq[ai + n], c = seq[ai + n + m];
				if (first[b][c] == -1) {
					first[b][c] = a;
					cnt[b][c]++;
					occ[b][c] = ai;
				}
				else if (first[b][c] != a) first[b][c] = -2;
				else cnt[b][c]++;
				
				if (second[a][c] == -1) second[a][c] = b;
				else if (second[a][c] != b) second[a][c] = -2;
				
				if (third[a][b] == -1) third[a][b] = c;
				else if (third[a][b] != c) third[a][b] = -2;
			}
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					int k = first[i][j];
					if (k >= 0) {
						if (second[k][j] == i && third[k][i] == j && cnt[i][j] >= th) {
							i6 now = {occ[i][j], n, m, k, i, j};
							if (now < ans) ans = now;
						}
					}
				}
			}
		}
	}
	if (get<0>(ans) == 9876) printf("random sequence\n");
	else printf("triple correlation %d(%d)%d(%d)%d found\n", get<3>(ans), get<1>(ans), get<4>(ans), get<2>(ans), get<5>(ans));
}
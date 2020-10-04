#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int field[50][50] = {0};
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		int x, y;
		for (int i = 0; i < k; ++i) {
			scanf("%d %d", &x, &y);
			field[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (field[i][j] == 1) {
					cnt++;
					vector<int> v;
					v.push_back(i * 50 + j);
					field[i][j] = 0;
					int p, q;
					while (v.size() != 0) {
						p = v.back();
						v.pop_back();
						q = p % 50;
						p /= 50;
						if (p > 0 && field[p - 1][q] == 1) {
							v.push_back((p - 1) * 50 + q);
							field[p - 1][q] = 0;
						}
						if (p < m - 1 && field[p + 1][q] == 1) {
							v.push_back((p + 1) * 50 + q);
							field[p + 1][q] = 0;
						}
						if (q > 0 && field[p][q - 1] == 1) {
							v.push_back(p * 50 + q - 1);
							field[p][q - 1] = 0;
						}
						if (q < n - 1 && field[p][q + 1] == 1) {
							v.push_back(p * 50 + q + 1);
							field[p][q + 1] = 0;
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > info =
{{0, 1, 2},
{3, 14, 15},
{4, 10, 14, 15},
{0, 2, 14, 15},
{0, 4, 5, 6, 7},
{4, 5, 7, 14, 15},
{1, 2, 3, 4, 5}};

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int clock[16];
		for (int i = 0; i < 16; ++i) {
			scanf("%d", clock + i);
			clock[i] /= 3;
		}

		int before = 0;
		for (int i = 0; i < 4 - clock[11]; ++i) { clock[3]++; clock[7]++; clock[9]++; before++; }
		for (int i = 0; i < 4 - clock[12]; ++i) { clock[6]++; clock[7]++; clock[8]++; clock[10]++; before++; }
		for (int i = 0; i < 4 - clock[13]; ++i) { clock[3]++; clock[4]++; clock[5]++; clock[9]++; before++; }
		clock[11] = clock[12] = clock[13] = 4;

		int rot[7] = {0}, min = 100, t, n;
		bool brk;
		for (int i = 0; i < (1 << 14); ++i) {
			brk = false;
			for (int j = 0; j < 16; ++j) {
				if (clock[j] & 3) {
					brk = true;
					break;
				}
			}
			if (!brk) {
				t = before;
				for (int j = 0; j < 7; ++j) t += (rot[j] & 3);
				if (t < min) min = t;
			}

			n = 0;
			t = i;
			rot[0]++;
			for (int j = 0; j < info[n].size(); ++j) clock[info[n][j]]++;
			while (n < 6 && (t & 3) == 3) {
				++n;
				rot[n]++;
				for (int j = 0; j < info[n].size(); ++j) clock[info[n][j]]++;
				t >>= 2;
			}
		}
		if (min == 100) printf("-1\n");
		else printf("%d\n", min);
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, area;
char map[26][26];

void search(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n) return;
	if (map[i][j] == '0') return;
	area++;
	map[i][j] = '0';
	search(i - 1, j);
	search(i + 1, j);
	search(i, j - 1);
	search(i, j + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", map[i]);

	vector<int> v;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (map[i][j] == '1') {
			area = 0;
			search(i, j);
			v.push_back(area);
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); ++i) printf("%d\n", v[i]);
}
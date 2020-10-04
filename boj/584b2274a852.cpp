#include <iostream>

int main() {
	int n, cnt1 = 0, cnt2 = 0;
	char room[101][101];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", room[i]);

	for (int i = 0; i < n; ++i) {
		int j = 0;
		bool s = false;
		while (j < n) {
			if (room[i][j] == '.') {
				if (!s) { s = true; j++; }
				else {
					cnt1++;
					while (j < n && room[i][j] == '.') j++;
					s = false;
				}
			}
			else { s = false; j++; }
		}
		j = 0; s = false;
		while (j < n) {
			if (room[j][i] == '.') {
				if (!s) { s = true; j++; }
				else {
					cnt2++;
					while (j < n && room[j][i] == '.') j++;
					s = false;
				}
			}
			else { s = false; j++; }
		}
	}
	printf("%d %d", cnt1, cnt2);
}
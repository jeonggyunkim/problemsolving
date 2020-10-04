#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;

		char s1[25];
		int s2 = 0;

		char t1[25];
		int t2;

		for (int j = 0; j < m; ++j) {
			cin >> t1 >> t2;
			if (t2 > s2) {
				s2 = t2;
				int k = -1;
				do {
					k++;
					s1[k] = t1[k];
				} while (t1[k] != '\0');
			}
		}
		cout << s1 << endl;
	}

	return 0;
}
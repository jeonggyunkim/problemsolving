#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, tc;
	char t;
	scanf("%d", &tc);
	for (int test = 1; test <= tc; ++test) {
		scanf("%d ", &n);

		string max_string;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			while ((t = getchar()) != '\n' && t != EOF) {
				s.push_back(t);
			}
			if (s < max_string) {
				ans++;
			}
			else max_string = s;
		}
		printf("Case #%d: %d\n", test, ans);
	}
}
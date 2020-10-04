#include <iostream>
#include <memory.h>
using namespace std;

int trie[100000][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(trie, 0, sizeof(trie));
		int n;
		cin >> n;

		char input[12];
		int cnt = 1;
		bool ans = 1;
		while (n--) {
			cin >> input;
			if (!ans) continue;
			int now = 0;
			for (int i = 0; input[i]; ++i) {
				int num = input[i] - '0';
				if (trie[now][num] == 0) {
					if (input[i + 1] == 0) trie[now][num] = -1;
					else {
						trie[now][num] = cnt;
						now = cnt++;
					}
				}
				else if (trie[now][num] == -1) {
					ans = 0;
					break;
				}
				else {
					if (input[i + 1] == 0) {
						ans = 0;
						break;
					}
					else now = trie[now][num];
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int trie[2020010][26];
int cnt[2020010];
int ind;

vector<int> solution(vector<string> words, vector<string> queries) {
	memset(trie, 0, sizeof(trie));
	memset(cnt, 0, sizeof(cnt));
	ind = 20001;
	for (string& s: words) {
		int len = s.size();
		int now = len;
		for (int i = 0; i < len; ++i) {
			cnt[now]++;
			if (trie[now][s[i] - 'a'] == 0) {
				trie[now][s[i] - 'a'] = ind;
				now = ind++;
			}
			else {
				now = trie[now][s[i] - 'a'];
			}
		}

		now = 10000 + len;
		for (int i = len - 1; i >= 0; --i) {
			cnt[now]++;
			if (trie[now][s[i] - 'a'] == 0) {
				trie[now][s[i] - 'a'] = ind;
				now = ind++;
			}
			else {
				now = trie[now][s[i] - 'a'];
			}
		}
	}

	vector<int> ans;
	for (string& s: queries) {
		int len = s.size();
		if (s[0] == '?') {
			int now = 10000 + len;
			for (int i = len - 1; i >= 0; --i) {
				if (s[i] == '?') {
					ans.push_back(cnt[now]);
					break;
				}
				if (trie[now][s[i] - 'a'] == 0) {
					ans.push_back(0);
					break;
				}
				now = trie[now][s[i] - 'a'];
			}
		}
		else {
			int now = len;
			for (int i = 0; i < len; ++i) {
				if (s[i] == '?') {
					ans.push_back(cnt[now]);
					break;
				}
				if (trie[now][s[i] - 'a'] == 0) {
					ans.push_back(0);
					break;
				}
				now = trie[now][s[i] - 'a'];
			}
		}
	}
	return ans;
}

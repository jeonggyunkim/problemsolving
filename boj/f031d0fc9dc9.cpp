#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Dir {
	string name;
	int p;
	int size = 0;
	bool expand = 0;
	map<string, int> child;
};

vector<string> split(string& s) {
	vector<string> ret;
	int start = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '/') {
			ret.push_back(s.substr(start, i - start));
			start = i + 1;
		}
	}
	return ret;
}

Dir dir[50000];
int cnt = 1;

void print(int i, string now) {
	if (dir[i].expand) {
		cout << "- " << now << ' ' << dir[i].size << '\n';
		for (auto it = dir[i].child.begin(); it != dir[i].child.end(); ++it) {
			print(it->second, now + it->first + '/');
		}
	}
	else {
		if (dir[i].child.size() == 0) {
			cout << "  " << now << ' ' << dir[i].size << '\n';
		}
		else {
			cout << "+ " << now << ' ' << dir[i].size << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dir[0].name = "/";
	dir[0].p = -1;

	int n, sz;
	cin >> n;
	string s;
	while (n--) {
		cin >> s >> sz;
		vector<string> d = split(s);
		int now = 0;
		for (int i = 0; i < d.size(); ++i) {
			if (dir[now].child.count(d[i])) {
				now = dir[now].child[d[i]];
			}
			else {
				dir[now].child[d[i]] = cnt;
				dir[cnt].name = d[i];
				dir[cnt].p = now;
				now = cnt++;
			}
		}
		while (now != -1) {
			dir[now].size += sz;
			now = dir[now].p;
		}
	}
	int th;
	cin >> th;

	for (int i = 0; i < cnt; ++i) {
		if (dir[i].size >= th) {
			int now = dir[i].p;
			while (now != -1) {
				dir[now].expand = 1;
				now = dir[now].p;
			}
		}
	}

	print(0, "/");
}
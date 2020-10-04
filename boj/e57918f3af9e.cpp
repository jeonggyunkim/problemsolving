#include <iostream>
#include <string>
#include <map>
#include <memory.h>
#define INF 1000000001
using namespace std;

map<string, int> name;

int jae[1000][50];
long long price[1000];

int main() {
	memset(price, -1, sizeof(price));

	int n, m;
	cin >> n >> m;

	string s, t;
	int ind = 1, w;
	while (n--) {
		cin >> s >> w;
		name[s] = ind;
		price[ind++] = w;
	}

	for (int i = 0; i < m; ++i) {
		cin >> s;
		int j = s.find('='), k = 1;
		t = s.substr(0, j);
		if (!name.count(t)) name[t] = ind++;
		jae[i][0] = name[t];
		j++;
		while (j < s.size()) {
			t.clear();
			int num = s[j++] - '0';
			while (j < s.size() && 'A' <= s[j] && s[j] <= 'Z') {
				t += s[j++];
			}
			if (!name.count(t)) name[t] = ind++;
			jae[i][k++] = name[t];
			jae[i][k++] = num;
			if (j < s.size()) j++;
		}
	}

	while (1) {
		bool cng = 0;
		for (int j = 0; jae[j][0]; ++j) {
			long long now = 0;
			bool pos = 1;
			for (int k = 1; jae[j][k]; k += 2) {
				if (price[jae[j][k]] != -1) {
					now += price[jae[j][k]] * jae[j][k + 1];
				}
				else {
					pos = 0;
					break;
				}
			}
			if (pos) {
				if (price[jae[j][0]] == -1 || now < price[jae[j][0]]) {
					if (now >= INF) now = INF;
					price[jae[j][0]] = now;
					cng = 1;
				}
			}
		}
		if (!cng) break;
	}

	cout << price[name["LOVE"]];
}
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> m = {{'U', 0}, {'D', 3}, {'F', 1}, {'B', 4}, {'L', 5}, {'R', 2}};
string pr = "wrbyog";
int side[6][4] = { {1, 2, 4, 5}, {2, 0, 5, 3}, {3, 4, 0, 1}, {5, 4, 2, 1}, {3, 5, 0, 2}, {1, 0, 4, 3} };

class cube {
public:
	string color[6][6];
	void init();
	void rotate(int c, int a[4], int b);
	void print();
};

void cube::init() {
	for (int i = 0; i < 6; ++i)
	for (int j = 0; j < 6; ++j) {
		color[i][j].clear();
		for (int k = 0; k < 3; ++k) color[i][j].push_back(pr[i]);
	}
}

void cube::rotate(int c, int a[4], int b) {
	for (int i = 3; i > 0; --i) {
		swap(color[c][a[i]], color[c][a[(i + 1) % 4]]);
		swap(color[a[i]][c], color[a[(i + 1) % 4]][c]);
		swap(color[a[i]][a[(i + 1) % 4]][b], color[a[(i + 1) % 4]][a[(i + 2) % 4]][b]);
		swap(color[a[(i + 1) % 4]][a[i]][2 - b], color[a[(i + 2) % 4]][a[(i + 1) % 4]][2 - b]);
	}
}

void cube::print() {
	cout << color[0][4] << '\n';
	cout << color[0][5][1] << 'w' << color[0][2][1] << '\n';
	reverse(color[0][1].begin(), color[0][1].end());
	cout << color[0][1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		cube c;
		c.init();
		while (t--) {
			string s;
			cin >> s;
			if (s[1] == '+') c.rotate(m[s[0]], side[(m[s[0]] + 3) % 6], 2);
			else c.rotate(m[s[0]], side[m[s[0]]], 0);
		}
		c.print();
	}
}
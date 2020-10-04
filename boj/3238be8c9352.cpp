#include <iostream>
using namespace std;

int p[100010];
long long d[100010];

int find(int i) {
	if (p[i] == i) return i;
	int next = find(p[i]);
	if (next != p[i]) {
		d[i] += d[p[i]];
	}
	return p[i] = next;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m, n || m) {
		for (int i = 1; i <= n; ++i) {
			p[i] = i;
			d[i] = 0;
		}

		char op;
		int a, b, w;
		while (m--) {
			cin >> op >> a >> b;
			int aa = find(a);
			int bb = find(b);
			if (op == '!') {
				cin >> w;
				if (aa != bb) {
					long long dif = d[a] - d[b] + w;
					if (dif >= 0) {
						p[bb] = aa;
						d[bb] = dif;
					}
					else {
						p[aa] = bb;
						d[aa] = -dif;
					}
				}
			}
			else {
				if (aa != bb) cout << "UNKNOWN\n";
				else {
					cout << d[b] - d[a] << '\n';
				}
			}
		}
	}
}
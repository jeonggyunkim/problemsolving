#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	p.resize(n + 1);
	int op, a, b;
	set<int> s;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		s.insert(i);
	}

	while (q--) {
		cin >> op >> a >> b;
		if (op == 1) {
			merge(a, b);
			a = *s.lower_bound(a);
			b = *s.lower_bound(b);
			merge(a, b);
		}
		else if (op == 2) {
			auto it = s.lower_bound(a);
			b = *s.lower_bound(b);
			while (*it < b) {
				auto jt = it;
				it++;
				merge(*it, b);
				s.erase(jt);
			}
		}
		else {
			a = *s.lower_bound(a);
			b = *s.lower_bound(b);
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
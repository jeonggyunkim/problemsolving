#include <iostream>
#include <queue>
using namespace std;

struct s{
	int a;
	s(int t) {a = t;};
};
bool operator<(s a, s b) {
	if (abs(a.a) != abs(b.a)) return abs(a.a) > abs(b.a);
	else return a.a > b.a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<s> pq;
	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		if (!t) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().a << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(s(t));
		}
	}
}
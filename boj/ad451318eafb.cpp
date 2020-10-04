#include <iostream>
#include <vector>
using namespace std;

int cnt, k;
vector<int> v;

void rec(int n) {
	if (n == 0) {
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < v.size(); ++i) {
				if (i) cout << '+';
				cout << v[i];
			}
		}
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		if (n >= i) {
			v.push_back(i);
			rec(n - i);
			v.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n >> k;
	rec(n);
	if (cnt < k) cout << -1;
}
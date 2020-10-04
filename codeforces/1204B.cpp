#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	long long mini = 0, maxi = 0;
	int p = 1;
	for (int i = 0; i < l; ++i) {
		mini += p;
		p *= 2;
	}
	for (int i = 0; i < n - l; ++i) mini += 1;

	p = 1;
	for (int i = 0; i < r; ++i) {
		maxi += p;
		p *= 2;
	}
	p /= 2;
	for (int i = 0; i < n - r; ++i) maxi += p;

	cout << mini << ' ' << maxi;
}
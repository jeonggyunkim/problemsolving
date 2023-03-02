#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, a, b;
	cin >> n >> b;
	if ((1LL << (b + 1)) - 1 >= n) cout << "yes";
	else cout << "no";
}
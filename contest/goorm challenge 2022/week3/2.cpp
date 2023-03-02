#include <iostream>
using namespace std;

string p[9] = {"1.,?!", "2ABC", "3DEF", "4GHI", "5JKL", "6MNO", "7PQRS", "8TUV", "9WXYZ"};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, con = 0;
	string s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i) {
		if (i == n - 1 || s[i] != s[i + 1]) {
			cout << p[s[i] - '1'][con % p[s[i] - '1'].size()];
			con = 0;
		}
		else con++;
	}
}
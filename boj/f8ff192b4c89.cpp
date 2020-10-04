#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string t;
	cin >> t;
	string u = t;
	reverse(t.begin(), t.end());
	if (t == u) cout << 1;
	else cout << 0;
}